const Account = require('../../models/account-model')

module.exports.getOne = async(req, res) => {
    if (!req.params.account) res.status(400).send('Parâmetros vazios. Informe uma conta válida.')
    try {
        const account = await Account.findOne({ account: req.params.account })
        res.status(200).send(account)
    } catch (err) {
        res.status(500).send(err)
    }
}