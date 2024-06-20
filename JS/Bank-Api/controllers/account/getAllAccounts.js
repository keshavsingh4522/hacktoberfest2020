const Account = require('../../models/account-model')

module.exports.getAll = async(req, res) => {
    const accounts = await Account.find()
    res.send(accounts)
}