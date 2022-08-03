tMotor leftMotor = motorA;
tMotor rightMotor = motorC;
task main()
{
	motor[leftMotor] = 100;
	motor[rightMotor] = 50;
	delay(3000);
	motor[leftMotor] = 0;
	motor[rightMotor] = 0;
	delay(3000);
}
