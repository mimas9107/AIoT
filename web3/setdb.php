<?php
// link to localhost mysql database:
// XAMPP default => username: "root", password: ""
$link=mysqli_connect("localhost","root","","web2");

mysqli_query($link, "set names utf8");

//設定時間相關處理
$nt=strtotime("+7 hours");
$now_date=date("Y-m-d", $nt);
$now_time=date("H:i:s", $nt);

?>