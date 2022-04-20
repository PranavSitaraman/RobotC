//B = LM
//C = RM
task main()
{
	int x = 1;
	int y = 1;
	float target = 360/(5.5 * 3.1415926535) * 16.5;
	while(y<=4)
	{
		nMotorEncoder[motorB] = 0;
		nMotorEncoder[motorC] = 0;
		while(nMotorEncoder[motorB] < target)
		{
			motor[motorB] = 50;
			motor[motorC] = 50;
		}
		if (x%2 == 1)
		{
			nMotorEncoder[motorB] = 90 * 2 * 18/5.5;
			motor[motorC] = 0;
		}
		else
		{
			motor[motorB] = 0;
			nMotorEncoder[motorC] = 90 * 2 * 18/5.5;
		}
		x=x + 1;

		y = y + 1;
	}
	nMotorEncoder[motorB] = 0;
	nMotorEncoder[motorC] = 0;
	motor[motorB] = 0;
	nMotorEncoder[motorC] = 90 * 2 * 18/5.5;
	while(nMotorEncoder[motorB] < 4 * target)
	{	motor[motorB] = 50;
		motor[motorC] = 50;
	}
}
