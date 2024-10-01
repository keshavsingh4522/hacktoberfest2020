const mongoose = require('mongoose');
const Joi = require('joi');
const jwt = require('jsonwebtoken');
const config = require('config');
const boolean = require('joi/lib/types/boolean');

const moderatorSchema = new mongoose.Schema({
  name: {
    type: String,
    required: true
  },
  email: {
    type: String,
    required: true
  },
  password: {
    type: String, 
    required: true
  },
  isAdmin: {
    type: Boolean,
    default: false
  }
});

function validator(moderator) {
  const schema = {
    name: Joi.string().min(2).max(30).required(), 
    email: Joi.required(),
    password: Joi.string().min(4).max(30).required()
  }

  return Joi.validate(moderator, schema);
}

moderatorSchema.methods.generateAuthToken = function () {
  const token = jwt.sign({ _id: this._id }, config.get("jwtPrivateKey"));
  return token;
};

const Moderator = mongoose.model('moderators', moderatorSchema);

exports.validator = validator;
exports.Moderator = Moderator;