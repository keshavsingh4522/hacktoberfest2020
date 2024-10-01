class UI {
  constructor() {
    this.uiContainer = document.getElementById("content");
    this.city;
    this.defaultCity = "Mumbai";
  }



  UIload(data) {
    //de-structure vars

    //add them to inner HTML
  
    this.uiContainer.innerHTML = `
        
        <div class="card mx-auto mt-5" style="width: 20rem;">
            <div class="card-body justify-content-center CONTENT">
                <h5>${data.name}</h5>
                <h6>Co-ordinates:</h6>
                <h6>Latitude: ${data.coord.lat}</h6> 
                <h6>Longitude: ${data.coord.lon} </h6>
                <h6>Maximum Temp(°C): ${data.main.temp_max}.</h6> 
                <h6>Minimum Temp(°C): ${data.main.temp_min}</h6>
                <h6 class="">Weather Forecast: ${data.weather[0].description}</h6> 

            </div>
        </div>
        
        <style>

          .CONTENT{
            background: ;
            box-shadow: 5px 5px 15px black;
          }

        </style>
        
        `;
  }

  clearUI() {
    uiContainer.innerHTML = "";
  }

  saveToLS(data) {
    localStorage.setItem("city", JSON.stringify(data));
  }

  getFromLS() {
    if (localStorage.getItem("city" == null)) {
      return this.defaultCity;
    } else {
      this.city = JSON.parse(localStorage.getItem("city"));
    }

    return this.city;
  }

  clearLS() {
    localStorage.clear();
  }
}