
// WATCH closely to see the differences
// Again, be inquisitive

task main()
{
	int i=10, j=20;

	displayTextLine(0, "this is robotc!");
	displayTextLine(1, "i = %d; j = %d", i, j);
	displayTextLine(2, "i * j = %d", i * j);
	displayTextLine(3, "i * j = %f", i * j);

	displayTextLine(4, "i / j = %d", i/j);  // watch the difference from the ones below
	displayTextLine(5, "i / j = %f", i/j);

	displayTextLine(6, "i / j = %d", (float)i/j); //
	displayTextLine(7, "i / j = %f", (float)i/j); //

	wait1Msec(10000);

}
