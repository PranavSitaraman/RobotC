tMotor leftMotor = motorA;
tMotor rightMotor = motorC;
task main()
{
	int count = 0;
	while (++count)
	{
		motor[leftMotor] = 50;
		motor[rightMotor] = 50;
		delay(2000);
		motor[leftMotor] = 50 * ((count % 2) * 2 - 1);
		motor[rightMotor] = -50 * ((count % 2) * 2 - 1);
		delay(1800);
	}
}
