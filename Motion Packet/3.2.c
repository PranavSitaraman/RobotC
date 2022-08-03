tMotor leftMotor = motorA;
tMotor rightMotor = motorC;
task main()
{
	while (1)
	{
		motor[leftMotor] = 50;
		motor[rightMotor] = 50;
		delay(2000);
		motor[leftMotor] = 50;
		motor[rightMotor] = -50;
		delay(1800);
	}
}
