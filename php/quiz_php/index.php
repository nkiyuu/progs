<?php

require_once (__DIR__ . '/config.php');
require_once (__DIR__ . '/Quiz.php');

$quiz = new MyApp\Quiz();
$data = $quiz->getCurrentQuiz();

shuffle($data['a']);
?>


<!DOCTYPE html>
<html>
<head>
	<meta charset="utf-8">
	<title>Quiz</title>
	<link rel="stylesheet" href="styles.css">
</head>
<body>
	<div id="container">
		<h1><?= h($data['q']) ?></h1>
		<ul>
			<?php foreach ($data['a'] as $a): ?>
			<li class="answer"><?= h($a) ?></li>
			<?php endforeach; ?>
		</ul>
	</div>
	<div id="btn" class="disabled">Next Question</div>
	<script src="https://ajax.googleapis.com/ajax/libs/jquery/2.2.4/jquery.min.js"></script>
	<script src="quiz.js"></script>
</body>
</html>