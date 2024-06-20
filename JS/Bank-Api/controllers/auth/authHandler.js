const express = require('express')
const router = express.Router()

const verifAccount = require('./verifAccount')

//rotas em uso:
router.post('/', verifAccount.findByAccount)

module.exports = router