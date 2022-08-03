#define EYE S1
#define LM motorA
#define RM motorB
const int Dist = 7;
task main()
{
	SensorType[EYE] = sensorSONAR;
	motor[LM] = 50;
	motor[RM] = 50;
	while (SensorValue[EYE] > Dist) delay(5);
	motor[LM] = 0;
	motor[RM] = 0;
}
