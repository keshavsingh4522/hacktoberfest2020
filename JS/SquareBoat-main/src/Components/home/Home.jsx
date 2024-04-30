import React from "react";
import { Typography } from "@mui/material";
import Button from "@mui/material/Button";
import "./Home.css";
function Home() {
  return (
    <div>
      <Typography variant="h3" gutterBottom component="div" className="home">
        Welcome to <br />
        <b>
          MY<span className="job">JOBS</span>
        </b>
      </Typography>
      <Button variant="contained" className="start">
        Get Started
      </Button>
      <img
        src="/Screenshot 2020-09-21 at 2.06.52 PM@2x.png"
        alt="home"
        className="image"
      />
      <Typography variant="h5" gutterBottom component="div">
        Why Us
      </Typography>
    </div>
  );
}

export default Home;
