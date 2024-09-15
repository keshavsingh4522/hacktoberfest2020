// Program to find the area of a triangle from the length of sides given.

// Mathematical Formula - (s(s - a)(s - b)(s - c))**(1/2)
// where 's' is semi perimeter - (a + b + c)/2


// Program
// Import the Math Library to use the pow function
import 'dart:math';

// Define a Function to find the Area.
double area(double a, double b, double c) {
  
  // Find 's'
  double s = (a + b + c)/2;
  
  //Find the Area
  double area = pow((s*(s - a)*(s - b)*(s - c)),(1/2)).toDouble();
  
  // Return the Area.
  return area;
}

void main() {
  
  // Test the Function
  print(area(3, 4, 5));  //6
}
