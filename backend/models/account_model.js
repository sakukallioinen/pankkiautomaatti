const db = require('../database');

const account = {
  getAll: function(callback) {
    return db.query('select * from account', callback);
  },
  getById: function(id, callback) {
    return db.query('select * from account where idAccount=?', [id], callback);
  },
  add: function(account, callback) {
    return db.query(
      'insert into account (balance, creditLimit, idAccount) values(?,?,?)',
      [account.balance, account.creditLimit, account.idAccount],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from account where idAccount=?', [id], callback);
  },
  update: function(id, account, callback) {
    return db.query(
      'update account set balance=?, creditLimit=? where idAccount=?',
      [account.balance, account.creditLimit, id],
      callback
    );
  }
};

module.exports = account;