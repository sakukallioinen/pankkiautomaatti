const express = require('express');
const router = express.Router();
const bcrypt = require('bcryptjs');
const login = require('../models/login_model');
const card = require('../models/card_model');

router.post('/', 
  function(request, response) {
    if(request.body.idcard && request.body.pin){
      const idcard = request.body.idcard;
      const pin = request.body.pin;
        login.checkpin(idcard, function(dbError, dbResult) {
          if(dbError){
            response.json(dbError);
          }
          else{
            if (dbResult.length > 0) {
              bcrypt.compare(pin,dbResult[0].pin, function(err,compareResult) {
                if(compareResult) {
                  console.log("login success");
                  response.send(true);
                }
                else {
                    console.log("wrong pin");
                    response.send(false);
                }			
              }
              );
            }
            else{
              console.log("card does not exists");
              response.send(false);
            }
          }
          }
        );
      }
    else{
      console.log("card or pin missing");
      response.send(false);
    }
  }
);

module.exports=router;