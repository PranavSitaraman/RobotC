#define EYE S1
#define LM motorA
#define RM motorB
const int Dist = 7;
task main()
{
	SensorType[EYE] = sensorSONAR;
	while (true)
	{
		motor[LM] = motor[RM] = 50;
		while (SensorValue[EYE] > Dist) delay(10);
		motor[LM] = motor[RM] = 0;
		playSound(soundBeepBeep);
		delay(500);
		motor[RM] = 50;
		motor[LM] = -50;
		delay(3600);
	}
}
