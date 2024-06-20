const Account = require('../../models/account-model')

module.exports.trasnfer = async(req, res) => {
    if (!req.body.incAccount || !req.body.outAccount || !req.body.value) return res.status(204).json({ msg: 'Favor informar um Body válido' })
    const out = req.body.outAccount
    const inc = req.body.incAccount
    const valueOfTransaction = req.body.value

    const accountTransferOut = await Account.findOne({ account: out })
    
    //Caso o haja saldo disponível para a transferência...
    let transferWithdraw
    if(accountTransferOut.value >= valueOfTransaction) {
        transferWithdraw = accountTransferOut.value - valueOfTransaction
    } else {
        return res.status(400).json({ msg: 'Não há saldo disponível para a transação se completar.' })
    }
    
    const accountTransferInc = await Account.findOne({ account: inc })
    let transferDeposit = accountTransferInc.value + valueOfTransaction
    try {
        await Account.findByIdAndUpdate(accountTransferOut._id, { value: transferWithdraw })
        await Account.findByIdAndUpdate(accountTransferInc._id, { value: transferDeposit })
        res.status(200).json({ msg: 'Transferência executada com sucesso.' })
    } catch (err) {
        res.status(500).json({ msg: 'Internal Error. Please contact the administrator' })
    }
}

module.exports.deposit = async(req, res) => {
    if (!req.body.account && !req.body.value) return res.status(204).json({ msg: 'Favor informar um Body válido' })

    const account = await Account.findOne({ account: req.body.account })
    const saldo = parseInt(account.value)
    const valueAfterDeposit = saldo + req.body.value

    try {
        await Account.updateOne({ account: req.body.account }, { value: valueAfterDeposit })
        res.status(200).json({ msg: 'Depósito executado com sucesso.' })
    } catch (error) {
        res.status(500).json({ msg: 'Internal Error. Please contact the administrator' })
    }
}

module.exports.withdraw = async(req, res) => {
    if (!req.body.account && !req.body.value) return res.status(204).json({ msg: 'Favor informar um Body válido' });
    let accountToSearch = req.body.account

    const accountSearched = await Account.findOne({ account: accountToSearch })
    const withdrawValue = parseInt(accountSearched.value)
    const valueAfterWithdraw = withdrawValue - req.body.value

    try {
        await Account.updateOne({ account: accountSearched.account }, { value: valueAfterWithdraw })
        res.status(200).json({ msg: 'Saque executado com sucesso.' })
    } catch (error) {
        res.status(500).json({ msg: 'Internal Error. Please contact the administrator' })      
    }
}