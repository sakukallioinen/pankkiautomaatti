const express = require('express');
const router = express.Router();
const bcrypt = require('bcryptjs');
const login = require('../models/login_model');
const jwt = require('jsonwebtoken');
const dotenv = require('dotenv');

router.post('/checkcard', function(request, response) {
  if(request.body.idcard){
    const idcard = request.body.idcard;
    login.checkCard(idcard, function(err, result) {
      if(err){
        response.json(err.errno);
      }
      else{
        if (result.length > 0) {
          request.session.idcard = idcard;
          console.log("card exists");
          response.send(true);
        }
        else{
          console.log("card does not exist");
          response.send(false);
        }
      }
    });
  }
  else{
    console.log("card missing");
    response.send(false);
  }
});

router.post('/checkpin', function(request, response) {
  if(request.body.pin && request.body.idcard){
    const idcard = request.body.idcard;
    const pin = request.body.pin;
    login.checkPin(idcard, function(dbError, dbResult) {
      if(dbError){
        response.json(dbError);
      }
      else{
        if (dbResult.length > 0) {
          bcrypt.compare(pin,dbResult[0].pin, function(err,compareResult) {
            if(compareResult) {
              console.log("login success");
              const token=generateAccessToken({idcard: idcard});
              response.send(token);
            }
            else {
              console.log("wrong pin");
              response.send(false);
            }			
          });
        }
        else{
          console.log("card does not exist");
          response.send(false);
        }
      }
    });
  }
  else{
    console.log("card or pin missing");
    response.send(false);
  }
});

function generateAccessToken(value) {
  dotenv.config();
  return jwt.sign(value, process.env.MY_TOKEN, { expiresIn: '1800s' });
}

module.exports=router;