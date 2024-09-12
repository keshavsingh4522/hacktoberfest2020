const express = require("express");
const bodyPARSER= require("body-parser");
const app= express();
const https= require("https");
/// https is used to get data from a external sserver



app.use(bodyPARSER.urlencoded({extended:true}));


app.get("/",  function(req,res){

  res.sendFile(__dirname + "/index.html");

});


   app.post("/", function(req,res){

              const cname= req.body.cityname;
              const country= req.body.countryname;


       const url="https://api.openweathermap.org/data/2.5/weather?q="+ cname+","+ country +"&units=metric&appid=435a6d9426567380086e2c86a104fb87";
    https.get(url, function(response){


 ////to display

              response.on("data", function(data){

                       const weatherDATA=  JSON.parse(data);

///  to acess individual elements
//weatherDATA.main.temp; like objects

                       //console.log(weatherDATA);
//
                       const temp= weatherDATA.main.temp;
                      const lat=  weatherDATA.coord.lat;

                     const lon=  weatherDATA.coord.lon;

                       const des= weatherDATA.weather[0].description;

                       const pic= weatherDATA.weather[0].icon;



                      res.write("<h1>TEMPerature in"+  cname+","+ country +" is "+ temp+"degree Celcius</h1>");
                      res.write("<p>latttitude"+lat+  "longitude"+lon+ "</p>");
                      res.write("<h1>WEATHER HERE IS ...>>"+des+"</h1>");

                              const  imgURL=  "http://openweathermap.org/img/wn/"+  pic   +"@2x.png"  ;
                             res.write("<img  src=" +imgURL +">");
                       res.send();
// weather[0]  as its an array with only one element.....

                  });
         });
});

////NOTE.... we can have only one res.send()  in a app.get()////
/// to send more than one data we need to create more app.get
//orrrrrrrrr we use  res.write()  many times to print what we need  and at end res.send() only once////




///// lisening line created in starting placed at end

app.listen(3000, function(){console.log("SERVER RUNNING AT  PORT 3000")  });
