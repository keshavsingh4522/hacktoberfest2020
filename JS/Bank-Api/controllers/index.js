// Express imports
const express = require('express')
const router = express.Router()

// Middlewares for entire routes
const logMiddleware = require('../middlewares/logger.js')

//logger middleware added
router.use(logMiddleware)

//Handlers
const accountHandler = require('./account/accountHandler')
const authHandler = require('./auth/authHandler')

// const path = require('path')

// Routes in use
router.use('/bank', accountHandler)
router.use('/auth', authHandler)
router.use('/', (req, res) => {
    res.send('Bem vindo à API de Sistema bancário')
})

// 404 setup
router.use('*', (req, res) => {
    res.status(404).send('Page Not Found')
})

module.exports = router