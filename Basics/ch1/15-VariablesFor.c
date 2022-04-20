// modification:
//    start ct = 10;
//    display in decremental order
//    e.g.      9     81
//              8     64
//    display 10 of them

task main()
{
	int ct=10;

	displayTextLine(1, "==================");
	displayTextLine(2, "number   number^2");
	for (ct; ct>0; ct--)
	{
		displayTextLine(3, "  %5d   %5d", ct, ct*ct);
		delay(5000);
	}

}
