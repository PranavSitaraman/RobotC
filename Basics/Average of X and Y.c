task main()
{
	float x = 4.1;
	float y = 3.2;
	displayTextLine(0, "%.2f", x);
	displayTextLine(1, "%.2f", y);
	float z = (x + y) / 2;
	displayTextLine(2, "%.2f", z);
	delay(10000);
}
