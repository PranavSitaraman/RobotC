tMotor leftMotor = motorA;
tMotor rightMotor = motorC;
task main()
{
	int count = 0;
	while (count < 4)
	{
		motor[leftMotor] = 50;
		motor[rightMotor] = 50;
		delay(2000);
		motor[leftMotor] = 50;
		motor[rightMotor] = -50;
		delay(1800);
		count++;
	}
}
