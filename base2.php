<?php

$a = [5,3];
$b = [3,5,9];

$c = array_intersect($a , $b);
if($a == $c || $b == $c) {
    echo "yes\n";
} else {
    echo "false\n";
}

if( [3,5] == [3,5]){
    echo "equal\n";
}

?>
