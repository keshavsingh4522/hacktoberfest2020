function Book(title, anime, genre, author, releaseYear) {
  this.title = title;
  this.anime = anime;
  this.genre = genre;
  this.author = author;
  this.releaseYear = releaseYear;
  // this.Summary = function () {
  //   return `The ${this.title} is a ${this.anime} about delenquents and its genre is ${this.genre}. This book is authored by ${this.author} and its release year is ${this.releaseYear}.`;
  // };
}

//for prototypes we can do this
//we can achieve same thing by doing this prototype method.
Book.prototype.Summary = function () {
  return `The ${this.title} is a ${this.anime} about delenquents and its genre is ${this.genre}. This book is authored by ${this.author} and its release year is ${this.releaseYear}.`;
};

//let's create one new prototupe

Book.prototype.getAge = function () {
  const yearsOld = new Date().getFullYear() - this.releaseYear;
  return `${this.title} is ${yearsOld} years old`;
};

Book.prototype.revise = function (newYear) {
  this.releaseYear = newYear;
  this.revised = true;
};

//Instantiate an object
const book1 = new Book("Tokyo Rvengers", "anime", "shonen", "ken wakui", 2019);
console.log(book1);
console.log(book1.Summary()); //The Tokyo Rvengers is a anime about delenquents and its genre is shonen. This book is authored by ken wakui and its release year is 2019.
console.log(book1.getAge()); // Tokyo Rvengers is 2 years old

console.log(book1);
book1.revise(2021);
console.log(book1);
