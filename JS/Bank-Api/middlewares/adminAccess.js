const jwt = require('jsonwebtoken')
const hash = process.env.SECRET_HASH

module.exports = (req, res, next) => {
    let token = req.headers['x-access-token'] || req.headers['authorization']

    if (!token) return res.status(400).json({ msg: 'Please do the authentication to proceed with the API Functions' })

    if (token.startsWith('Bearer ')) {
        // Tirando da string a palavra 'Bearer' caso ela esteja no início da string
        token = token.slice(7, token.length)
    }

    jwt.verify(token, hash, (err, decoded) => {
        if (err) {
            return res.json({
                success: false,
                message: 'Token invalid. Please authenticate your bank account.'
            })
        } else {
            req.decoded = decoded
            if (req.decoded.admin === "true") {
                next()
            } else {
                return res.status(401).json({ msg: 'Please do the authentication with a admin account to proceed with the API Functions' })
            }
        }
    })
}