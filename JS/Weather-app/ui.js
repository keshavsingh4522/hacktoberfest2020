const dayName = document.querySelector('.date-dayname');
const currentDate = document.querySelector('.date-day');

const today = new Date();

let myDay = today.getDay();
let weekday = ['Sunday', 'Monday', 'Tuesday', 'Wednesday', 'Thursday', 'Friday', 'Saturday'];
dayName.innerText = weekday[myDay];

var dd = String(today.getDate()).padStart(2, '0');
var yyyy = today.getFullYear();
let monthName = ['Jan', 'Feb', 'Mar', 'Apr', 'May', 'Jun', 'Jul', 'Aug', 'Sep', 'Oct', 'Nov', 'Dec'];
var mm = monthName[today.getMonth()];
currentDate.innerText = `${dd} ${mm} ${yyyy}`;

// Modal 
const modal = document.querySelector('#myModal');
const modalBtn = document.querySelector('#locationBtn');
const closeBtn = document.querySelector('#close');

modalBtn.onclick = function () {
    modal.style.display = "block";
}
closeBtn.onclick = function () {
    modal.style.display = "none";
}
window.onclick = function (e) {
    if (e.target == modal) {
        modal.style.display = "none";
    }
}

class UI {
    constructor() {
        this.location = document.getElementById('w-location');
        this.desc = document.getElementById('w-desc');
        this.string = document.getElementById('w-temp');
        // this.details = document.getElementById('w-location');
        this.icon = document.getElementById('w-icon');
        this.humidity = document.getElementById('w-humidity');
        this.feelsLike = document.getElementById('w-feels-like');
        this.dewpoint = document.getElementById('w-dewpoint');
        this.wind = document.getElementById('w-wind');
    }

    paint(weather) {
        this.location.textContent = weather.name;
        this.desc.textContent = weather.weather[0].description;
        this.string.textContent = weather.main.temp + '°C';
        this.icon.setAttribute(
            'src',
            `http://openweathermap.org/img/wn/${weather.weather[0].icon}@2x.png`
        );
        this.humidity.textContent = weather.main.humidity; 
        this.dewpoint.textContent = weather.visibility; 
        this.wind.textContent = `${weather.wind.speed} m/s`; 
        this.feelsLike.textContent = weather.main.feels_like; 
    }
}