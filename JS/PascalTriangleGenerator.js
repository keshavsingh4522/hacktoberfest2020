function generatePascalTriangle(numRows) {
     if (!Number.isInteger(numRows) || numRows < 0) throw new Error();

     if (numRows === 0) return [];
     if (numRows === 1) return [[1]];

     let triangle = [];
     for (let row = 1; row <= numRows; row++) {
         let arr = [];
         for (let col = 0; col < row; col++) {
             if (col === 0 || col === row - 1) {
                 arr.push(1);
             } else {
                 arr.push((triangle[row-2][col-1] + triangle[row-2][col]));
             }
         }
         triangle.push(arr);
     }
     return triangle;
}

generatePascalTriangle(10).map(x => x.join(" ")).join("\n")