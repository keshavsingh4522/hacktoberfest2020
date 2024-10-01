const s1 = "Hello";
console.log(s1.toUpperCase());
console.log(typeof s1); // string

const s2 = new String("Hello");
console.log(typeof s2); //object

//Object literal
const book1 = {
  id: 1,
  title: "Tokyo revengers",
  type: "anime",
  genre: "shonen",
  author: "Ken Wakui",
  getSummary: function () {
    return `The ${book1.title}
     is a ${book1.type}
      about delenquents and its genre is
       ${book1.genre}. This book is authored
        by ${book1.author} and its release year is
         ${book1.releaseYear}.`;
  },
  releaseYear: 2021,
};

console.log(book1.getSummary());
