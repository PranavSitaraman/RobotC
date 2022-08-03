const tMotor Lm = motorA;
const tMotor Rm = motorC;
const tSensors Eye = (tSensors) S1;
int table = 55;
int silver = 80;
int threshold = (table + silver)/2;
task main()
{
	SensorType[Eye] = sensorLightActive;
	while (SensorValue[Eye] < threshold)
	{
		motor[Lm] = motor[Rm] = 50;
	}
	motor[Lm] = motor[Rm] = 0;
}
