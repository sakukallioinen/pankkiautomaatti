const express=require('express');
const router = express.Router()
const cardAccount = require('../models/cardaccount_model');


router.get('/',function(request, response){
    cardAccount.getAll(function(err,result){
    if(err){
        response.send(err);
    }
    else{
        console.log(result);
        response.json(result);
    }
    });
});

router.get('/:idaccount',
    function (request, response) {
        cardAccount.getById(request.params.idaccount, function (err, dbResult) {
            if (err) {
                response.json(err);
            } else {
                response.json(dbResult);
            }
        })
    });

router.post('/',function(request, response){
    cardAccount.add( request.body, function(err, result){
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
  cardAccount.delete(request.params.id, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult);
    }
  });
});


router.put('/:id', 
function(request, response) {
  cardAccount.update(request.params.id, request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult);
    }
  });
});



module.exports=router;