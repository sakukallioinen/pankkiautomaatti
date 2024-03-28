const express=require('express');
const router = express.Router()
const card=require('../models/card_model');
const { response } = require('../app');


router.get('/',function(request, response){
    card.getAll(function(err,result){
    if(err){
        response.send(err);
    }
    else{
        console.log(result);
        response.json(result);
    }
    });
});

router.post('/',function(request, response){
    card.add( request.body, function(err, result){
        if(err){
            response.send(err);
        }
        else{
            response.json(result);
        }
    });
});

module.exports=router
