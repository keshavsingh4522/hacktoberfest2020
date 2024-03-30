const MytitleKey = sessionStorage.getItem("MovieId");

setMovieDetails(MytitleKey);

async function setMovieDetails(titleKey) {
  try {
    const response = await fetch(
      "https://www.omdbapi.com/?apikey=a9af6e42&i=" + titleKey,
      {
        method: "GET",
      }
    );

    const response_1 = await response.json();

    document.getElementById("movie-img").src = response_1.Poster;
    var allGenre = response_1.Genre.split(",");
    document.getElementById("Details-container").innerHTML = `
            <h2 id="movie-Name">${response_1.Title} </h2>
            
            <div id="time">
                <p>${response_1.Year + "  "} . ${
      "  " + timeIn12hr(response_1.Runtime.replace("min", "")) + "  "
    } . ${"  " + response_1.Type.toUpperCase()} </p>
            </div>
            <br>
            <div id="genres">
              <h4 class="movie-genre">${allGenre[0]}</h4>
              <h4 class="movie-genre">${allGenre[1]}</h4>
              <h4 class="movie-genre">${allGenre[2]}</h4>
            </div>
            <br><br><br>
            <p id="movie-summary">${response_1.Plot}</p>
            <br><hr>
            
            <div id="rating">
               <h5>IMDB RATINGS</h5>
               <img src="images/star2.png">
               <h3>${response_1.imdbRating}</h3><h4>/10</h4>
               <p>Rated by ${response_1.imdbVotes} peoples</p><br>
           </div>  <hr><br>
           <div id="Awards">
              <h5><strong>Awards Won</strong> : </h5>
              <p> ${ response_1.Awards}</p><br><br>
              <h5><strong>Metascore</strong> : </h5><p> ${ 
                response_1.Metascore
              }</p><br><br>
              <h5><strong>Box - Office Collection </strong> : </h5>
              <p>${ response_1.BoxOffice}</p><br><br>
              <h5><strong>Rated for </strong> : </h5>
              <p>${ response_1.Rated}</p>
           </div>      
    `;
    document.getElementById("castInfo").innerHTML = `
            <h1>Our Cast Informations</h1><br>
            
            <h2><strong>Directors </strong> : </h2><p>${response_1.Director}</p>
            <h2><strong>Produced By </strong> : </h2><p> ${response_1.Production}</p>
            <h2><strong>Writers </strong> : </h2><p>${response_1.Writer}</p>
            <h2><strong>Main Actors  </strong> :</h2><p> ${response_1.Actors}</p>
              
              
    `;
  } catch (err) {
    console.error(err);
  }
}

function timeIn12hr(MINUTES) {
  let m = MINUTES % 60;
  let h = (MINUTES - m) / 60;
  let HHMM = h.toString() + "h " + (m < 10 ? "0" : "") + m.toString() + "min";
  return HHMM;
}

