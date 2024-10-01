
# Define an object class named Dog
class Dog:
        def __init__(self, breed, name, weight, age):
        # Define Data Fields for breed, name, weight, and age
                self.breed = breed
        
                self.name = name
        
                self.weight = weight
        
                self.age = age

        # Define getters for breed, name, weight, and age
        def getBreed(self):
                return self.breed
        
        def getName(self):
                return self.name
        
        def getWeight(self):
                return self.weight
        
        def getAge(self):
                return self.age
        
        # Define setters for breed, name, weight, and age
        def setBreed(self, breed):
                self.breed = breed
        
        def setName(self, name):
                self.name = name
        
        def setWeight(self, weight):
                self.weight = weight
        
        def setAge(self, age):
                self.age = age