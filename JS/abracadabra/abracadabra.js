// Arranges a word in triangle shape

const prompt = require('prompt-sync')()

function abracadabra(baseWord) {

    let cont = 0

    while(cont <= baseWord.length) {

        let formattedWord = baseWord.substr(0, (baseWord.length - cont))
        console.log(' '.repeat(cont) + formattedWord.split('').join(' '));

        cont++
    }
}

const checkSpace = (string) => string.indexOf(' ') >= 0;

let testCases = prompt('How many tests do you want to do: ')

if(typeof testCases++ != 'number') 
    console.log('Enter a quantity in number for testing')

for(let i = 1; i < testCases; i++) {
    
    const word = prompt('Type a word: ')
    
    if(word.length > 100 || word.length < 2 || checkSpace(word))
        console.log('The message must be from 2 to 100 characters and no spaces!')
    else
        abracadabra(word.toUpperCase())
}