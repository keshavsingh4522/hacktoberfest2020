import numpy as np
import sys
import random

class Knapsack:

  def __init__(self, items, w, v, weight, pop_size):
    self.w = w
    self.v = v
    self.weight = weight
    self.col = items
    self.row = pop_size
    self.rand_pop = np.zeros((self.row, self.col))
    self.rand_popTemp = np.zeros((self.row, self.col))

  def display(self):
    print("The weights and values are: ")
    print("Weights: ", self.w)
    print("Values: ", self.v)
  
  def const_matrix(self):
    addZeros = np.zeros((self.row,6))
    self.rand_pop = np.append(self.rand_pop, addZeros, axis=1)
    #print(self.rand_pop)

  def gen_pop(self):
    self.rand_pop = np.random.randint(0,2,(self.row,self.col)) 
    self.rand_popTemp = np.random.randint(0,2,(self.row,self.col))
    #print(self.rand_pop)
    #rand_pop.shape
    self.const_matrix()

  def calc_fitness(self):
    for i in range(self.row):
        self.rand_pop[i,self.col+2] = self.rand_pop[i,self.col+1]/np.average(self.rand_pop[:,self.col+1])
        self.rand_pop[i,self.col+3] = round(self.rand_pop[i,self.col+2])
  
  def roulette_wheel(self):
    sumf = sum(self.rand_pop[:,self.col+1:self.col+2])
    if sumf == 0:
      print("\nDivide by zero error")
      sys.exit()
  
    self.rand_pop[:,self.col+2] = np.round(self.rand_pop[:,self.col+1]/sumf,2)
    self.rand_pop[0,self.col+3] = self.rand_pop[0,self.col+2]

    for i in range(self.row-1):
      self.rand_pop[i+1,self.col+3] = self.rand_pop[i,self.col+3] + self.rand_pop[i+1,self.col+2]
      self.rand_pop[i,self.col+4] = np.round(random.random(),2)

    self.rand_pop[self.row-1,self.col+4] = np.round(random.random(),2)    
      
    #print("\nThe intermediate calculations: \n",self.rand_pop[:,0:self.col+6])

    for i in range(self.row):
      arrayOfTrue = self.rand_pop[:,self.col+3] > self.rand_pop[i,self.col+4]
      if np.where(arrayOfTrue == True)[0].size > 0:
        itemindex = np.where(arrayOfTrue == True)[0][0]
        self.rand_popTemp[i] = self.rand_pop[itemindex,0:self.col]
        self.rand_pop[:,0:self.col] = self.rand_popTemp

    print("\nNext generation: \n",self.rand_pop[:,0:self.col])
  
  def knapsack(self):
    maxVal = 0
    capIndividual = []
    for itr in range(10):
      print("\nIteration no:",itr+1)

      for i in range(self.row):
        sumWeight = sum(np.multiply(self.w, self.rand_pop[i,0:self.col]))
        self.rand_pop[i,self.col] = sumWeight
        sumValue = sum(np.multiply(self.v, self.rand_pop[i,0:self.col]))

        if sumWeight > self.weight:
            sumValue = 0
            self.rand_pop[i,self.col+1] = sumValue
            continue
        
        self.rand_pop[i,self.col+1] = sumValue
        
        if maxVal < sumValue:
            maxVal = sumValue
            capIndividual = self.rand_pop[i,0:self.col]
        
      self.roulette_wheel()

w = [20, 10, 5, 32, 11, 25, 16, 19, 25, 23]
v = [200, 30, 200, 50, 156, 100, 30, 300, 25, 10]
knap_object = Knapsack(items = 10, w = w, v = v, weight = 100, pop_size = 50)
knap_object.display()
knap_object.gen_pop()
knap_object.knapsack()