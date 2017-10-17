<?php    
$mb = "I am 欧小龙";
$ans = mb_substr($mb , 0, 8 ,'utf8');

function reverse($str)
{
	$ll = mb_strlen($str,'utf8');
	$ans = "";
    for($i = $ll; $i > 0 ; $i--){
        $content = mb_substr($str , $i - 1 , 1 , 'utf8');
        $ans .= $content;
	}
	return $ans;
}
echo reverse($mb);
