task main()
{
	int x = 1;
	while(x<=7)
	{ motor[motorB] = 50;
		motor[motorC] = 50;
		delay(2250);
		if (x%2 == 1)
		{motor[motorC] = 0;
			delay(1050);}
		else
		{motor[motorB] = 0;
			delay(1050);
		}
		x=x + 1;
	}
}
