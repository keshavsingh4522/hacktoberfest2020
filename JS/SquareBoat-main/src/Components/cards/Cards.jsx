import React, { useState } from "react";
import Card from "@mui/material/Card";
import CardContent from "@mui/material/CardContent";
import Typography from "@mui/material/Typography";
import { Button, CardActionArea, CardActions } from "@mui/material";
import Box from "@mui/material/Box";
import Modal from "@mui/material/Modal";
import axios from "axios";
import Avatar from "@mui/material/Avatar";
import LocationOnOutlinedIcon from "@mui/icons-material/LocationOnOutlined";
import Paper from "@mui/material/Paper";
import "./Cards.css";

function Cards(props) {
  const [open, setOpen] = React.useState(false);
  const [data, setdata] = useState([]);
  const handleOpen = (id) => {
    setOpen(true);
    console.log(data);
    axios
      .get(
        `https://jobs-api.squareboat.info/api/v1/recruiters/jobs/${id}/candidates`,
        {
          headers: {
            Authorization: localStorage.getItem("token"),
          },
        }
      )
      .then((res) => {
        console.log(res.data);
        setdata(res.data.data);
      })
      .catch((err) => console.log(err));
  };

  const handleClose = () => setOpen(false);
  return (
    <div>
      <Card sx={{ maxWidth: 345 }} className="cards">
        <CardActionArea>
          <CardContent>
            <Typography gutterBottom variant="h5" component="div">
              {props.title}
            </Typography>
            <Typography variant="body2" color="text.secondary">
              {props.description}
            </Typography>
          </CardContent>
        </CardActionArea>

        <CardActions>
          <LocationOnOutlinedIcon />
          {props.location}
          <Button
            size="small"
            color="primary"
            onClick={() => handleOpen(props.id)}
            className="apply"
          >
            Apply
          </Button>
        </CardActions>
      </Card>
      <Modal
        open={open}
        onClose={handleClose}
        aria-labelledby="modal-modal-title"
        aria-describedby="modal-modal-description"
        className="scrollable"
      >
        <Box>
          <div className="header">
            <Typography id="modal-modal-title" variant="h6" component="h2">
              Applicants for this job
            </Typography>
          </div>
          <Paper elevation={3} className="paper">
            <div className="now">
              {data.map((item) => (
                <Card sx={{ minWidth: 275 }} className="applicants">
                  <CardContent>
                    <Avatar>{item.name[0]}</Avatar>
                    <Typography
                      sx={{ fontSize: 14 }}
                      color="text.secondary"
                      gutterBottom
                    >
                      {item.name}
                    </Typography>
                    <Typography sx={{ mb: 1.5 }} color="text.secondary">
                      {item.email}
                    </Typography>
                    <Typography variant="body2">
                      Skills
                      <br />
                      {item.skills}
                    </Typography>
                  </CardContent>
                </Card>
              ))}
            </div>
          </Paper>
        </Box>
      </Modal>
    </div>
  );
}

export default Cards;
