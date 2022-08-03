const tMotor Lm = motorA;
const tMotor Rm = motorC;
const tSensors Bumper = (tSensors) S1;
task main()
{
	SensorType[Bumper] = sensorTouch;
	motor[Lm] = 50;
	motor[Rm] = 50;
	while (SensorValue[Bumper] == 0) delay(5);
	motor[Lm] = 0;
	motor[Rm] = 0;
	delay(2000);
}
