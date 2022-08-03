const tMotor Lm = motorA;
const tMotor Rm = motorC;
const tSensors Eye = (tSensors) S1;
int black = 50;
int white = 70;
int silver = 90;
int blackwhitethreshold = (black + white)/2;
int silverwhitethreshold = (silver + white)/2;
task main()
{
	SensorType[Eye] = sensorLightActive;
	while (true)
	{
		motor[Lm] = 50;
		motor[Rm] = 50;
		if (SensorValue[Eye] < blackwhitethreshold)
		{
			motor[Lm] = 50;
			motor[Rm] = -50;
			delay(1800);
		}
		else if (SensorValue[Eye] > silverwhitethreshold)
		{
			motor[Lm] = -50;
			motor[Rm] = 50;
			delay(1800);
		}
	}
}
