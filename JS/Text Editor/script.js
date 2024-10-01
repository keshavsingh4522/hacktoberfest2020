
function updateText(){
    let text = document.getElementById('text-input').value;
    document.getElementById('text-output').innerText = text;
}

function makeBold(element){
    element.classList.toggle('active');
    document.getElementById('text-output').classList.toggle('bold');
}

function makeItalic(element){
    element.classList.toggle('active');
    document.getElementById('text-output').classList.toggle('italic');
}

function makeUnderline(element){
    element.classList.toggle('active');
    document.getElementById('text-output').classList.toggle('underline');
}

function alignText(element, alignType){
    document.getElementById('text-output').style.textAlign = alignType;
    let buttonList = document.getElementsByClassName('btn');
    for(let i=0;i<buttonList.length;i++){
        buttonList[i].classList.remove('active');
    }
    element.classList.add('active');
}