const nodemailer = require('nodemailer');

module.exports = (message, destinatary, subject) => {
    const transporter = nodemailer.createTransport({
        service: 'Gmail',
        auth: {
            user: process.env.EMAIL_SENDER,
            pass: process.env.EMAIL_SENDER_PASS
        }
    });

    const mail = {
        from: 'dontreplyibank@gmail.com',
        to: destinatary,
        subject: subject,
        text: message
    };

    transporter.sendMail(mail);
};