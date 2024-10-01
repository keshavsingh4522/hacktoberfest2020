const express = require('express');
const router = express.Router();
const bcrypt = require('bcryptjs');
const { Moderator, validator } = require('./../models/moderator');
const jwt = require('jsonwebtoken');
const config = require('config');

router.use(express.json());

router.post('/', async (req, res) => {
    const { error } = validator(req.body);

    if(error) return res.status(400).send(error.details[0].message);

    let user = await Moderator.findOne({ email: { $eq: req.body.email } });
    if(!user) return res.status(404).send('Invalid email.');

    const password = req.body.password;

    const validPassword = await bcrypt.compare(password, user.password);

    if(!validPassword) return res.status(400).send('password does not match with the user.');

    const token = jwt.sign({ _id: user._id }, config.get('jwtPrivateKey'));

    res.send(token);
});

module.exports = router;