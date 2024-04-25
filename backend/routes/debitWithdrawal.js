const express=require('express');
const router = express.Router()
const debitWithdrawalModel = require('../models/debitWithdrawalModel');

router.post('/', function(request, response) {
    const idaccount = request.body.idaccount;
    const amount = request.body.amount;

    debitWithdrawalModel.debitWithdrawal(idaccount, amount, function(err, result) {
        if (err) {
          console.error(err);
          response.status(500).json({ error: 'Internal server error' });
        } else {
          response.status(200).json({ message: 'Debit withdrawal successful' });
        }
      });
});

module.exports = router;