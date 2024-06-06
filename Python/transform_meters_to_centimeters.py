
# conversion in Python

# meter to centimeters
def meters_to_centimeters():
  meters = float (input ('enter the number in meters:'))
  cent = meters*100
  print ('the num in cent equals {}'.format(cent))
  
  # centimeters to millimeters
  def centimeters_to_millimeters():
    centimeters = float (input ('enter the number in centimeters:'))
    milli = centimeters*100
    print ('the num in millimeter equals {}'.format(milli))
  
  # centimeters to metters
  def centimeters_to_meters():
    centimeters = float (input ('enter the number in centimeters:'))
    metter = centimeters/100
    print ('the num in cent equals {}'.format(metter))
  
  # millimeters to meters
  def millimeters_to_meters():
    millimeters = float (input ('enter the number in millimeters:'))
    metter = millimeters/1000
    print ('the num in cent equals {}'.format(metter))
