<?php
   // 先處理傳過來的欲修改資料:
include_once("setdb.php");

if(!empty($_GET["upd"])){ 
	//這邊表示本頁重刷
	$sql="update health set name='".$_GET["name"]."',"."age='".$_GET["age"]."',"."height='".$_GET["hei"]."',"."weight='".$_GET["wei"]."'"." where seq='".$_GET["upd"]."'";
	//echo $sql;
	mysqli_query($link, $sql);
	
	// sql執行完就, 執行跳回首頁
	echo "<script>location.href='index.php';</script>";
	
}

if(!empty($_GET["seq"])){
	$sql="select * from health where seq=".$_GET["seq"];
	$ro=mysqli_query($link, $sql);
	$row=mysqli_fetch_assoc($ro);
}	

?>

<html>
<head><meta charset="utf-8"></head>

<body>
<h1> 修改 </h1>
<form method="get">
<input type="hidden" name="upd" value="<?=$row["seq"]?>">
	<table border="1">
			
		<tr>
			<td style="width: 80," align="center">姓名</td>
			<td><input name="name" value="<?=$row["name"]?>"></td>
		</tr>
		<tr>
			<td style="width: 80," align="center">年齡</td>
			<td><input name="age" value="<?=$row["age"]?>"></td>
		</tr>
		<tr>
			<td style="width: 80," align="center">身高</td>
			<td><input name="hei" value="<?=$row["height"]?>"></td>
		</tr>
		<tr>
			<td style="width: 80," align="center">體重</td>
			<td><input name="wei" value="<?=$row["weight"]?>"></td>
		</tr>
		<tr>
			<td colspan="2" align="center"><input type="submit" value="送出"></td>
		</tr>
	</table>
	

</form>
</body>

</html>
