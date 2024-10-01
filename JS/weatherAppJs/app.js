// Catching DOM
const API_key = "9b18029f3953756825124dfb264b64a2";
const mainContainer = document.querySelector("#data");
const input = document.querySelector("#location");
const btn = document.querySelector("#btn");

// btn event listener
btn.addEventListener("click", (e) => {
  e.preventDefault();
  async function asyncCall() {
    try {
      const fetchingData = await fetch(
        `https://api.openweathermap.org/data/2.5/weather?q=${input.value}&appid=${API_key}`
      );
      const data = await fetchingData.json();
      mainContainer.innerHTML = `
      <div id="weather-info">
      <h1 id="temp">${convertToCelcius(data.main.temp)}<span>&deg;</span>C</h1>
      <h2>${data.name}, ${
        data.sys.country
      } <sup><img src="http://openweathermap.org/images/flags/${data.sys.country.toLowerCase()}.png" alt=""></sup></h2>
      <div class="w-info">
        <img src="http://openweathermap.org/img/wn/${
          data.weather[0].icon
        }@2x.png" alt="" />
        <h3>${data.weather[0].description}</h3>
      </div>
      <div id="other-info">
        <div class="info-card">
          <div class="icon">
            <i class="fas fa-temperature-low"></i>
          </div>
          <p>${data.main.humidity}%</p>
          <h2>Humidity</h2>
        </div>
        <div class="info-card">
          <div class="icon">
            <i class="fas fa-wind"></i>
          </div>
          <p>${data.wind.speed}mps</p>
          <h2>Wind</h2>
        </div>
        <div class="info-card">
          <div class="icon">
            <i class="fas fa-tachometer-alt"></i>
          </div>
          <p>${data.main.pressure}</p>
          <h2>Air pressure</h2>
        </div>
      </div>
    </div>
      `;
    } catch (err) {
      alert("Sorry! Failed to load");
    }
  }
  asyncCall();
});
function convertToCelcius(data) {
  return Math.round(data - 273.15);
}
