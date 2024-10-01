// to get random moles to show
let chooseMole = (choosen) => {
    let molesIndex = [0,1,2,3,4,5]
    molesIndex = molesIndex.filter(e => !choosen.includes(e))
    let numberOfMole = 1+Math.floor(Math.random()*molesIndex.length)
    while (molesIndex.length > numberOfMole) {
        let idx = Math.floor(Math.random()*molesIndex.length);
        molesIndex.splice(idx,1)
    }
    return molesIndex
}



let kotaks = document.getElementsByClassName("kotak")   
// moles appear-disappear interval
// let availableIdx = [1,1,1,1,1,1]
let idxs = chooseMole([])
let moleInterval;

// start
const start = document.querySelector(".start p")
start.addEventListener("click",() => {
    start.parentElement.classList.add("down")
    setTimeout(() => start.parentElement.style.display = "none", 500)
    moleInterval = setInterval(() => {
        // console.log(idxs);
        for (let i = 0; i < kotaks.length; i++){
            kotaks[i].style.backgroundImage = "none"
            kotaks[i].style.cursor = "auto"
        }
        idxs.forEach((i) => {
            /*if(availableIdx[i])*/kotaks[i].style.backgroundImage = "url(\"img/mole.png\")"
            kotaks[i].style.cursor = "pointer"
        })
        idxs = chooseMole(idxs)
    },1000)
})
    // if the moles got clicked
    document.querySelectorAll(".kotak").forEach((e,idx) => {
        e.addEventListener("click" ,() => {
            if(e.style.backgroundImage == "url(\"img/mole.png\")") {
                document.getElementById("score").children[0].innerHTML = parseInt(document.getElementById("score").children[0].innerHTML) + 1 ;
                e.style.border = "red solid 2px"
                setTimeout(() => e.style.border = "none", 30)
                e.style.backgroundImage = "none"
                // availableIdx[idx] = 0
            }
        })
    })
    
    // reset
    document.getElementById("reset").addEventListener("click",() => location.reload()   )