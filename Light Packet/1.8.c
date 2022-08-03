const tMotor Lm = motorA;
const tMotor Rm = motorC;
const tSensors Eye = (tSensors) S1;
int table = 55;
int cliff = 35;
int threshold = (table + cliff)/2;
int silver = 90;
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
		if (SensorValue[Eye] > threshold)
		{
			motor[Lm] = 50;
			motor[Rm] = 0;
		}
		else
		{
			motor[Lm] = 0;
			motor[Rm] = 50;
		}
	}
}
