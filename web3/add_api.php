<?php
include_once("setdb.php");
if(!empty($_GET["temp"])){
	$sql="insert into th_data value(null,'"
		.$_GET["temp"]."','"
		.$_GET["humi"]."','"
		.$now_date."','"
		.$now_time.
	"')";
	//echo $sql;
	
	//新增資料進資料庫:
	mysqli_query($link, $sql);
}

?>

<!-- 這邊要跳回首頁 ESP32 project先保留著要看 response! --!>
<script>location.href="index.php";</script>