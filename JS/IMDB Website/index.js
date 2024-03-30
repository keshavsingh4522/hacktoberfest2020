const main = document.getElementById("main");
const form = document.getElementById("form");
const search = document.getElementById("search");
const searchBtn = document.getElementById("Search-Btn");
const nextBtn=document.getElementById("next");
const prevBtn = document.getElementById("prev");
var i=1;

getMovies("popular");


async function getMovies(query) {
  try {
    const response = await fetch(
      "https://www.omdbapi.com/?apikey=a9af6e42&s=" + query,
      {
        method: "GET",
      }
    );

    const response_1 = await response.json();
    showMovies(response_1.Search);
    console.log(response_1.Search[0]);
  } catch (err) {
    console.error(err);
  }
}

function showMovies(data) {
  main.innerHTML = "";

  data.forEach((movie) => {
    let id = movie.imdbID;
    //   console.log(getMovies(id));
    const movieEl = document.createElement("div");
    movieEl.classList.add("movie");
    movieEl.innerHTML = `
            <img src="${movie.Poster}">
            <div class="movie-info">
                <h3>${movie.Title}</h3>
                <span class="year">${movie.Year}</span>
            </div>
           <button class="know-more" id="${id}" onclick="knowMore(id)">Get - Details</button>
        
        `;
    main.appendChild(movieEl);
  });
}

form.addEventListener("submit", (e) => {
  e.preventDefault();
  console.log(search);
  const searchText = search.value;
  console.log(searchText);
  if (searchText) {
    getMovies(searchText);
    nextBtn.style.display="block";
    if(i>1){
      prevBtn.style.display="block"
    }
  }
});

function knowMore(id){
    sessionStorage.setItem('MovieId',id);
    window.location='index2.html';
    return false;
}
nextBtn.onclick=function(){
  i++;
  getMovies(search.value+"&page="+i);
   if (i > 1) {
     prevBtn.style.display = "block";
   }
}

prevBtn.onclick = function () {
  i--;
  
  getMovies(search.value + "&page=" + i);
  if(i<=1){
    prevBtn.style.display="none"
  }
};




