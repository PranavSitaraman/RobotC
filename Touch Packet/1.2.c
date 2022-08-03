const tMotor Lm = motorA;
const tMotor Rm = motorC;
const tSensors Bumper = (tSensors) S1;
task main()
{
	SensorType[Bumper] = sensorTouch;
	while (true)
	{
		motor[Lm] = 50;
		motor[Rm] = 50;
		while (SensorValue[Bumper] == 0) delay(5);
		motor[Lm] = motor[Rm] = -50;
		delay(500);
		motor[Rm] = 50;
		delay(700);
	}
}
