<?php

namespace MyApp;

class Poll
{
    private $_db;

    public function __construct()
    {
        $this->_connectDB();
    }

    private function _connectDB()
    {
        try {
            $this->_db = new \PDO(DSN, DB_USERNAME, DB_PASSWORD);
            $this->_db->setAttribute(\PDO::ATTR_ERRMODE, \PDO::ERRMODE_EXCEPTION);
        } catch (\PDOException $e) {
            throw new \Exception('Faild to connect DB');
        }
    }
}
