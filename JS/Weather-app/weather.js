class Weather {
    constructor(city, country) {
        this.apiKey = '128c3ba5fd3044c64c74b30476cd3f37';
        this.city = city;
        this.country = country;
    }

    async getWeather() {
        const response = await fetch(`https://api.openweathermap.org/data/2.5/weather?q=${this.city},${this.country}&APPID=${this.apiKey}&units=metric`);
        const responseDate = await response.json();
        return responseDate;
    }

    changeLocation(city, country) {
        this.city = city;
        this.country = country;
    }
}