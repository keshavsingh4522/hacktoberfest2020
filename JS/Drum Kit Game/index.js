// Detecting Button Press
var numberOfDrums = document.querySelectorAll(".drum").length;

for(var i=0; i<numberOfDrums; i++){
    document.querySelectorAll(".drum")[i].addEventListener("click",function(){
        var nameOfElement = this.innerHTML;

        makeSound(nameOfElement);

        buttonAnimation(nameOfElement);

    });
    
}

// Detecting Keyboard Press

document.addEventListener("keypress",function(event){

   makeSound(event.key);

   buttonAnimation(event.key);

});


function makeSound(key){

    switch(key){
        case "d":
            var tom1 = new Audio("sounds/tom-1.mp3");
            tom1.play();    
            break;
        case "i":
            var tom2 = new Audio("sounds/tom-2.mp3");
            tom2.play();    
            break;
        case "s":
            var tom3 = new Audio("sounds/tom-3.mp3");
            tom3.play();    
            break;
        case "h":
            var tom4 = new Audio("sounds/tom-4.mp3");
            tom4.play();    
            break;
        case "a":
            var snare = new Audio("sounds/snare.mp3");
            snare.play();    
            break;
        case "n":
            var crash = new Audio("sounds/crash.mp3");
            crash.play();    
            break;
        case "t":
            var kick = new Audio("sounds/kick-bass.mp3");
            kick.play();    
            break;
        
        default:
            console.log(innerHTML);
    }
}


function buttonAnimation(currentkey) {

    var activebutton = document.querySelector("." + currentkey);

    activebutton.classList.add("pressed");
    
    setTimeout(function(){
        activebutton.classList.remove("pressed");
    }, 100);

}