task main()
{
	float target = 360/(5.5 * 3.1415926535) * 16.25;
	nMotorEncoder[motorB] = 0;
		nMotorEncoder[motorC] = 0;
		while(nMotorEncoder[motorB] > (-1 * target))
		{
			motor[motorB] = -50;
			motor[motorC] = -50;
		}
		motor[motorB] = 0;
		nMotorEncoder[motorC] = 90 * 2 * 18/5.5;

}
