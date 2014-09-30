<?php
//If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
//Find the sum of all the multiples of 3 or 5 below 1000.

$x = 1000;
echo 1.5*(int)(($x-1)/3)*(int)(($x+2)/3) + 2.5*(int)(($x-1)/5)*(int)(($x+4)/5) - 7.5*(int)(($x-1)/15)*(int)(($x+14)/15);