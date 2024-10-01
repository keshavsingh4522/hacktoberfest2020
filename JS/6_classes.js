class Book {
  constructor(title, author, year) {
    this.title = title;
    this.author = author;
    this.year = year;
  }

  getSummary() {
    return `The ${this.title} was written by ${this.author} in ${this.year} `;
  }
}

//Instantiate object

const book1 = new Book("Tokyo revengers", "Ken wakui", "2021");

console.log(book1);
