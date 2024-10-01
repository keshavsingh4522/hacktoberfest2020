function Book(title, author, releaseYear) {
  this.title = title;
  this.author = author;
  this.releaseYear = releaseYear;
}

//for prototypes we can do this
//we can achieve same thing by doing this prototype method.
Book.prototype.Summary = function () {
  return `The ${this.title} was written by ${this.author} in ${this.releaseYear} `;
};

function Magzine(title, author, releaseYear, month) {
  Book.call(this, title, author, releaseYear);
  this.month = month;
}

//Inherit Prototype
Magzine.prototype = Object.create(Book.prototype);

//Instantitate Magzine object
const mag1 = new Magzine("Magzine one", "Akash", "2018", "feb");

//Use Magzine constructor
Magzine.prototype.constructor = Magzine;

console.log(mag1.Summary()); //will throw type error  mag1.Summary is not a function
