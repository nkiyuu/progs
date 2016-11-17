<?php

require_once __DIR__.'/config.php';
require_once __DIR__.'/Poll.php';

 ?>


<!DOCTYPE html>
<html lang="ja">
<head>
  <meta charset="utf-8">
  <title>Poll</title>
  <link rel="stylesheet" href="styles.css">
</head>
<body>
  <h1>Which do you like best</h1>
  <form action="" method="post">
    <div class="row">
      <div class="box" id="box_0" data-id="0">5</div>
      <div class="box" id="box_0" data-id="0">10</div>
      <div class="box selected" id="box_0" data-id="0">20</div>
    </div>
    <div id="btn">Vote and See Result</div>
  </form>
</body>
</html>
