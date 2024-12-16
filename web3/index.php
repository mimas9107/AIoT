<?php
include_once("setdb.php");
echo $now_date."<br/>".$now_time;

// 刪除當筆資料
if(!empty($_GET["del"])){
	$sql="delete from th_data where seq=".$_GET["del"];
	mysqli_query($link, $sql);
}


$sql="select * from th_data";
$ro=mysqli_query($link, $sql); // 將撈出的資料存到 ro
$row=mysqli_fetch_assoc($ro); // 每次只撈1列.

$total=mysqli_num_rows($ro); // 撈目前資料表還有多少列


?>

<html>
<head>
   <meta charset="utf-8">
   <title>溫溼度網站</title>
</head>
<body>
<h1>溫溼度網站</h1>
<div style="100%">
<table border="1">
	<tr>
		<td style="width:80" align="center">溫度</td>
		<td style="width:80" align="center">濕度</td>
		<td style="width:80" align="center">日期</td>
		<td style="width:80" align="center">時間</td>
		<td style="width:120" align="center">功能</td>
	</tr>
<?php

if($total>0){
	do{
?>	

<form method="get">
<input type="hidden" name="del" value="<?=$row["seq"]?>">
	<tr>
		<td style="width:80" align="center"><?=$row["temp"]?></td>
		<td style="width:80" align="center"><?=$row["humi"]?></td>
		<td style="width:80" align="center"><?=$row["date"]?></td>
		<td style="width:80" align="center"><?=$row["time"]?></td>
		
		<td align="center"> 
		  
		  <input type="submit" value="刪除" >
		</td>
	</tr>
</form>

<?php
	}while($row=mysqli_fetch_assoc($ro)); //--- do
} //--- if($total>0)
?>
	
</table>

</div>
</body>
</html>