const db = require('../database');

const debitWithdrawalModel = {
    
    debitWithdrawal: function(idaccount, balance, callback) {
      db.query('CALL debit_withdrawal(?, ?)', [idaccount, balance], function(err, result) {
        if (err) {
          callback(err, null);
        } else {
          callback(null, result);
        }
      });
    }
  };
  
  module.exports = debitWithdrawalModel;