tMotor leftMotor = motorA;
tMotor rightMotor = motorC;
task main()
{
	motor[leftMotor] = 50;
	motor[rightMotor] = -50;
	delay(900);
	int count = 0;
	while (count < 4)
	{
		motor[leftMotor] = -50;
		motor[rightMotor] = 50;
		delay(1800);
		motor[leftMotor] = 50;
		motor[rightMotor] = -50;
		delay(1800);
		count++;
	}
	motor[leftMotor] = 0;
	motor[rightMotor] = 0;
	playImmediateTone(260, 50);
	delay(500);
}
