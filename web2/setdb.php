<?php
// link to localhost mysql database:
// XAMPP default => username: "root", password: ""
$link=mysqli_connect("localhost","root","","web2");

mysqli_query($link, "set names utf8");

?>