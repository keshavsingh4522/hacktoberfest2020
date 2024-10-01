class Fetch {
  async getCurrent(input) {
    const Key = "295cf32709ad96540975e65b535c536c";

    //make request to url

    const response = await fetch(
      `https://api.openweathermap.org/data/2.5/weather?q=${input}&appid=${Key}&units=metric`
    );


    const data = await response.json();
     
    console.log(data);

    return data;
  }
}

