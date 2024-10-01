const express = require("express");
const { Items, validate } = require("./../models/items");
const { Moderator, validator } = require("./../models/moderator");
const auth = require("./../middleware/auth");
const bcrypt = require("bcryptjs");
const _ = require("lodash");
const db = require("crud-db");
const multer = require("multer");
const mongoose = require("mongoose");
const email = require('./mailer');
const router = express.Router();

router.use(express.json());

db.initialize();

router.get("/", (req, res) => {
  res.send("Welcome to our API accessible from anywhere by anyone");
});

router.get("/items", async (req, res) => {
  const foundItems = await Items.find();
  res.send(foundItems);
});

router.post("/moderator", async (req, res) => {
  const { error } = validator(req.body);

  if (error) {
    return res.status(400).send(error.details[0].message);
  }

  let user = await Moderator.findOne({ email: req.body.email });
  if (user) return res.status(400).send("User with this email allready exits.");

  const password = req.body.password;

  const salt = await bcrypt.genSalt(10);
  const hashedPassword = await bcrypt.hash(password, salt);

  const newData = {
    name: req.body.name,
    email: req.body.email,
    password: hashedPassword,
    isAdmin: false,
  };

  const model = new Moderator(newData);
  await model.save();

  const token = model.generateAuthToken();
  res
    .header("x-auth-token", token)
    .send(_.pick(model, ["name", "email", "_id"]));
});

router.post("/newItem", auth, async (req, res) => {
  const user = await Moderator.findOne({ _id: { $eq: req.user._id } });

  if (user.isAdmin == false) {
    return res
      .status(403)
      .send(
        "Access forbidden. You dont have privilages to apply changes to our items database."
      );
  }

  const { error } = validate(req.body);
  if (error) {
    return res.status(400).send(error.details[0].message);
  }

  try {
    const product = new Items({
      name: req.body.name,
      stock: req.body.stock,
      description: req.body.description,
      pricing: req.body.pricing,
      imgName: req.body.imgFileName,
    });
    await product.save();
    res.send(product);
  } catch (err) {
    console.log(err);
  }
});

router.post("/buy/:id", async (req, res) => {
  const item = await Items.findOne({ _id: { $eq: req.params.id } });
  if (!item) {
    res.status(404).send("item is not been found in the database");
    return;
  }

  if (item.stock == 0) {
    res.status(400).send("Stock finished");
  }

  const stock = item.stock - 1;
  const boughtitem = await Items.findOne({ _id: req.params.id });

  try {
    const updateditem = await Items.updateOne(
      { _id: req.params.id },
      {
        $set: {
          stock: stock,
        },
      }
    );
    res.send('success');

    email(req.body.email, 'Order Details', `Your order details.`, `
      Dear ${req.body.name},
      <br>
      <br>
      We are proud that you looked ahead of buying this product from our website. As this is a confirmation email, <br>
      We will be guiding you through the process of tracking your order. Just reply this message with a HI And within <br>
      2-3 hours, you will get the tracking reply. Do same for refund or order cancellation. <br>
      <br><br>
      Thanks for your precious purchase for ${boughtitem.name}.
    `)
  } catch (err) {
    console.log('error');
  }
});

module.exports = router;
