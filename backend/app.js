const jwt = require('jsonwebtoken');
const session = require('express-session');


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
const debitWithdrawalRouter = require('./routes/debitwithdrawal');

var app = express();

app.use(logger('dev'));
app.use(express.json());
app.use(express.urlencoded({ extended: false }));
app.use(cookieParser());
app.use(express.static(path.join(__dirname, 'public')));

app.use(session({
  secret: 'your secret',
  resave: false,
  saveUninitialized: true
}));

app.use('/login', loginRouter);


//app.use(authenticateToken);

app.use('/debitWithdrawal', debitWithdrawalRouter);
app.use('/customer', customerRouter);
app.use('/card', cardRouter);
app.use('/account', accountRouter);
app.use('/transaction', transactionRouter);

app.use('/cardaccount', cardaccountRouter);
app.use('/customeraccount', customeraccountRouter);


function authenticateToken(req, res, next) {
    const authHeader = req.headers['authorization']
    const token = authHeader && authHeader.split(' ')[1]
  
    console.log("token = "+token);
    if (token == null) return res.sendStatus(401)
  
    jwt.verify(token, process.env.MY_TOKEN, function(err, user) {
  
      if (err) return res.sendStatus(403)

      req.user = user
  
      next()
    })
  }

module.exports = app;
 