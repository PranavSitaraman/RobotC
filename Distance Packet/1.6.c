#define EYE S1
#define LM motorA
#define RM motorB
const int Dist = 7;
task main()
{
	SensorType[EYE] = sensorSONAR;
	int count = 0;
	while (++count)
	{
		motor[LM] = 50;
		motor[RM] = 50;
		while (SensorValue[EYE] > Dist) delay(10);
		motor[LM] = 50 * ((count % 2) * 2 - 1);
		motor[RM] = -50 * ((count % 2) * 2 - 1);
		delay(1800);
	}
}
