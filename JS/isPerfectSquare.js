function isPerfectSquare(num) {
   if(Number.isInteger(Math.sqrt(num))){
      return ('Yes '+num+' is a perfect square of '+Math.sqrt(num))
   }else{
      return ('No '+num+' is not a perfect square.')
   }
}

console.log(isPerfectSquare(9))
console.log(isPerfectSquare(12))
console.log(isPerfectSquare(15))
