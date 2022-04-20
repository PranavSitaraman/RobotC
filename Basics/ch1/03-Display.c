
// Can run this with PC-emulated mode.
//
// Be inquisitive. Make a few changes and check it out
// Step thru the code and watch the change of the value in variable "x"

task main()
{ int x = 1;
	displayTextLine(1, "x= %2d", x);
	x = x + 1;
	displayTextLine(2, "x= %3d", x);
	x = x + 1;
	displayTextLine(3, "x= %4d", x);
	x = x + 1;
	displayTextLine(4, "x= %5d", x);
	sleep(10000);
}
