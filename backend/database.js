const mysql = require('mysql2');
const myConnectionString = "mysql://bankuser:bankpass@127.0.0.1:3306/bankautomat";
const connection = mysql.createPool(myConnectionString);
module.exports = connection;