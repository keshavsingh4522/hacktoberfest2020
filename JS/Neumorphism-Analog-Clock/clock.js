function clock() {
    const deg = 6;
    const hr = document.querySelector('#hr');
    const mn = document.querySelector('#mn');
    const sc = document.querySelector('#sc');

    const day = new Date();
    const hh = day.getHours() * 30;
    const mm = day.getMinutes() * deg;
    const ss = day.getSeconds() * deg;

    hr.style.transform = `rotateZ(${(hh) + (mm / 12)}deg)`;
    mn.style.transform = `rotateZ(${mm}deg)`;
    sc.style.transform = `rotateZ(${ss}deg)`;
}

setInterval(() => clock(), 1000);

var toggle_action = document.getElementById('toggle-btn');

toggle_action.onclick = function toggle() {
    const clock = document.getElementById('container-clock');
    clock.classList.toggle('light');
}
