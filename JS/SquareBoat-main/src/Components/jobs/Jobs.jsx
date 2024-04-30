import React, { useEffect, useState } from "react";
import axios from "axios";
import Cards from "../cards/Cards";
import Grid from "@mui/material/Grid";
import Box from "@mui/material/Box";
import Typography from "@mui/material/Typography";
import HomeIcon from "@mui/icons-material/Home";
import { Link } from "react-router-dom";
import "./Jobs.css";

function Jobs() {
  const [data, setdata] = useState([]);
  useEffect(() => {
    axios
      .get(`https://jobs-api.squareboat.info/api/v1/recruiters/jobs`, {
        headers: {
          Authorization: localStorage.getItem("token"),
        },
      })
      .then((res) => setdata(res.data.data.data));
  }, []);
  console.log(data);
  return data.length === 0 ? (
    <div>No jobs posted by you</div>
  ) : (
    <div className="container mt-2">
      <div className="homie">
        <HomeIcon />
        <Link to="/" className="hom">
          Home
        </Link>
      </div>
      <Typography variant="h6" gutterBottom component="div" className="posted">
        Jobs posted by you
      </Typography>
      <div className="row">
        {data.map((item) => (
          <Box sx={{ flexGrow: 1 }}>
            <Grid container spacing={2} className="grids">
              <Cards
                key={item.id}
                id={item.id}
                title={item.title}
                description={item.description}
                location={item.location}
              />
            </Grid>
          </Box>
        ))}
      </div>
    </div>
  );
}

export default Jobs;
