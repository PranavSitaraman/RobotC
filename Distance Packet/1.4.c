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
		delay(1800);
		motor[RM] = 50;
		motor[LM] = 50;
		delay(700);
		motor[LM] = 70;
		motor[RM] = 25;
		delay(3700);
		motor[RM] = 50;
		motor[LM] = 50;
		delay(800);
		motor[LM] = 70;
		motor[RM] = 25;
		delay(3700);
		motor[RM] = 50;
		motor[LM] = 50;
		delay(700);
		motor[RM] = 50;
		motor[LM] = -50;
		delay(1800);
	}
}
