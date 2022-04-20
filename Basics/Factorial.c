task main()
{
	int x = 1;
	int factorial = 1;
	while (x <= 6)
	{
		factorial = factorial * x;
		x++;
	}
	displayTextLine(4,"%d", factorial);
	delay(5000);
}
