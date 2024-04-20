const db = require('../database');

exports.checkCard = function(idcard, callback) {
  db.query('SELECT * FROM card WHERE idcard = ?', [idcard], function(error, results, fields) {
    if (error) {
      callback(error, null);
    } else {
      callback(null, results);
    }
  });
};

exports.checkPin = function(idcard, callback) {
  db.query('SELECT pin FROM card WHERE idcard = ?', [idcard], function(error, results, fields) {
    if (error) {
      callback(error, null);
    } else {
      callback(null, results);
    }
  });
};