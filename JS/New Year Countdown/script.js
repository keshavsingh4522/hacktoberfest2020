var countdowndate = new Date("January 1, 2022 00:00:00").getTime();

//document.getElementById("demo").innerHTML =countdowndate;
setInterval(function(){
  var now = new Date().getTime();
  var diff = countdowndate-now;
  
  var days = Math.floor(diff / (1000 * 60 * 60 * 24));
  var hours = Math.floor((diff% (1000 * 60 * 60 * 24)) / (1000 * 60 * 60));
  var minutes = Math.floor((diff % (1000 * 60 * 60)) / (1000 * 60));
  var seconds = Math.floor((diff % (1000 * 60)) / 1000);
  
  document.getElementById("day1").innerHTML = Math.floor(days/10);
  document.getElementById("day2").innerHTML =days%10;
  document.getElementById("hour1").innerHTML = Math.floor(hours/10);
  document.getElementById("hour2").innerHTML =hours%10;
  document.getElementById("min1").innerHTML = Math.floor(minutes/10);
  document.getElementById("min2").innerHTML =minutes%10;
  document.getElementById("sec1").innerHTML = Math.floor(seconds/10);
  document.getElementById("sec2").innerHTML =seconds%10;
  
}, 1000);