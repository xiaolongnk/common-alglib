<?php

function formatImages(&$v) 
{
	if (empty($resp)) {
		return;
	}
	if (is_array($resp) || is_object($resp)) {
		foreach($resp as $k => $v) {
			formatImages($v);
		}
	} else {
		if (substr($resp, 0, 9) == '/products') {
			$resp = config('app.image_domain').$resp;
		}
	}
}



?>
