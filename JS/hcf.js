// program to find the HCF of two integers

let hcf;
// taking input from user
const num1 = prompt('Enter a positive integer: ');
const num2 = prompt('Enter another positive integer: ');

for (let i = 1; i <= num1 && i <= num2; i++) {
    if( num1 % i == 0 && num2 % i == 0) {
        hcf = i;
    }
}

// display the hcf
console.log(`HCF of ${num1} and ${num2} is ${hcf}. And Happy Hacktober!`);
