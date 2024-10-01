const mongoose = require('mongoose');
const Joi = require('joi');

const itemSchema = new mongoose.Schema({
  name: {
    type: String,
    required: true
  },
  description: {
    type: String,
    required: true
  },
  stock: {
    type: Number,
    required: true
  },
  pricing: {
    type: Number,
    required: true
  },
  imgName: {
    type: String,
    required: true
  }
});

function validate(item) {
  const schema = {
    name: Joi.string().min(10).max(60).required(),
    stock: Joi.number().required(),
    description: Joi.string().min(50).max(5000).required(),
    pricing: Joi.number().required(),
    imgFileName: Joi.string().required()
  }

  return Joi.validate(item, schema);
}

const Items = mongoose.model('Items', itemSchema);

exports.Items = Items;
exports.validate = validate;