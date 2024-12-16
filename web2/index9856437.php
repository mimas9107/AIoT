<?php
$a="1234";
$b="5678";

echo '<html>';
echo '<head>
<meta charset="UTF-8">
<title>Hello world!-這是網站 title</title>
</head>';

echo '<body>';

echo '<h1><font color=#0000ff> 這是第一個 php程式 hello world!</font></h1>';
echo '<div>';
	echo "字串a+字串b = ".$a+$b;
	echo '<br/>';
	echo "字串a.字串b = ".$a.$b;
echo '</div>';

echo '<div>';
	$arr[]="aaaaaa";
	echo '<br/>';
	echo $arr[0];
	echo '<br/>';
	echo '<br/>';
	$weekarray[]='星期日';
	$weekarray[]='星期一';
	$weekarray[]='星期二';
	$weekarray[]='星期三';
	$weekarray[]='星期四';
	$weekarray[]='星期五';
	$weekarray[]='星期六';
	for($i=0; $i<7; $i++){
		echo $weekarray[$i]."<br/>";
	}
echo '</div>';

echo '<br/>';
echo '<br/>';

echo '<div>';
	$weekarr=array("Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday");
	for($i=0;$i<7;$i++){
		echo $weekarr[$i]."<br/>";
	}
echo '<div>';

echo '</body>';
echo '</html>';;


?>