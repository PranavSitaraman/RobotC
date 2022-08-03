const tMotor leftMotor = motorA;
const tMotor rightMotor = motorC;
const tSensors Bumper = (tSensors) S1;
task main()
{
	SensorType[Bumper] = sensorTouch;
	int count = 0;
	while (true)
	{
		motor[leftMotor] = 50;
		motor[rightMotor] = 50;
		while (SensorValue[Bumper] == 0) delay(5);
		if (count % 4 == 0 || count % 4 == 1)
		{
			motor[leftMotor] = 50;
			motor[rightMotor] = -50;
		}
		else
		{
			motor[leftMotor] = -50;
			motor[rightMotor] = 50;
		}
		delay(1800);
		count++;
	}
}
