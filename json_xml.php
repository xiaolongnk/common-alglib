<?php

$ans = <<<EOT
	<?xml version="1.0" encoding="UTF-8"?>  
	  <humans>  
	  <zhangying>  
	  <name>张映</name>  
	  <sex>男</sex>  
	  <old>28</old>  
	  </zhangying>  
	  <tank>  
	  <name>tank</name>  
	  <sex>  
	 <hao>yes</hao>  
	 <aaaa>no</aaaa>  
	 </sex>  
	  <old>28</old>  
	  </tank>  
	  </humans>
EOT;

function xml_to_json($source) {  
	if(is_file($source)){
		$xml_array=simplexml_load_file($source);  
	}else{  
		$xml_array=simplexml_load_string($source);  
	}  
	$json = json_encode($xml_array);
	return $json;  
}

$tt = xml_to_json($ans);

function json_to_xml($source,$charset='utf8') {  
	if(empty($source)){
		return false;  
	}
	$array = json_decode($source);
	$xml  ='<?xml version="1.0" encoding="'.$charset.'"?>';  
	$xml .= change($array);  
	return $xml;  
}  

function change($source) {  
	$string=""; 
	foreach($source as $k=>$v){ 
		$string .="<".$k.">"; 
		if(is_array($v) || is_object($v)){
			$string .= change($v);
		}else{ 
			$string .=$v;
		}
		$string .="</".$k.">";  
	}  
	return $string;  
}
$ww = json_to_xml($tt , 'utf8');
print($ww);

