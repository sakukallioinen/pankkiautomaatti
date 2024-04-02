var express = require('express');
var path = require('path');
var cookieParser = require('cookie-parser');
var logger = require('morgan');

var customerRouter = require('./routes/customer');
var cardRouter = require('./routes/card');
var accountRouter = require('./routes/account');
var transactionsRouter = require('./routes/transactions');
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
app.use('/transactions', transactionsRouter);
app.use('/login', loginRouter);
app.use('/cardaccount', cardaccountRouter);
app.use('/customeraccount', customeraccountRouter);

module.exports = app;
 