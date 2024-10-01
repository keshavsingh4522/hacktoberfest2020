function Book(title, anime, genre, author, releaseYear) {
  this.title = title;
  this.anime = anime;
  this.genre = genre;
  this.author = author;
  this.releaseYear = releaseYear;
  this.Summary = function () {
    return `The ${this.title} is a ${this.anime} about delenquents and its genre is ${this.genre}. This book is authored by ${this.author} and its release year is ${this.releaseYear}.`;
  };
}

//Instatiate an object
const book1 = new Book("Tokyo Rvengers", "anime", "shonen", "ken wakui", 2021);
console.log(book1);
console.log(book1.Summary());
