let interval;
let msec = 0;
let sec = 0;
let min = 0 ;

// Getting elements
let msecText = document.getElementById("msec");
let secText = document.getElementById("sec");
let minText = document.getElementById("min");

let i = 1;

// counter
const timer = () => {
    msec++;

    msecText.innerHTML = msec;
    
    if (msec >= 100) {
        sec++;
        secText.innerHTML = sec;
        msec = 0;
        msecText.innerHTML = 0;
    } else if (sec >= 60) {
        min++;
        minText.innerHTML = min;
        sec = 0;
        msecText.innerHTML = 0;
    }

}

// For starting the timer
const start = () => {
    interval = setInterval(timer, 10);

    document.getElementById('pause').disabled = false;
    document.getElementById('reset').disabled = false;
    document.getElementById('save').disabled = false;
    document.getElementById('start').disabled = true;

}

// For pausing the timer
const pause = () => {
    clearInterval(interval);

    document.getElementById('pause').disabled = true;
    document.getElementById('start').disabled = false;
}

// Reseting Timer
const reset = () => {
    clearInterval(interval);

    msecText.innerHTML = 0;
    secText.innerHTML = 0;
    minText.innerHTML = 0;

    document.getElementById('pause').disabled = true;
    document.getElementById('reset').disabled = true;
    document.getElementById('save').disabled = true;
    document.getElementById('start').disabled = false;
}

// Saving a time and list down below
const save = () => {
    let data =  "<tr>"+
    "<td>"+ i +"</td>"+
    "<td>"+ min +":"+ sec +":"+ msec +"</td>";
    i++;
    $('tbody').append(data);
}
