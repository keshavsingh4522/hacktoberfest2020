//Object of protos

const bookProtos = {
  Summary: function () {
    return `The ${this.title} was written by ${this.author} in ${this.releaseYear} `;
  },
  getAge: function () {
    const yearsOld = new Date().getFullYear() - this.releaseYear;
    return `${this.title} is ${yearsOld} years old`;
  },
};

//create object

const book1 = Object.create(bookProtos);

book1.title = "Tokyo revengers";
book1.author = "Ken wakui";
book1.releaseYear = "2021";

console.log(book1);
