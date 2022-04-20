
// This program will loop from number from 0 to 7, its square value
// make sure you observe how "ct" is incremented.
// best is to "step through" the code with the debugger screen on.
/* sample output
     start ct = 10;
     0    0
     1    1
     2    4
     3    9
     4    16
     etc.
*/

task main()
{
	int ct=0;

	displayTextLine(0, "==================");
	displayTextLine(1, "number   number^2");
	while (ct < 8)
	{
		displayTextLine(ct, "  %5d   %5d", ct, ct*ct);
		ct = ct + 1;
		delay(100);
	}
	delay(5000);   // what is this 5 seconds delay for?
}
