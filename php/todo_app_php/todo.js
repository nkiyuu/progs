$(function(){
    'use strict';

    //update
    $('#todos').on('click','.update_todo', function(){
        //get id
        var id = $(this).parents('li').data('id');

        //ajax
        $.post('_ajax.php',{
            id: id,
            mode: 'update'
        }, function(res){
            if(res.state === '1'){
                $('#todo_' + id).find('.todo_title').addClass('done');
            }
            else{
                $('#todo_' + id).find('.todo_title').removeClass('done');
            }
        })
    });
});