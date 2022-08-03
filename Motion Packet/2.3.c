tMotor leftMotor = motorA;
tMotor rightMotor = motorC;
task main()
{
	motor[leftMotor] = 100;
	motor[rightMotor] = -100;
	delay(3000);
	motor[leftMotor] = -100;
	motor[rightMotor] = 100;
	delay(3000);
}
