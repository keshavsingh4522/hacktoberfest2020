import React from "react";
import Card from "@mui/material/Card";
import CardContent from "@mui/material/CardContent";
import Typography from "@mui/material/Typography";
import { CardActionArea } from "@mui/material";

function Articles(props) {
  return (
    <Card sx={{ maxWidth: 345 }} className="cards">
      <CardActionArea>
        <CardContent>
          <Typography gutterBottom variant="h5" component="div">
            {props.name}
          </Typography>
          <Typography variant="body2" color="text.secondary">
            {props.author}
            {props.category}
          </Typography>
        </CardContent>
      </CardActionArea>
    </Card>
  );
}

export default Articles;
