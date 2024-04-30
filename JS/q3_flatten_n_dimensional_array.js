/* Write a Program to Flatten a given n-dimensional array */

const flatten = (arr) => {
	// Write your code here
	try{
	const flat = arr.reduce((prev, next) => {
		if(Array.isArray(next)!=true)
		return prev.concat(next);
		else
		return prev.concat(flatten(next));
},[]);
	return(flat);
}
catch(err)
{
	return null;
}
};


/* For example,
INPUT - flatten([1, [2, 3], [[4], [5]])
OUTPUT - [ 1, 2, 3, 4, 5 ]

*/

module.exports = flatten;
