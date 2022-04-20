task main()
{
	int a = 54;
	int b = 36;
	int temp;
	while(b>0)
	{
		temp = a%b;
		a = b;
		b = temp;
	}
	displayTextLine(4, "%d", a);
	delay(10000);
}
