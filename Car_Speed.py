'''class Vehicle:
    def __init__(self, max_speed, mileage):
        self.max_speed = max_speed
        self.mileage = mileage

    car = Vehicle(521, 6)

print("The maxin speed is ",car.max_speed)'''

####################

'''class Vehicle:
    def __init__(self, max_speed, mileage):
        self.name = name
        self.max_speed = max_speed
        self.mileage = mileage

    def occupant_capacity(self,capacity):
        return f"The occupant capacity of {self.name} is {capacity} passengers"

class Car(Vehicle):
    def busSeating_capacity(self, capacity=60):
        super().busSeating_capacity(capacity)

car = Car("Volvo", 90, 60)

print("Vehile name: ", car.name)
print(car.busSeating_capacity(60))'''
