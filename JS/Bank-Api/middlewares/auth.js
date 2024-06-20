const jwt = require('jsonwebtoken')
const hash = process.env.SECRET_HASH

module.exports = (req, res, next) => {
    let token = req.headers['x-access-token'] || req.headers['authorization']

    if (!token) return res.status(401).json({ msg: 'Please, set on header request your token access aquired on /auth route' })

    if (token.startsWith('Bearer ')) {
        // Tirando da string a palavra 'Bearer' caso ela esteja no início da string
        token = token.slice(7, token.length)
    }

    jwt.verify(token, hash, (err, decoded) => {
        if (err) {
            return res.status(403).json({
                success: false,
                message: 'Invalid token.'
            })
        } else {
            req.decoded = decoded
            console.log(req.decoded)
            next()
        }
    })
}