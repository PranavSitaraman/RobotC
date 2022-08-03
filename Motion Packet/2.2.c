tMotor leftMotor = motorA;
tMotor rightMotor = motorC;
task main()
{
	motor[leftMotor] = 100;
	motor[rightMotor] = 0;
	delay(3000);
	motor[leftMotor] = 0;
	motor[rightMotor] = -100;
	delay(3000);
	motor[rightMotor] = 100;
	motor[leftMotor] = 0;
	delay(3000);
	motor[rightMotor] = 0;
	motor[leftMotor] = -100;
	delay(3000);
}
