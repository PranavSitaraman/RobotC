const tMotor Lm = motorA;
const tMotor Rm = motorC;
const tSensors Eye = (tSensors) S1;
int black = 47;
int white = 65;
int threshold = (black + white)/2;
task main()
{
	SensorType[Eye] = sensorLightActive;
	while (true)
	{
		if (SensorValue[Eye] < threshold)
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
