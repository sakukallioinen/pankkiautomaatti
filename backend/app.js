const jwt = require('jsonwebtoken');

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

app.use('/login', loginRouter);

app.use(authenticateToken);

app.use('/customer', customerRouter);
app.use('/card', cardRouter);
app.use('/account', accountRouter);
app.use('/transaction', transactionRouter);

app.use('/cardaccount', cardaccountRouter);


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
 