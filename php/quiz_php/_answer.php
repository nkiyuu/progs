<?php
/**
 * Created by PhpStorm.
 * User: root
 * Date: 16/09/12
 * Time: 0:34
 */

require_once (__DIR__ . '/config.php');
require_once (__DIR__ . '/Quiz.php');

$quiz = new MyApp\Quiz();
$correctAnswer = $quiz->checkAnswer();

header('Content-Type: application/json; charset=UTF-8');
echo json_encode([
	'correct_answer' => $correctAnswer
]);