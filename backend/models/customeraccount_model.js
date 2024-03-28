const db = require('../database');

const customerAccount = {
  getAll: function(callback) {
    return db.query('select * from customeraccount', callback);
  },
  getById: function(idCustomer, idAccount, callback) {
    return db.query('select * from customeraccount where idCustomer=? AND idAccount=?', [id], callback);
  },
  add: function(customerAccount, callback) {
    return db.query(
      'insert into customeraccount (idCustomer, idAccount) values(?,?)',
      [customerAccount.idCustomer, customerAccount.idAccount],
      callback
    );
  },
  delete: function(idCustomer, idAccount, callback) {
    return db.query('delete from customeraccount where idCustomer=? AND idAccount=?', [id], callback);
  },
  update: function(ids, customerAccount, callback) {
    return db.query(
      'update customeraccount set idCustomer=?, idAccount=? where idCustomer=? AND idAccount=?',
      [customerAccount.idCustomer, customerAccount.idAccount, ids.idCustomer, ids.idAccount],
      callback
    );
  }
};

module.exports = customerAccount;