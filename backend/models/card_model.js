const db=require('../database');
const bcrypt = require('bcrypt');

const card = {
    getAll: function(callback) {
      return db.query('select * from card', callback);
    },
    getById: function(id, callback) {
      return db.query('select * from card where idcard=?', [id], callback);
    },
    add: function(card, callback) {
        bcrypt.hash(card.pin,10,function(err,hashedPin)
        {
            return db.query(
                'insert into card (pin, cardType, idcard) values(?,?,?)',
                [hashedPin, card.cardType, card.idcard],
                callback
              );
        });  
    },

    delete: function(id, callback) {
      return db.query('delete from card where idcard=?', [id], callback);
    },

    update: function(id, card, callback) {
      
      bcrypt.hash(card.pin, 10, function(err, hashedPin) {
        if (err) {
          callback(err); 
        } else {
          return db.query(
            'update card set pin=?, cardType=? where idcard=?',
            [hashedPin, card.cardType, id],
            callback
          );
        }
      });
    }
  };
  module.exports = card;