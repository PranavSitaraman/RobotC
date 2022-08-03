tMotor leftMotor = motorA;
tMotor rightMotor = motorC;
task main()
{
	motor[leftMotor] = 50;
	motor[rightMotor] = -50;
	delay(900);
	while (1)
	{
		motor[leftMotor] = -50;
		motor[rightMotor] = 50;
		delay(1800);
		motor[leftMotor] = 50;
		motor[rightMotor] = -50;
		delay(1800);
	}
}
