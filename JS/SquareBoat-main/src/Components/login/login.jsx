import React, { useState } from "react";
import axios from "axios";
import { useHistory } from "react-router-dom";
import Button from "@mui/material/Button";
import TextField from "@mui/material/TextField";
import { Link } from "react-router-dom";
import Typography from "@mui/material/Typography";
import "./login.css";

function Login(props) {
  const [username, setusername] = useState("");
  const [password, setpassword] = useState("");
  const [error, seterror] = useState(false);
  let history = useHistory();
  function success() {
    props.suckcess();
  }
  async function login() {
    try {
      seterror(false);
      const res = await axios.post(
        `https://jobs-api.squareboat.info/api/v1/auth/login`,
        JSON.stringify({ email: username, password: password }),
        {
          headers: {
            "Content-Type": `application/json`,
          },
        }
      );
      console.log(res.data.data.token);
      localStorage.setItem("token", res.data.data.token);
      success();
      history.push("/jobs");
    } catch {
      seterror(true);
    }
  }

  return (
    <div className="form-box">
      <Typography variant="h5" gutterBottom component="div" className="login">
        Login
      </Typography>
      <br />
      <br />
      <TextField
        required
        id="outlined-required"
        label="Email address"
        onChange={(e) => setusername(e.target.value)}
      />
      <br />
      <Link className="forgot">Forgot your Password?</Link>
      <br />
      <br />
      <TextField
        id="outlined-password-input"
        label="Password"
        type="password"
        autoComplete="current-password"
        onChange={(e) => setpassword(e.target.value)}
      />
      <br />
      {error && (
        <Typography
          variant="body2"
          gutterBottom
          component="div"
          className="error"
        >
          Incorrect email address or password
        </Typography>
      )}
      <br />
      <br />
      <Button variant="contained" id="btnLogin" onClick={(e) => login()}>
        Login
      </Button>
      <br />
      <br />
      <Typography
        variant="subtitle1"
        gutterBottom
        component="div"
        className="register"
      >
        New to MYJOBS? <Link>Create an account</Link>
      </Typography>
    </div>
  );
}

export default Login;
