#pragma config(Sensor, S2,     colorSensor,    sensorEV3_Color, modeEV3Color_RGB_Raw)
#pragma config(Sensor, S3,     colorSensor,    sensorEV3_Color, modeEV3Color_RGB_Raw)
#pragma config(Sensor, S4,     sonarSensor,    sensorEV3_IRSensor)
#pragma config(Motor,  motorB,          leftMotor,     tmotorEV3_Large, PIDControl, driveLeft, encoder)
#pragma config(Motor,  motorC,          rightMotor,    tmotorEV3_Large, PIDControl, driveRight, encoder)
#include "global.h"
#include "utils.c"
task main()
{
	float Kp1;
	float motortarget1;
	while (true)
	{
		Kp1 = 0.5;
		motortarget1 = -20;
		sensorvalues();
		if (tardownlimit < xvalue - avalue && xvalue - avalue < taruplimit)
		{
			tar = xvalue - avalue;
		}
		else
		{
			tar = leftvalue - rightvalue;
		}
		error = xvalue - avalue - tar;
		turn = (Kp1 * error);
		if (error>55 || error<55)
		{
			powerB = motortarget1 - turn;
			powerC = motortarget1 + turn;
		}
		else
		{
			powerB = motortarget1 + turn;
			powerC = motortarget1 - turn;
		}
		motor[motorB] = powerB;
		motor[motorC] = powerC;
		lastError = error;
		if (integral > integraluplimit)
		{
			integral = integraltarget;
		}
		else
		{
			if (integral < integraldownlimit)
			{
				integral = integraltarget;
			}
			else
			{
			}
		}
		sensorvalues();
		findgreen();
	}
}
