tMotor leftMotor = motorA;
tMotor rightMotor = motorC;
task main()
{
	int count = 0;
	while (count < 5)
	{
		motor[leftMotor] = 50;
		motor[rightMotor] = 50;
		delay(3000);
		motor[leftMotor] = 0;
		motor[rightMotor] = 0;
		motor[leftMotor] = -50;
		motor[rightMotor] = -50;
		delay(3000);
		count = count + 1;
	}
}
