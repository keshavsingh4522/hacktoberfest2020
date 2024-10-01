import java.io.*;  
import java.util.*;  
public class FrugalNumberExample  
{  
//function checks if the number is frugal or not  
static boolean frugal(long n)  
{  
ArrayList<Long> arr = primes(n);  
long t = n;  
//determines number of digits in prime factorization of the number  
long s = 0;  
for (int i = 0; i < arr.size(); i++)  
{  
if (t % arr.get(i) == 0)  
{  
//exponent for current factor  
long k = 0;  
//loop counts the number of times the prime factor divides  
//i.e. determines exponent  
while (t % arr.get(i) == 0)  
{  
t = t / arr.get(i);  
k++;  
}  
//determines the number of digits in the exponent avoiding exponents of value 1  
if (k == 1)  
s = s + countDigits(arr.get(i));  
else if (k != 1)  
s = s + countDigits(arr.get(i)) + countDigits(k);         
}  
}  
//the given number will be frugal number if the condition returns true  
return (countDigits(n) > s && s != 0);  
}      
//function that finds primes up to given numbers  
static ArrayList<Long> primes(long n)  
{  
//creates a boolean array for primes      
boolean []prime = new boolean[(int)n + 1];  
for(int i = 0; i < n + 1; i++)  
prime[i] = true;  
//determines prime by using the Sieve of Eratosthenes method  
for (int i = 2; i * i <= n; i++)  
{  
//if prime[i] is true then it is prime  
if (prime[i] == true)  
{  
//finds multiples of p  
for (int j = i * 2; j <= n; j += i)  
prime[j] = false;  
}  
}  
//creates an array of prime numbers  
ArrayList<Long> array = new ArrayList<Long>();  
for (int i = 2; i < n; i++)  
//returns true if i is prime  
if (prime[i])  
//adding elements to the array  
array.add((long)i);  
//returns an array of prime numbers  
return array;  
}  
//function counts the number of digits in n  
static int countDigits(long n)  
{  
long temp = n;  
int count = 0;  
while (temp != 0)  
{  
//divides the number by 10      
temp = temp / 10;  
//increments the variable c by 1  
count++;  
}  
//returns the number of digits  
return count;  
}  
//driver code  
public static void main(String args[])  
{  
Scanner sc = new Scanner(System.in);  
System.out.print("Enter the number to check: ");  
long num = sc.nextLong();  
//function calling  
if (frugal(num))  
System.out.println("It is a frugal number.");  
else  
System.out.println("It is not a frugal number.");  
}  
}  
