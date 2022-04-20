#pragma config(Sensor, S2,     colorSensor,    sensorEV3_Color, modeEV3Color_RGB_Raw)
#pragma config(Sensor, S3,     colorSensor,    sensorEV3_Color, modeEV3Color_RGB_Raw)
#pragma config(Sensor, S4,     sonarSensor,    sensorEV3_Ultrasonic)
#pragma config(Motor,  motorA,          mediumMotor,   tmotorEV3_Medium, PIDControl, encoder)
#pragma config(Motor,  motorB,          leftMotor,     tmotorEV3_Large, PIDControl, driveLeft, encoder)
#pragma config(Motor,  motorC,          rightMotor,    tmotorEV3_Large, PIDControl, driveRight, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()

{

	float error;

	float integral = 0.0;

	float integrallimit = 500.0;

	float derivative = 0.0;

	float lastError = 0.0;

	float turn;

	float powerB;

	float powerC;

	long x;

	float xvalue;

	long y;

	long z;

	long a;

	float avalue;

	long b;

	long c;

	float leftvalue = 42.0;

	float rightvalue = 40.0;

	float tar = leftvalue-rightvalue;

	float mt = 30.0;

	float Kp = 7.5;

	float Ki = 0.05;

	float Kd = 1.0;

	while (true)

	{

		getColorRGB(S2, x, y, z);

		getColorRGB(S3, a, b, c);

		xvalue = (float)(x);

		avalue = (float)(a);

		error = xvalue - avalue - tar;

		integral = integral+error;

		derivative = error-lastError;

		turn = (Kp*error)+(Ki*integral)+(Kd*derivative);

		powerB = mt+turn;

		powerC = mt-turn;

		motor[motorB] = powerB;

		motor[motorC] = powerC;

		lastError = error;

		if (integral > integrallimit)

		{

			integral = 0.0;

		}

		else

		{

			if (integral< 0.0 - integrallimit)

			{

				integral = 0.0;

			}

			else

			{

			}

		}

	}

}
