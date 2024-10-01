
function stone(){
    let a=getRandomArbitrary(0,3);
    console.log(a);
    if(a==0){
        alert("It's a stone,draw!!!");
    }
    if(a==1){
        alert("It's paper,you lose!!!");
    }
    if(a==2){
        alert("It's a scissor,you win!!!");
    }
}
function paper(){
    let a=getRandomArbitrary(0,3);
    if(a==0){
        alert("It's a stone,you win!!!");
    }
    if(a==1){
        alert("It's paper,you draw!!");
    }
    if(a==2){
        alert("It's a scissor,you lose!!!");
    }
}
function scissor(){
    let a=getRandomArbitrary(0,3);
    if(a==0){
        alert("It's a stone,you lose!!!");
    }
    if(a==1){
        alert("It's paper,you win!!!");
    }
    if(a==2){
        alert("It's a scissor,draw!!!");
    }
}

function getRandomArbitrary(min, max) {
  return Math.floor((Math.random() * (max - min) + min));
}
