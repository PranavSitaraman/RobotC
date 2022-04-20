task main()
{
	float a[5];
	float b[5];
	a[0] = 22;
	a[1] = 44;
	a[2] = 66;
	a[3] = 88;
	a[4] = 110;
	b[0] = 88;
	b[1] = 44;
	b[2] = 66;
	b[3] = 22;
	b[4] = 44;
	// Sets a loop that runs 5 times (once for each "zombie" that needs to be "killed"
	int count = 0;
	while (count <=4)
	{
		// Resets the motors and the motor encoders
		nMotorEncoder[motorB] = 0;
		nMotorEncoder[motorC] = 0;
		motor[motorB] = 0;
		motor[motorC] = 0;
		delay(5000);
		// Uses the arctan to calculate how much the robot has to turn in order to face the object
		if (count == 0)
		{
			while(nMotorEncoder[motorB] < atan(b[count]/a[count]) * 180/PI * 2 * 16.7/5.5 - 20)
			{
				motor[motorB] = 25;
				motor[motorC] = 0;
			}
			nMotorEncoder[motorB] = 0;
			nMotorEncoder[motorC] = 0;
			// Uses the Pythagorean theorem to move the robot the distance that it needs to go in order to "kill" the "zombie"
			while(nMotorEncoder[motorB] < (sqrt(a[count] * a[count] + b[count] * b[count])) * 360/(5.5 * PI))
			{
				motor[motorB] = 25;
				motor[motorC] = 25;
			}
			nMotorEncoder[motorB] = 0;
			nMotorEncoder[motorC] = 0;
			count++;
		}
		else if (b[count] < b[count + 1])
		{
			delay(1000);
		}
		// Ends the program
	}
}
