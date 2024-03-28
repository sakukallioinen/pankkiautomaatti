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
        'insert into cardaccount (idcardaccount, idcard) values(?,?)',
        [cardaccount.idcardaccount, cardaccount.idcard ],
        callback
      );
    },
    delete: function(id, callback) {
      return db.query('delete from cardaccount where idcardaccount=?', [id], callback);
    },
    update: function(id, cardaccount, callback) {
      return db.query(
        'update cardaccount set idcardaccount=?,idcard=? where idcardaccount=?',
        [cardaccount.idcard, id],
        callback
      );
    }
  };
  module.exports = cardaccount;