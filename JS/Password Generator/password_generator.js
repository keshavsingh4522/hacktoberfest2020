"use strict";

const upperCase = ["A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"];
const lowerCase = ["a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"];
const numbers = ["0","1","2","3","4","5","6","7","8","9"];
const symbols = ["*","/",".","?","[]",";","@","!","$","#","^","%","&","+","-"];

function GeneratePassword() {        
    var characters = [];
    if (document.getElementById("include_symbols").checked)
        characters = characters.concat(upperCase, lowerCase, numbers, symbols);
    else
    characters = characters.concat(upperCase, lowerCase, numbers);

    var passwordLength = document.getElementById("password_length").value;
    var password = "";
    for (var i = 0; i < passwordLength; i++)
        password += characters[Math.floor(Math.random() * characters.length)];
    
    document.getElementById("password").innerHTML = "Your Password: " + password;
}