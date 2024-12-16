<?php
include_once("setdb.php");
if(!empty($_GET["name"])){
	$sql="insert into `health` value(null,'"
		.$_GET["name"]."','"
		.$_GET["age"]."','"
		.$_GET["hei"]."','"
		.$_GET["wei"].
	"')";
	//echo $sql;
	
	//新增資料進資料庫:
	mysqli_query($link, $sql);
}

?>

<!-- 這邊要跳回首頁 --!>
<script>
location.href="index.php";

</script>