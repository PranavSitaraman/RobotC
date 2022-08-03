const tMotor Lm = motorA;
const tMotor Rm = motorC;
const tSensors Eye = (tSensors) S1;
int ambient = 55;
int hand = 80;
int threshold = (ambient + hand)/2;
task main()
{
	SensorType[Eye] = sensorLightActive;
	while (true)
	{
		if (SensorValue[Eye] > threshold) motor[Lm] = motor[Rm] = 50;
		else	motor[Lm] = motor[Rm] = 0;
	}
}
