/**
 * Created by root on 16/09/12.
 */

$(function(){
    'use strict';

    $('.answer').on('click', function () {
        var $selected = $(this);
        $selected.addClass('selected');
        if($selected.hasClass('correct') || $selected.hasClass('wrong')){
            return;
        }
        var answer = $selected.text();

        $.post('/_answer.php', {

        }).done(function (res) {
            $('.answer').each(function(){
                if($(this).text() === res.correct_answer){
                    $(this).addClass('correct');
                }
                else{
                    $(this).addClass('wrong');
                }
            });
            if(answer === res.correct_answer){
                //correct!
                $selected.text(answer + '....CORRECT!')
            }
            else{
                //wrong!
                $selected.text(answer + '....WRONG!')
            }
            $('#btn').removeClass('disabled');
        });
    });

    $('#btn').on('click', function(){
        console.log('test');
        if(!$(this).hasClass('disabled')){
            location.reload();
        }
    });
});