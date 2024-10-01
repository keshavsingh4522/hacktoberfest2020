const express = require('express')

const app = express()

const publicDirectoryPath = __dirname
const port = process.env.PORT || 3000

app.use(express.static(publicDirectoryPath))

app.get('', (req, res) => {
  res.render('index')
})

app.listen(port, () => {
  console.log('Server is up on port ' + port)
})