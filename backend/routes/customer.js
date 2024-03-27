const express=require('express');
const router = express.Router()
const customer=require('../models/customer_model')

router.get('/',function(request, response){
    customer.getAll(function(err,result){
    if(err){
        response.send(err);
    }
    else{
        console.log(result)
        response.json(result)
    }
    });
})

module.exports=router