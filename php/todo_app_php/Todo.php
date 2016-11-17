<?php

namespace MyApp;

class Todo{
	private $_db;

	public function __construct()  //This function is done when this class called.
	{
		try{
			$this->_db = new \PDO(DSN, DB_USERNAME, DB_PASSWORD);  //connect to db
			$this->_db->setAttribute(\PDO::ATTR_ERRMODE, \PDO::ERRMODE_EXCEPTION);  //for Error
		}
		catch (\PDOException $e){
			echo $e->getMessage();
			exit;
		}
	}

	public function getAll(){
		$stmt = $this->_db->query("select * from todos order by id desc");
		return $stmt->fetchAll(\PDO::FETCH_OBJ);
	}


	public function post(){
		if(!isset($_POST['mode'])){
			throw new \Exception('mode not set!');
		}

		switch ($_POST['mode']) {
			case 'update':
				return $this->_update();
			case 'create':
				return $this->_create();
			case 'delete':
				return $this->_delete();
		}
	}

	private function _update(){
		if(!isset($_POST['id'])){
			throw new \Exception('[update]id not set!');
		}

		$this->_db->beginTransaction();

		$sql = sprintf("update todos set state = (state + 1) %% 2 where id = %d", $_POST['id']);
		$stmt = $this->_db->prepare($sql);
		$stmt->execute();

		$sql = sprintf("select state from todos where id = %d", $_POST['id']);
		$stmt = $this->_db->query($sql);
		$state = $stmt->fetchColumn();

		$this->_db->commit();

		return [
			'state' => $state
		];
	}

	private function _create(){

	}

	private function _delete(){

	}

}


?>