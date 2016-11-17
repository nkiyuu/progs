<?php
/**
 * Created by PhpStorm.
 * User: root
 * Date: 16/09/12
 * Time: 0:20
 */
namespace MyApp;

class Quiz{


	private $_quizSet= [];

	public function __construct()
	{
		$this->setup();

		if(!isset($_SESSION['current_num'])){
			$_SESSION['current_num'] = 0;
		}

	}

	private function setup(){
		$this->_quizSet[] = [
			'q' => 'What is A ?',
			'a' => ['a1', 'a2', 'a3', 'a4']
		];
		$this->_quizSet[] = [
			'q' => 'What is B ?',
			'a' => ['b1', 'b2', 'b3', 'b4']
		];
		$this->_quizset[] = [
			'q' => 'What is C ?',
			'a' => ['c1', 'c2', 'c3', 'c4']
		];

	}

	public function getCurrentQuiz(){
		return $this->_quizSet[$_SESSION['current_num']];
	}

	public function checkAnswer(){
		$correctAnswer = $this->_quizSet[$_SESSION['current_num']]['a'][0] ;
		return $correctAnswer;
	}
}