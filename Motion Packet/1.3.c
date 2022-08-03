task main()
{
	for (int i = 0; i < 20; i++)
	{
		drawRect(10 + 2 * i,10 + i,90 - 2 * i,50 - i);
		delay(500);
		eraseDisplay();
	}
}
