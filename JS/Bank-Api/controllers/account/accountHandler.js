const express = require('express')
const router = express.Router()

//CRUD functions
const getAllAccounts = require('./getAllAccounts')
const getAccount = require('./getAccount.js')
const createAccount = require('./createAccount')
const updateAccount = require('./updateAccount.js')
const deleteAccount = require('./deleteAccount.js')

//Middleware functions
const adminAccess = require('../../middlewares/adminAccess')
const auth = require('../../middlewares/auth')

//Routes and Middlewares
router.get('/', adminAccess, getAllAccounts.getAll)
router.get('/:account', auth, getAccount.getOne)
router.post('/create', createAccount)
router.post('/deposit', updateAccount.deposit)
router.post('/withdraw', auth, updateAccount.withdraw)
router.put('/transfer', auth, updateAccount.trasnfer)
router.delete('/delete', adminAccess, deleteAccount)

module.exports = router