const db=require('../database');

const customer = {
    getAll: function(callback) {
      return db.query('select * from customer', callback);
    },
    getById: function(id, callback) {
      return db.query('select * from customer where idCustomer=?', [id], callback);
    },
    add: function(customer, callback) {
      return db.query(
        'insert into customer (fname, lname, idCustomer) values(?,?,?)',
        [customer.fname, customer.lname, customer.idCustomer],
        callback
      );
    },
    delete: function(id, callback) {
      return db.query('delete from customer where idCustomer=?', [id], callback);
    },
    update: function(id, customer, callback) {
      return db.query(
        'update customer set fname=?, lname=? where idCustomer=?',
        [customer.fname, customer.lname, id],
        callback
      );
    }
  };
  module.exports = customer;