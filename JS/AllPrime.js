let args = process.argv;
let n = parseInt(args[2])

for (let i = 1; i <= n; i++){
    
    if(isPrime(i)) {
        console.log(i);
    }
}

function isPrime(num) {
    let prime = true
    for (let div = 2; div * div <= num; div++) {
       if (num % div === 0) {
           prime = false;
           break;
       } else {
           prime = true;
       }
    }
    return prime;
}
