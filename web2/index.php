<?php
include_once("setdb.php");

// 刪除當筆資料
if(!empty($_GET["del"])){
	$sql="delete from health where seq=".$_GET["del"];
	mysqli_query($link, $sql);
}


$sql="select * from `health`";
$ro=mysqli_query($link, $sql); // 將撈出的資料存到 ro
$row=mysqli_fetch_assoc($ro); // 每次只撈1列.

$total=mysqli_num_rows($ro); // 撈目前資料表還有多少列


?>

<html>
<head>
   <meta charset="utf-8">
   <title>健康資料表</title>
</head>
<body>
<h1>健康資料表</h1>
<div style="100%">
<table border="1">
	<tr>
		<td style="width:120" align="center">姓名</td>
		<td style="width:80" align="center">年齡</td>
		<td style="width:80" align="center">身高</td>
		<td style="width:80" align="center">體重</td>
		<td style="width:120" align="center">功能</td>
	</tr>
<?php

if($total>0){
	do{
?>	

<form method="get">
<input type="hidden" name="del" value="<?=$row["seq"]?>">
	<tr>
		<td style="width:120" align="center"><?=$row["name"]?></td>
		<td style="width:80" align="center"><?=$row["age"]?></td>
		<td style="width:80" align="center"><?=$row["height"]?></td>
		<td style="width:80" align="center"><?=$row["weight"]?></td>
		<td align="center"> 
		  <input type="button" value="修改" onclick="location.href='update.php?seq=<?=$row["seq"]?>'">
		  <input type="submit" value="刪除" >
		</td>
	</tr>
</form>

<?php
	}while($row=mysqli_fetch_assoc($ro)); //--- do
} //--- if($total>0)
?>
	<tr>
		<td colspan="4" align="center"><input type="button" onclick="location.href='add.html'" value="新增資料"></td>
	</tr>
</table>

</div>
</body>
</html>