const db=require('../database');

const transaction = {
    getAll: function(callback) {
      return db.query('select * from transaction', callback);
    },
    getById: function(id, callback) {
      return db.query('select * from transaction where idtransaction=?', [id], callback);
    },
    add: function(transaction, callback) {
      return db.query(
        'insert into transaction (idtransaction, date, withdraw, amount ) values(?,?,?,?)',
        [transaction.idtransaction, transaction.date, transaction.withdraw, transaction.amount],
        callback
      );
    },
    delete: function(id, callback) {
      return db.query('delete from transaction where idtransaction=?', [id], callback);
    },
    update: function(id, transaction, callback) {
      return db.query(
        'update transaction set withdraw=?,date=?,amount=? where idtransaction=?',
        [transaction.withdraw, transaction.date, transaction.amount, id],
        callback
      );
    }
  };
  module.exports = transaction;