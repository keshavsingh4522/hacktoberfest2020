const balancedParentheses = (x) => {
 const opening = []
 const closing = []
 x.split('').forEach(x => {
  if ('({['.includes(x)) opening.push(x);
  if (')}]'.includes(x)) closing.push(x);
 })
 if (opening.length === 0 ||
  closing.length === 0 ||
  opening.length !== closing.length) return false

 opening.forEach((x, i) => {
  if (x !== closing[i]) return false
 })
 console.log(opening)
 console.log(closing)
 return true
}