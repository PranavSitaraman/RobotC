//B = LM
//C = RM
task main()
{
	int x = 1;
	float target = 360/(5.5 * 3.1415926535) * 6.3;
	while(true)
	{
		nMotorEncoder[motorB] = 0;
		nMotorEncoder[motorC] = 0;
		while(nMotorEncoder[motorB] < target)
		{	motor[motorB] = 50;
			motor[motorC] = 50;
		}

		if (x%2 == 1)
		{
			motor[motorB] = 50;
			motor[motorC] = 0;
			delay(2150);}
		else
		{
			motor[motorB] = 0;
			motor[motorC] = 50;
			delay(2150);
		}
		x=x + 1;
	}
}
