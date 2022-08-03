#define EYE S1
#define LM motorA
#define RM motorB
const int Dist = 7;
int counter = 0;
task main()
{
	SensorType[EYE] = sensorSONAR;
	while (counter < 4)
	{
		motor[LM] = motor[RM] = 50;
		while (SensorValue[EYE] > Dist) delay(10);
		motor[LM] = motor[RM] = 0;
		playSound(soundBeepBeep);
		delay(500);
		motor[RM] = 50;
		motor[LM] = -50;
		delay(3600);
		counter++;
	}
}
