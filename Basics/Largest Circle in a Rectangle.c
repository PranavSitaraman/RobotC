task main()
{
	int x = 0;
	int y = 50;
	int z = 100;
	int w = 10;
	drawRect(x,y,z,w);



	if ((z-x) >= (y-w))
	{
		fillEllipse(x,y,x+y-w,w);
	}
	else
	{
		fillEllipse(x,y,z,y-z+x);
	}
		delay(5000);

}
