tMotor leftMotor = motorA;
tMotor rightMotor = motorC;
task main()
{
	while (1)
	{
		motor[leftMotor] = 50;
		motor[rightMotor] = 50;
		delay(3000);
		motor[leftMotor] = 0;
		motor[rightMotor] = 0;
		motor[leftMotor] = -50;
		motor[rightMotor] = -50;
		delay(3000);
	}
}
