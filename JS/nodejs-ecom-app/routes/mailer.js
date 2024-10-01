const nodemailer = require("nodemailer");
const dotenv = require('dotenv').config();

module.exports = function (emailToSend, subject, text, html) {
  let transporter = nodemailer.createTransport({
    service: "gmail",
    auth: {
      user: process.env.EMAIL,
      pass: process.env.PASSWORD,
    },
  });

  let mailOptions = {
    from: process.env.EMAIL,
    to: emailToSend,
    subject: subject,
    text: text,
    html: html,
  };

  transporter.sendMail(mailOptions, function (err, data) {
    if (err) {
      console.log("Error occured: ", err);
    } else {
      console.log("email sent");
    }
  });
};