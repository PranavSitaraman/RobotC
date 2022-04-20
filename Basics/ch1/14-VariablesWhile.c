
// Importamt:  "while" expression ends with a ";"
//            compare this with the exercise before this
task main()
{
	int ct;

	ct=2;
	displayTextLine(0, "check before do");
	while (ct<3) {
		displayTextLine(1, "  %5d   %5d", ct, ct*ct);
		ct = ct + 1;
		wait1Msec(100);
	}
	displayTextLine(3 , "---------");


	ct = 2;
	displayTextLine(4, "do before check");
	do   {
		displayTextLine(5, "  %5d   %5d", ct, ct*ct);
		ct = ct + 1;
		wait1Msec(100);
	} while (ct < 3);
	displayTextLine(6 , "---------");
	wait1Msec(5000);
}
