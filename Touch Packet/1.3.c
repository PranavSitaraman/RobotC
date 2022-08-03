const tMotor Lm = motorA;
const tMotor Rm = motorC;
const tSensors Bumper = (tSensors) S1;
task main()
{
	SensorType[Bumper] = sensorTouch;
	int ct = 0;
	while (true)
	{
		if (SensorValue[Bumper] == 1)
		{
			++ct;
			playSound(soundBlip);
			displayBigTextLine(3, "%d", ct);
			while (SensorValue[Bumper] == 1) delay(50);
		}
	}
	delay(2000);
}
