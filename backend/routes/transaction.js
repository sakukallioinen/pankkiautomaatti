const express=require('express');
const router = express.Router()
const transaction=require('../models/transaction_model');


router.get('/',function(request, response){
    transaction.getAll(function(err,result){
    if(err){
        response.send(err);
    }
    else{
        console.log(result);
        response.json(result);
    }
    });
});

router.get('/:id',function(request, response){
    transaction.getById(request.params.id,function(err,result){
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
    transaction.add( request.body, function(err, result){
        if(err){
            response.send(err);
        }
        else{
            response.json(result);
        }
    });
});

router.delete('/:id', 
function(request, response) {
  transaction.delete(request.params.id, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult);
    }
  });
});


router.put('/:id', 
function(request, response) {
  transaction.update(request.params.id, request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult);
    }
  });
});

module.exports=router
