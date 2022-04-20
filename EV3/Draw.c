#pragma config(Sensor, S2,     colorSensor,    sensorEV3_Color, modeEV3Color_RGB_Raw)
#pragma config(Sensor, S3,     colorSensor,    sensorEV3_Color, modeEV3Color_RGB_Raw)
#pragma config(Sensor, S4,     sonarSensor,    sensorEV3_IRSensor)
#pragma config(Motor,  motorB,          leftMotor,     tmotorEV3_Large, PIDControl, driveLeft, encoder)
#pragma config(Motor,  motorC,          rightMotor,    tmotorEV3_Large, PIDControl, driveRight, encoder)
#include "global.h"
#include "utils.c"

task main()
{
	int cornercounter = 2;
	int entrancearray = 1;
	int exitarray = 2;
	int emptyarray = 0;
	int exit;
	int array[3][4] = {{0, 0, 0},{0, 0, 0},{0, 0, 0},{0, 0, 0}}; //sizeof(array) = 4*3*sizeof(int) sizeof(int) = 4
	int length;
	drawRect(29.66666, 51.2, 59.333333, 25.6);
	drawRect(29.66666, 76.8, 59.333333, 51.2);
	drawRect(29.66666, 102.4, 59.333333, 76.8);
	drawRect(59.33333, 51.2, 89, 25.6);
	drawRect(59.33333, 76.8, 89, 51.2);
	drawRect(59.33333, 102.4, 89, 76.8);
	drawRect(89, 51.2, 118.66666, 25.6);
	drawRect(89, 76.8, 118.66666, 51.2);
	drawRect(89, 102.4, 118.66666, 76.8);
	drawRect(118.66666, 51.2, 148.33333, 25.6);
	drawRect(118.66666, 76.8, 148.33333, 51.2);
	drawRect(118.66666, 102.4, 148.33333, 76.8);
	turnDegrees('s', 5.9055, motortarget, motortarget);
	resetmotors();
	array[0][0] = entrancearray;
	turnDegrees('l', turntarget, reversemotortarget, motortarget);
	if (SensorValue[S4] < walldistance)
	{
		startturndirection = 'l';
	}
	else
	{
		startturndirection = 'r';
	}
	resetmotors();
	turnDegrees('r', turntarget, motortarget, reversemotortarget);
	resetmotors();
	cornernumb += half;
	repeat(2)
	{
		while (nMotorEncoder[motorB] < circle/(wheeldiameter * PI) * 11.811)
		{
			motor[motorB] = motortarget;
			motor[motorC] = motortarget;
		}
		resetmotors();
		if (startturndirection == 'l')
		{
			turnDegrees('l', turntarget, reversemotortarget, motortarget);
		}
		else if (startturndirection == 'r')
		{
			turnDegrees('r', turntarget, motortarget, reversemotortarget);
		}
		if (SensorValue[S4] > walldistance)
		{
			exit = cornercounter;
			array[0][cornercounter - single] = exitarray;
		}
		else
		{
			array[0][cornercounter - single] = emptyarray;
		}
		cornercounter++;
		resetmotors();
		if (startturndirection == 'l')
		{
			turnDegrees('r', turntarget, motortarget, reversemotortarget);
		}
		else if (startturndirection == 'r')
		{
			turnDegrees('l', turntarget, reversemotortarget, motortarget);
		}
		resetmotors();
	}
	if (SensorValue[S4] < walldistance)
	{
		length = 3;
	}
	else
	{
		resetmotors();
		sensorvalues();
		findgreen();
		while (nMotorEncoder[motorB] < circle/(wheeldiameter * PI) * 11.811 && (l == no && r == no))
		{
			motor[motorB] = motortarget;
			motor[motorC] = motortarget;
			sensorvalues();
			findgreen();
		}
		resetmotors();
		if (l == yes || r == yes)
		{
			while (nMotorEncoder[motorB] > circle/(wheeldiameter * PI) * (0 - 5.9055))
			{
				motor[motorB] = reversemotortarget;
				motor[motorC] = reversemotortarget;
			}
			resetmotors();
			array[0][2] = exitarray;
			if (length == 3 && startturndirection == 'l')
			{
				fillEllipse(37.08333, 115.2, 51.91666, 89.6);
			}
			else if (length == 3 && startturndirection == 'r')
			{
				fillEllipse(126.08333, 115.2, 140.91666, 89.6);
			}
		}
		else
		{
			if (startturndirection == 'l')
			{
				turnDegrees('l', turntarget, reversemotortarget, motortarget);
			}
			else if (startturndirection == 'r')
			{
				turnDegrees('r', turntarget, motortarget, reversemotortarget);
			}
			if (SensorValue[S4] > walldistance)
			{
				exit = cornercounter;
				array[0][cornercounter - single] = exitarray;
			}
			else
			{
				array[0][cornercounter - single] = emptyarray;
			}
			resetmotors();
			if (startturndirection == 'l')
			{
				turnDegrees('r', turntarget, motortarget, reversemotortarget);
			}
			else if (startturndirection == 'r')
			{
				turnDegrees('l', turntarget, reversemotortarget, motortarget);
			}
			resetmotors();
			length = 4;
			if (SensorValue[S4] > walldistance)
			{
				array[0][3] = emptyarray;
				if (length == 4 && startturndirection == 'l')
				{
					fillEllipse(14.83333, 32, 44.5, 44.8);
				}
				else if (length == 4 && startturndirection == 'r')
				{
					fillEllipse(14.83333, 83.2, 44.5, 96);
				}
			}
		}
	}
	if (length == 4 && startturndirection == 'l')
	{
		drawRect(133.5, 32, 163.16666, 44.8);
		if (exit == 2)
		{
			fillEllipse(96.41666, 38.4, 111.25, 12.8);
		}
		else if (exit == 3)
		{
			fillEllipse(66.75, 38.4, 81.58333, 12.8);
		}
		else if (exit == 4)
		{
			fillEllipse(37.08333, 38.4, 51.91666, 12.8);
		}
	}
	else if (length == 4 && startturndirection == 'r')
	{
		drawRect(133.5, 83.2, 163.16666, 96);
		if (exit == 2)
		{
			fillEllipse(96.41666, 115.2, 111.25, 89.6);
		}
		else if (exit == 3)
		{
			fillEllipse(66.75, 115.2, 81.58333, 89.6);
		}
		else if (exit == 4)
		{
			fillEllipse(37.08333, 115.2, 51.91666, 89.6);
		}
	}
	else if (length == 3 && startturndirection == 'l')
	{
		drawRect(37.08333, 38.4, 51.91666, 12.8);
		if (exit == 2)
		{
			fillEllipse(14.83333, 70.4, 44.5, 57.6);
		}
		else if (exit == 3)
		{
			fillEllipse(14.83333, 96, 44.5, 83.2);
		}
	}
	else if (length == 3 && startturndirection == 'r')
	{
		drawRect(126.08333, 38.4, 140.91666, 12.8);
		if (exit == 2)
		{
			fillEllipse(133.5, 70.4, 163.16666, 57.6);
		}
		else if (exit == 3)
		{
			fillEllipse(133.5, 96, 163.16666, 83.2);
		}
	}
	for (int i = 0; i < sizeof(array)/sizeof(array[0]); i++)
	{
		for (int ii = 0; ii < sizeof(array[0])/sizeof(array[0][0]); ii++)
		{
			if(array[i][ii] == exitarray){
				eraseDisplay();
				displayTextLine(4, "%i, %i", i, ii);
				delay(10000);
			}
		}
	}
}
