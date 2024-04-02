var express = require('express');
var path = require('path');
var cookieParser = require('cookie-parser');
var logger = require('morgan');

var customerRouter = require('./routes/customer');
var cardRouter = require('./routes/card');
var accountRouter = require('./routes/account');
var transactionRouter = require('./routes/transaction');
var loginRouter = require('./routes/login');
var cardaccountRouter = require('./routes/cardaccount');
var customeraccountRouter = require('./routes/customeraccount');

var app = express();

app.use(logger('dev'));
app.use(express.json());
app.use(express.urlencoded({ extended: false }));
app.use(cookieParser());
app.use(express.static(path.join(__dirname, 'public')));

app.use('/customer', customerRouter);
app.use('/card', cardRouter);
app.use('/account', accountRouter);
app.use('/transaction', transactionRouter);
app.use('/login', loginRouter);


module.exports = app;
 