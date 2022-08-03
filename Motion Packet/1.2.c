task main()
{
	for (int i = 0; i < 50; i+=5)
	{
		drawRect(10,50 - i,20,45 - i);
		delay(500);
		eraseDisplay();
	}
}
