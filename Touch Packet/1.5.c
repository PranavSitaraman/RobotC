const tMotor leftMotor = motorA;
const tMotor rightMotor = motorC;
const tSensors Bumper = (tSensors) S1;
task main()
{
	SensorType[Bumper] = sensorTouch;
	int count = 0;
	while (++count)
	{
		motor[leftMotor] = 50;
		motor[rightMotor] = 50;
		while (SensorValue[Bumper] == 0) delay(5);
		motor[leftMotor] = 50 * ((count % 2) * 2 - 1);
		motor[rightMotor] = -50 * ((count % 2) * 2 - 1);
		delay(1800);
	}
}
