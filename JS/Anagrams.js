var first = "Cat";
var second = "Act";

isAnagram(first, second); 

function isAnagram(first, second) 
{
  var first1 = first.toLowerCase();
  var second2 = second.toLowerCase();
  first1 = first1.split("").sort().join("");
  second2 = second2.split("").sort().join("");
  return first1 === second2;
}
