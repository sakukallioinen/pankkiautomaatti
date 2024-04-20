const db=require('../database');

const cardaccount = {
    getAll: function(callback) {
      return db.query('select * from cardaccount', callback);
    },
    getById: function(id, callback) {
      return db.query('select * from cardaccount where idAccount=? AND idCard= ?', [id], callback);
    },
    add: function(cardaccount, callback) {
      return db.query(
        'insert into cardaccount (idaccount, idcard) values(?,?)',
        [cardaccount.idaccount, cardaccount.idcard ],
        callback
      );
    },
    delete: function(id, callback) {
      return db.query('delete from cardaccount where idaccount=?', [id], callback);
    },
    update: function(id, cardaccount, callback) {
      return db.query(
        'update cardaccount set idaccount=?,idcard=? where idaccount=?',
        [cardaccount.idcard, id],
        callback
      );
    }
  };
  module.exports = cardaccount;