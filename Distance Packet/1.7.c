#define EYE S1
#define LM motorA
#define RM motorB
const int Dist = 7;
task main()
{
	SensorType[EYE] = sensorSONAR;
	int count = 0;
	while (true)
	{
		motor[LM] = 50;
		motor[RM] = 50;
		while (SensorValue[EYE] > Dist) delay(10);
		if (count % 4 == 0 || count % 4 == 1)
		{
			motor[LM] = 50;
			motor[RM] = -50;
		}
		else
		{
			motor[LM] = -50;
			motor[RM] = 50;
		}
		delay(1800);
		count++;
	}
}
