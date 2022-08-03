const tMotor Lm = motorA;
const tMotor Rm = motorC;
const tSensors Eye = (tSensors) S1;
int black = 55;
int white = 75;
int silver = 90;
int blackwhitethreshold = (black + white)/2;
task main()
{
	SensorType[Eye] = sensorLightActive;
	while (true)
	{
		if (SensorValue[Eye] > silver)
		{
			motor[Rm] = 0;
			motor[Lm] = 0;
			break;
		}
		if (SensorValue[Eye] < blackwhitethreshold)
		{
			motor[Rm] = 0;
			motor[Lm] = 50;
		}
		else
		{
			motor[Rm] = 50;
			motor[Lm] = 0;
		}
	}
}
