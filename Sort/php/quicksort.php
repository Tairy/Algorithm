<?php
function swap($arr, $left, $right){
	$temp = $arr[$left];
	$arr[$left] = $arr[$right];
	$arr[$right] = $temp;
}
function quicksort($left,$right,$arr){
	$l = $left;
	$r = $right;
	$pivot = $arr[($left+$right)/2];
	$temp = 0;
	while($l<$r){
		while($arr[$l] < $pivot){
			$l++;
		}

		while($arr[$r] > $pivot){
			$r--;
		}

		if($l>=$r){
			break;
		}

		$temp = $arr[$l];

	}
}