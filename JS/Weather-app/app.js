// Init storage
const storage = new Storage();
// Get stored location data
const weatherLocation = storage.getLocationDate();

// Init weather object
const weather = new Weather(weatherLocation.city, weatherLocation.country);
// Init UI
const ui = new UI();

// Get weather on DOM load
document.addEventListener('DOMContentLoaded',getWeather)

function getWeather() {
    weather.getWeather()
        .then(results => ui.paint(results))
        .catch(err => console.log(err));
}

// Change location event
document.getElementById('w-change-btn').addEventListener('click',(e) => {
    const city = document.getElementById('city').value;
    const country = document.getElementById('country').value;

    weather.changeLocation(city, country);

    // LS
    storage.setLocationData(city,country);

    getWeather();

    modal.style.display = "none";
});