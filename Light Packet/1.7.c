const tMotor Lm = motorA;
const tMotor Rm = motorC;
const tSensors Eye = (tSensors) S1;
int black = 50;
int white = 70;
int threshold = (black + white)/2;
task main()
{
	SensorType[Eye] = sensorLightActive;
	motor[Rm] = 50;
	motor[Lm] = 50;
	while (SensorValue[Eye] > threshold);
	motor[Rm] = 0;
	motor[Lm] = 0;
}
