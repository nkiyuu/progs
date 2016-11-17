var N = 8;

$(function(){

    drawGameBoard(makeInitialGameBoard(), BLACK);
});

var EMPTY = 'empty';
var WHITE = 'white';
var BLACK = 'black';

//ボードの初期化
function  makeInitialGameBoard() {
    var board = new Array(N);
    for(var i = 0; i < N; i++){
        board[i] = new Array(N);
    }
    for(var row = 0; row < N ; row++){
        for(var col = 0; col < N; col++){
            board[row][col] = EMPTY;
        }
    }
}

//ボードを書く
function drawGameBoard(board, player){
    var ss = [];

    ss.push('<table align="center" border="1">');
    for(var x = 0; x < N; x++){
        ss.push('<tr>');
        for(var y = 0; y < N; y++){
            ss.push('<td width="40px" height="40px">マス</td>');
        }
        ss.push('</tr>');
    }
    ss.push('</table>');
    $('#game-board').html(ss.join(''));
    $('#current-player-name').text(player);
}