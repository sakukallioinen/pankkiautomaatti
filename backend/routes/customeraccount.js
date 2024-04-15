const express=require('express');
const router = express.Router()
const customeraccount = require('../models/customeraccount_model');


router.get('/',function(request, response){
    customeraccount.getAll(function(err,result){
    if(err){
        response.send(err);
    }
    else{
        console.log(result);
        response.json(result);
    }
    });
});