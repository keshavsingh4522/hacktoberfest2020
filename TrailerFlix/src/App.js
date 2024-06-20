import React, {useState, useEffect} from 'react'
import './App.css';
import Row from './Row';
import requests from './requests'
import Banner from './Banner';
import Nav from './Nav';
import tenor from './Images/tenor3.gif'

function App() {

  const [loading, setloading] = useState(false)

  useEffect(() => {
    setloading(true)
    setTimeout(() => {
      setloading(false)
    }, 2500);
  }, [])

  return (
    <div>
      {loading ? 
         <img src={tenor} style={{backgroundColor:"black" ,height:"100vh",width:"100%",position:"center", background: "center"}} alt="LOGO"/>
      :
      <div className="App">
        <Nav/>
        <Banner/>
        <Row title="NETFLIX ORIGINALS" 
        fetchUrl = {requests.fetchNetflixOriginals}
        isLargeRow={true}
        />
        <Row title="Trending Now" fetchUrl = {requests.fetchTrending}/>
        <Row title="Top Rated" fetchUrl = {requests.fetchTopRated}/>
        <Row title="Action Movies" fetchUrl = {requests.fetchActionMovies}/>
        <Row title="Comedy Movies" fetchUrl = {requests.fetchComedyMovies}/>
        <Row title="Horror Movies" fetchUrl = {requests.fetchHorrorMovies}/>
        <Row title="Romance Movies" fetchUrl = {requests.fetchRomanceMovies}/>
        <Row title="Documentaries" fetchUrl = {requests.fetchDocumentaries}/>
      </div>
      }
    </div>
  );
}

export default App;
