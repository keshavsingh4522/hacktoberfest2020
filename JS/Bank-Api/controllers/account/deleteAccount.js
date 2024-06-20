const Account = require('../../models/account-model')

module.exports = async(req, res) => {
    if (!req.body.account) res.send('Body inválido. Informações insuficientes')
    try {
        await Account.findOneAndDelete({ account: req.body.account })
        res.send('conta excluída!')
    } catch (err) {
        res.send('err')
    }
}