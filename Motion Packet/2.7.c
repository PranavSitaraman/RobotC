tMotor leftMotor = motorA;
tMotor rightMotor = motorC;
task main()
{
	motor[leftMotor] = 100;
	motor[rightMotor] = -100;
	delay(1000);
	motor[leftMotor] = -100;
	motor[rightMotor] = 100;
	delay(2000);
	motor[leftMotor] = 100;
	motor[rightMotor] = -100;
	delay(1000);
	motor[leftMotor] = 0;
	motor[rightMotor] = 0;
}
