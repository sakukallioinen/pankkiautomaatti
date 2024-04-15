const express=require('express');
const router = express.Router()
const cardaccount = require('../models/cardaccount_model');


router.get('/',function(request, response){
    cardaccount.getAll(function(err,result){
    if(err){
        response.send(err);
    }
    else{
        console.log(result);
        response.json(result);
    }
    });
});