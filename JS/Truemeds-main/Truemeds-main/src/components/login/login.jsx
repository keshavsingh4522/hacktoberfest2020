import React, { useState } from "react";
import axios from "axios";
import { useHistory } from "react-router-dom";
import Button from "@mui/material/Button";
import TextField from "@mui/material/TextField";
import Typography from "@mui/material/Typography";

function Login(props) {
  const [phone, setphone] = useState(0);
  const [password, setpassword] = useState("");
  const [sent, setsent] = useState(false);
  const [error1, seterror1] = useState(false);
  const [error2, seterror2] = useState(false);
  let history = useHistory();
  async function send() {
    try {
      setsent(false);
      seterror1(false);
      seterror2(false);
      if (
        (phone[0] === "6" ||
          phone[0] === "7" ||
          phone[0] === "8" ||
          phone[0] === "9") &&
        phone.length === 10
      ) {
        const res = await axios.post(
          `https://stage-services.truemeds.in/CustomerService/sendOtp?mobileNo=${phone}`,
          {},
          {
            headers: {
              transactionId: "react_interview",
            },
          }
        );
        console.log(res);
        setsent(true);
      } else seterror1(true);
    } catch {
      seterror1(true);
    }
  }

  async function verify() {
    try {
      seterror2(false);
      seterror1(false);
      const res = await axios.post(
        `https://stage-services.truemeds.in/CustomerService/verifyOtp?mobileNo=${phone}&otp=${password}&de
        viceKey=abcd&isIos=false&source=react_interview`,
        {},
        {
          headers: {
            transactionId: "react_interview",
          },
        }
      );
      console.log(res.data.Response.access_token);
      localStorage.setItem("token", res.data.Response.access_token);
      props.success();
      history.push("/");
    } catch {
      seterror2(true);
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
        id="outlined-number"
        type="number"
        label="Phone"
        onChange={(e) => setphone(e.target.value)}
      />
      <br />
      <br />
      {error1 && (
        <Typography
          variant="body2"
          gutterBottom
          component="div"
          className="error"
        >
          Please Enter correct number
        </Typography>
      )}
      <br />
      <br />
      {sent && (
        <TextField
          id="outlined-password-input"
          label="Enter OTP"
          type="password"
          autoComplete="current-password"
          onChange={(e) => setpassword(e.target.value)}
        />
      )}

      <br />
      {error2 && (
        <Typography
          variant="body2"
          gutterBottom
          component="div"
          className="error"
        >
          Incorrect OTP
        </Typography>
      )}
      <br />
      <br />
      {sent ? (
        <div>
          <Button variant="contained" id="btnLogin" onClick={(e) => send()}>
            Resend OTP
          </Button>
          &nbsp;
          <Button variant="contained" id="btnLogin" onClick={(e) => verify()}>
            Login
          </Button>
        </div>
      ) : (
        <Button variant="contained" id="btnLogin" onClick={(e) => send()}>
          Generate OTP
        </Button>
      )}
      <br />
    </div>
  );
}

export default Login;
