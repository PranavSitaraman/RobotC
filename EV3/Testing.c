#include "global.h"
#include "utils.c"
void testing()
{
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
	resetmotors();
	turnDegrees('s', halfgrid, motortarget, motortarget);
	resetmotors();
	turnDegrees('l', turntarget, reversemotortarget, motortarget);
	resetmotors();
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
	while (nMotorEncoder[motorB] < circle/(wheeldiameter * PI) * grid)
	{
		motor[motorB] = motortarget;
		motor[motorC] = motortarget;
	}
	resetmotors();
	if (startturndirection == 'l')
	{
		resetmotors();
		turnDegrees('l', turntarget, reversemotortarget, motortarget);
		resetmotors();
	}
	else if (startturndirection == 'r')
	{
		resetmotors();
		turnDegrees('r', turntarget, motortarget, reversemotortarget);
		resetmotors();
	}
	sensorvalues();
	findgreen();
	if (SensorValue[S4] > walldistance)
	{
		resetmotors();
		while (nMotorEncoder[motorB] < circle/(wheeldiameter * PI) * grid && (l == no && r == no) && ((xvalue+yvalue+zvalue)/triple<silvervalue && (avalue+bvalue+cvalue)/triple<silvervalue))
		{
			motor[motorB] = motortarget;
			motor[motorC] = motortarget;
			sensorvalues();
			findgreen();
		}
		resetmotors();
		if (l == yes || r == yes)
		{
			resetmotors();
			while (nMotorEncoder[motorB] > circle/(wheeldiameter * PI) * (0 - halfgrid))
			{
				motor[motorB] = reversemotortarget;
				motor[motorC] = reversemotortarget;
			}
			resetmotors();
			exit = 2;
			array[0][1] = exitarray;
		}
		else if ((xvalue+yvalue+zvalue)/triple>=silvervalue || (avalue+bvalue+cvalue)/triple>=silvervalue)
		{
			resetmotors();
			while (nMotorEncoder[motorB] > circle/(wheeldiameter * PI) * (0 - halfgrid))
			{
				motor[motorB] = reversemotortarget;
				motor[motorC] = reversemotortarget;
			}
			resetmotors();
			entrance = 2;
			array[0][1] = entrancearray;
		}
	}
	else
	{
		array[0][1] = emptyarray;
	}
	if (startturndirection == 'l')
	{
		resetmotors();
		turnDegrees('r', turntarget, motortarget, reversemotortarget);
		resetmotors();
	}
	else if (startturndirection == 'r')
	{
		resetmotors();
		turnDegrees('l', turntarget, reversemotortarget, motortarget);
		resetmotors();
	}
	resetmotors();
	while (nMotorEncoder[motorB] < circle/(wheeldiameter * PI) * grid)
	{
		motor[motorB] = motortarget;
		motor[motorC] = motortarget;
	}
	resetmotors();
	if (startturndirection == 'l')
	{
		resetmotors();
		turnDegrees('l', turntarget, reversemotortarget, motortarget);
		resetmotors();
	}
	else if (startturndirection == 'r')
	{
		resetmotors();
		turnDegrees('r', turntarget, motortarget, reversemotortarget);
		resetmotors();
	}
	sensorvalues();
	findgreen();
	if (SensorValue[S4] > walldistance)
	{
		resetmotors();
		while (nMotorEncoder[motorB] < circle/(wheeldiameter * PI) * grid && (l == no && r == no) && ((xvalue+yvalue+zvalue)/triple<silvervalue && (avalue+bvalue+cvalue)/triple<silvervalue))
		{
			motor[motorB] = motortarget;
			motor[motorC] = motortarget;
			sensorvalues();
			findgreen();
		}
		resetmotors();
		if (l == yes || r == yes)
		{
			resetmotors();
			while (nMotorEncoder[motorB] > circle/(wheeldiameter * PI) * (0 - halfgrid))
			{
				motor[motorB] = reversemotortarget;
				motor[motorC] = reversemotortarget;
			}
			resetmotors();
			exit = 3;
			array[0][2] = exitarray;
		}
		else if ((xvalue+yvalue+zvalue)/triple>=silvervalue || (avalue+bvalue+cvalue)/triple>=silvervalue)
		{
			resetmotors();
			while (nMotorEncoder[motorB] > circle/(wheeldiameter * PI) * (0 - halfgrid))
			{
				motor[motorB] = reversemotortarget;
				motor[motorC] = reversemotortarget;
			}
			resetmotors();
			entrance = 3;
			array[0][2] = entrancearray;
		}
	}
	else
	{
		array[0][2] = emptyarray;
	}
	if (startturndirection == 'l')
	{
		resetmotors();
		turnDegrees('r', turntarget, motortarget, reversemotortarget);
		resetmotors();
	}
	else if (startturndirection == 'r')
	{
		resetmotors();
		turnDegrees('l', turntarget, reversemotortarget, motortarget);
		resetmotors();
	}
	if (SensorValue[S4] < walldistance)
	{
		length = 3;
	}
	else
	{
		sensorvalues();
		findgreen();
		resetmotors();
		while (nMotorEncoder[motorB] < circle/(wheeldiameter * PI) * grid && (l == no && r == no) && ((xvalue+yvalue+zvalue)/triple<silvervalue && (avalue+bvalue+cvalue)/triple<silvervalue))
		{
			motor[motorB] = motortarget;
			motor[motorC] = motortarget;
			sensorvalues();
			findgreen();
		}
		resetmotors();
		if (l == yes || r == yes)
		{
			resetmotors();
			while (nMotorEncoder[motorB] > circle/(wheeldiameter * PI) * (0 - halfgrid))
			{
				motor[motorB] = reversemotortarget;
				motor[motorC] = reversemotortarget;
			}
			resetmotors();
			array[0][2] = exitarray;
			if (length == 3 && startturndirection == 'l')
			{
				eraseEllipse(37.08333, 115.2, 51.91666, 89.6);
				drawEllipse(37.08333, 115.2, 51.91666, 89.6);
			}
			else if (length == 3 && startturndirection == 'r')
			{
				eraseEllipse(126.08333, 115.2, 140.91666, 89.6);
				drawEllipse(126.08333, 115.2, 140.91666, 89.6);
			}
		}
		else if ((xvalue+yvalue+zvalue)/triple>=silvervalue || (avalue+bvalue+cvalue)/triple>=silvervalue)
		{
			resetmotors();
			while (nMotorEncoder[motorB] > circle/(wheeldiameter * PI) * (0 - halfgrid))
			{
				motor[motorB] = reversemotortarget;
				motor[motorC] = reversemotortarget;
			}
			resetmotors();
			array[0][2] = entrancearray;
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
				resetmotors();
				turnDegrees('l', turntarget, reversemotortarget, motortarget);
				resetmotors();
			}
			else if (startturndirection == 'r')
			{
				resetmotors();
				turnDegrees('r', turntarget, motortarget, reversemotortarget);
				resetmotors();
			}
			sensorvalues();
			findgreen();
			if (SensorValue[S4] > walldistance)
			{
				resetmotors();
				while (nMotorEncoder[motorB] < circle/(wheeldiameter * PI) * grid && (l == no && r == no) && ((xvalue+yvalue+zvalue)/triple<silvervalue && (avalue+bvalue+cvalue)/triple<silvervalue))
				{
					motor[motorB] = motortarget;
					motor[motorC] = motortarget;
					sensorvalues();
					findgreen();
				}
				resetmotors();
				if (l == yes || r == yes)
				{
					resetmotors();
					while (nMotorEncoder[motorB] > circle/(wheeldiameter * PI) * (0 - halfgrid))
					{
						motor[motorB] = reversemotortarget;
						motor[motorC] = reversemotortarget;
					}
					resetmotors();
					exit = 4;
					array[0][3] = exitarray;
				}
				else if ((xvalue+yvalue+zvalue)/triple>=silvervalue || (avalue+bvalue+cvalue)/triple>=silvervalue)
				{
					resetmotors();
					while (nMotorEncoder[motorB] > circle/(wheeldiameter * PI) * (0 - halfgrid))
					{
						motor[motorB] = reversemotortarget;
						motor[motorC] = reversemotortarget;
					}
					resetmotors();
					entrance = 4;
					array[0][3] = entrancearray;
				}
			}
			else
			{
				array[0][3] = emptyarray;
			}
			if (startturndirection == 'l')
			{
				resetmotors();
				turnDegrees('r', turntarget, motortarget, reversemotortarget);
				resetmotors();
			}
			else if (startturndirection == 'r')
			{
				resetmotors();
				turnDegrees('l', turntarget, reversemotortarget, motortarget);
				resetmotors();
			}
			length = 4;
			sensorvalues();
			findgreen();
			if (SensorValue[S4] > walldistance)
			{
				resetmotors();
				while (nMotorEncoder[motorB] < circle/(wheeldiameter * PI) * grid && (l == no && r == no) && ((xvalue+yvalue+zvalue)/triple<silvervalue && (avalue+bvalue+cvalue)/triple<silvervalue))
				{
					motor[motorB] = motortarget;
					motor[motorC] = motortarget;
					sensorvalues();
					findgreen();
				}
				resetmotors();
				if (l == yes || r == yes)
				{
					resetmotors();
					while (nMotorEncoder[motorB] > circle/(wheeldiameter * PI) * (0 - halfgrid))
					{
						motor[motorB] = reversemotortarget;
						motor[motorC] = reversemotortarget;
					}
					resetmotors();
					array[0][3] = exitarray;
					if (length == 4 && startturndirection == 'l')
					{
						eraseEllipse(14.83333, 32, 44.5, 44.8);
						drawEllipse(14.83333, 32, 44.5, 44.8);
					}
					else if (length == 4 && startturndirection == 'r')
					{
						eraseEllipse(14.83333, 83.2, 44.5, 96);
						drawEllipse(14.83333, 83.2, 44.5, 96);
					}
				}
				else if ((xvalue+yvalue+zvalue)/triple>=silvervalue || (avalue+bvalue+cvalue)/triple>=silvervalue)
				{
					resetmotors();
					while (nMotorEncoder[motorB] > circle/(wheeldiameter * PI) * (0 - halfgrid))
					{
						motor[motorB] = reversemotortarget;
						motor[motorC] = reversemotortarget;
					}
					resetmotors();
					array[0][3] = entrancearray;
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
	}
	sensorvalues();
	if (xvalue<sensoraverage || avalue<sensoraverage)
	{
		triangle = yes;
	}
	else
	{
		triangle = no;
	}
	if (triangle == yes && length == 3)
	{
		array[0][2] = trianglearray;
	}
	else if (triangle == yes && length == 4)
	{
		array[0][3] = trianglearray;
	}
	if (length == 4 && startturndirection == 'l')
	{
		eraseRect(133.5, 32, 163.16666, 44.8);
		drawRect(133.5, 32, 163.16666, 44.8);
		if (exit == 2)
		{
			eraseEllipse(96.41666, 38.4, 111.25, 12.8);
			drawEllipse(96.41666, 38.4, 111.25, 12.8);
		}
		else if (exit == 3)
		{
			eraseEllipse(66.75, 38.4, 81.58333, 12.8);
			drawEllipse(66.75, 38.4, 81.58333, 12.8);
		}
		else if (exit == 4)
		{
			eraseEllipse(37.08333, 38.4, 51.91666, 12.8);
			drawEllipse(37.08333, 38.4, 51.91666, 12.8);
		}
		if (entrance == 2)
		{
			fillEllipse(96.41666, 38.4, 111.25, 12.8);
		}
		else if (entrance == 3)
		{
			fillEllipse(66.75, 38.4, 81.58333, 12.8);
		}
		else if (entrance == 4)
		{
			fillEllipse(37.08333, 38.4, 51.91666, 12.8);
		}
		if (triangle == yes)
		{
			drawLine(29.66666, 51.2, 59.333333, 25.6);
		}
	}
	else if (length == 4 && startturndirection == 'r')
	{
		eraseRect(133.5, 83.2, 163.16666, 96);
		drawRect(133.5, 83.2, 163.16666, 96);
		if (exit == 2)
		{
			eraseEllipse(96.41666, 115.2, 111.25, 89.6);
			drawEllipse(96.41666, 115.2, 111.25, 89.6);
		}
		else if (exit == 3)
		{
			eraseEllipse(66.75, 115.2, 81.58333, 89.6);
			drawEllipse(66.75, 115.2, 81.58333, 89.6);
		}
		else if (exit == 4)
		{
			eraseEllipse(37.08333, 115.2, 51.91666, 89.6);
			drawEllipse(37.08333, 115.2, 51.91666, 89.6);
		}
		if (entrance == 2)
		{
			fillEllipse(96.41666, 115.2, 111.25, 89.6);
		}
		else if (entrance == 3)
		{
			fillEllipse(66.75, 115.2, 81.58333, 89.6);
		}
		else if (entrance == 4)
		{
			fillEllipse(37.08333, 115.2, 51.91666, 89.6);
		}
		if (triangle == yes)
		{
			drawLine(29.66666, 76.8, 59.333333, 102.4);
		}
	}
	else if (length == 3 && startturndirection == 'l')
	{
		eraseRect(37.08333, 38.4, 51.91666, 12.8);
		drawRect(37.08333, 38.4, 51.91666, 12.8);
		if (exit == 2)
		{
			eraseEllipse(14.83333, 70.4, 44.5, 57.6);
			drawEllipse(14.83333, 70.4, 44.5, 57.6);
		}
		else if (exit == 3)
		{
			eraseEllipse(14.83333, 96, 44.5, 83.2);
			drawEllipse(14.83333, 96, 44.5, 83.2);
		}
		if (entrance == 2)
		{
			fillEllipse(14.83333, 70.4, 44.5, 57.6);
		}
		else if (entrance == 3)
		{
			fillEllipse(14.83333, 96, 44.5, 83.2);
		}
		if (triangle == yes)
		{
			drawLine(29.66666, 76.8, 59.333333, 102.4);
		}
	}
	else if (length == 3 && startturndirection == 'r')
	{
		eraseRect(126.08333, 38.4, 140.91666, 12.8);
		drawRect(126.08333, 38.4, 140.91666, 12.8);
		if (exit == 2)
		{
			eraseEllipse(133.5, 70.4, 163.16666, 57.6);
			drawEllipse(133.5, 70.4, 163.16666, 57.6);
		}
		else if (exit == 3)
		{
			eraseEllipse(133.5, 96, 163.16666, 83.2);
			drawEllipse(133.5, 96, 163.16666, 83.2);
		}
		if (entrance == 2)
		{
			fillEllipse(133.5, 70.4, 163.16666, 57.6);
		}
		else if (entrance == 3)
		{
			fillEllipse(133.5, 96, 163.16666, 83.2);
		}
		if (triangle == yes)
		{
			drawLine(118.66666, 102.4, 148.33333, 76.8);
		}
	}
	entrance = 0;
	exit = 0;
	triangle = no;
	resetmotors();
	if (length == 4)
	{
		if (startturndirection == 'l')
		{
			resetmotors();
			turnDegrees('r', turntarget, motortarget, reversemotortarget);
			resetmotors();
		}
		else if (startturndirection == 'r')
		{
			resetmotors();
			turnDegrees('l', turntarget, reversemotortarget, motortarget);
			resetmotors();
		}
		eraseDisplay();
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
		resetmotors();
		while (nMotorEncoder[motorB] < circle/(wheeldiameter * PI) * grid)
		{
			motor[motorB] = motortarget;
			motor[motorC] = motortarget;
		}
		resetmotors();
		if (startturndirection == 'l')
		{
			resetmotors();
			turnDegrees('l', turntarget, reversemotortarget, motortarget);
			resetmotors();
		}
		else if (startturndirection == 'r')
		{
			resetmotors();
			turnDegrees('r', turntarget, motortarget, reversemotortarget);
			resetmotors();
		}
		sensorvalues();
		findgreen();
		if (SensorValue[S4] > walldistance)
		{
			resetmotors();
			while (nMotorEncoder[motorB] < circle/(wheeldiameter * PI) * grid && (l == no && r == no) && ((xvalue+yvalue+zvalue)/triple<silvervalue && (avalue+bvalue+cvalue)/triple<silvervalue))
			{
				motor[motorB] = motortarget;
				motor[motorC] = motortarget;
				sensorvalues();
				findgreen();
			}
			resetmotors();
			if (l == yes || r == yes)
			{
				resetmotors();
				while (nMotorEncoder[motorB] > circle/(wheeldiameter * PI) * (0 - halfgrid))
				{
					motor[motorB] = reversemotortarget;
					motor[motorC] = reversemotortarget;
				}
				resetmotors();
				exit = 2;
				array[1][3] = exitarray;
			}
			else if ((xvalue+yvalue+zvalue)/triple>=silvervalue || (avalue+bvalue+cvalue)/triple>=silvervalue)
			{
				resetmotors();
				while (nMotorEncoder[motorB] > circle/(wheeldiameter * PI) * (0 - halfgrid))
				{
					motor[motorB] = reversemotortarget;
					motor[motorC] = reversemotortarget;
				}
				resetmotors();
				entrance = 2;
				array[1][3] = entrancearray;
			}
		}
		else
		{
			array[1][3] = emptyarray;
		}
		if (startturndirection == 'l')
		{
			resetmotors();
			turnDegrees('r', turntarget, motortarget, reversemotortarget);
			resetmotors();
		}
		else if (startturndirection == 'r')
		{
			resetmotors();
			turnDegrees('l', turntarget, reversemotortarget, motortarget);
			resetmotors();
		}
		resetmotors();
		while (nMotorEncoder[motorB] < circle/(wheeldiameter * PI) * grid)
		{
			motor[motorB] = motortarget;
			motor[motorC] = motortarget;
		}
		resetmotors();
		if (startturndirection == 'l')
		{
			resetmotors();
			turnDegrees('l', turntarget, reversemotortarget, motortarget);
			resetmotors();
		}
		else if (startturndirection == 'r')
		{
			resetmotors();
			turnDegrees('r', turntarget, motortarget, reversemotortarget);
			resetmotors();
		}
		sensorvalues();
		findgreen();
		if (SensorValue[S4] > walldistance)
		{
			resetmotors();
			while (nMotorEncoder[motorB] < circle/(wheeldiameter * PI) * grid && (l == no && r == no) && ((xvalue+yvalue+zvalue)/triple<silvervalue && (avalue+bvalue+cvalue)/triple<silvervalue))
			{
				motor[motorB] = motortarget;
				motor[motorC] = motortarget;
				sensorvalues();
				findgreen();
			}
			resetmotors();
			if (l == yes || r == yes)
			{
				resetmotors();
				while (nMotorEncoder[motorB] > circle/(wheeldiameter * PI) * (0 - halfgrid))
				{
					motor[motorB] = reversemotortarget;
					motor[motorC] = reversemotortarget;
				}
				resetmotors();
				exit = 3;
				array[2][3] = exitarray;
			}
			else if ((xvalue+yvalue+zvalue)/triple>=silvervalue || (avalue+bvalue+cvalue)/triple>=silvervalue)
			{
				resetmotors();
				while (nMotorEncoder[motorB] > circle/(wheeldiameter * PI) * (0 - halfgrid))
				{
					motor[motorB] = reversemotortarget;
					motor[motorC] = reversemotortarget;
				}
				resetmotors();
				entrance = 3;
				array[2][3] = entrancearray;
			}
		}
		else
		{
			array[2][3] = emptyarray;
		}
		if (startturndirection == 'l')
		{
			resetmotors();
			turnDegrees('r', turntarget, motortarget, reversemotortarget);
			resetmotors();
		}
		else if (startturndirection == 'r')
		{
			resetmotors();
			turnDegrees('l', turntarget, reversemotortarget, motortarget);
			resetmotors();
		}
		if (SensorValue[S4] < walldistance)
		{
			length = 3;
		}
		else
		{
			sensorvalues();
			findgreen();
			resetmotors();
			while (nMotorEncoder[motorB] < circle/(wheeldiameter * PI) * grid && (l == no && r == no) && ((xvalue+yvalue+zvalue)/triple<silvervalue && (avalue+bvalue+cvalue)/triple<silvervalue))
			{
				motor[motorB] = motortarget;
				motor[motorC] = motortarget;
				sensorvalues();
				findgreen();
			}
			resetmotors();
			if (l == yes || r == yes)
			{
				resetmotors();
				while (nMotorEncoder[motorB] > circle/(wheeldiameter * PI) * (0 - halfgrid))
				{
					motor[motorB] = reversemotortarget;
					motor[motorC] = reversemotortarget;
				}
				resetmotors();
				array[2][3] = exitarray;
				if (length == 3 && startturndirection == 'l')
				{
					eraseEllipse(37.08333, 115.2, 51.91666, 89.6);
					drawEllipse(37.08333, 115.2, 51.91666, 89.6);
				}
				else if (length == 3 && startturndirection == 'r')
				{
					eraseEllipse(126.08333, 115.2, 140.91666, 89.6);
					drawEllipse(126.08333, 115.2, 140.91666, 89.6);
				}
			}
			else if ((xvalue+yvalue+zvalue)/triple>=silvervalue || (avalue+bvalue+cvalue)/triple>=silvervalue)
			{
				resetmotors();
				while (nMotorEncoder[motorB] > circle/(wheeldiameter * PI) * (0 - halfgrid))
				{
					motor[motorB] = reversemotortarget;
					motor[motorC] = reversemotortarget;
				}
				resetmotors();
				array[2][3] = entrancearray;
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
					resetmotors();
					turnDegrees('l', turntarget, reversemotortarget, motortarget);
					resetmotors();
				}
				else if (startturndirection == 'r')
				{
					resetmotors();
					turnDegrees('r', turntarget, motortarget, reversemotortarget);
					resetmotors();
				}
				sensorvalues();
				findgreen();
				if (SensorValue[S4] > walldistance)
				{
					resetmotors();
					while (nMotorEncoder[motorB] < circle/(wheeldiameter * PI) * grid && (l == no && r == no) && ((xvalue+yvalue+zvalue)/triple<silvervalue && (avalue+bvalue+cvalue)/triple<silvervalue))
					{
						motor[motorB] = motortarget;
						motor[motorC] = motortarget;
						sensorvalues();
						findgreen();
					}
					resetmotors();
					if (l == yes || r == yes)
					{
						resetmotors();
						while (nMotorEncoder[motorB] > circle/(wheeldiameter * PI) * (0 - halfgrid))
						{
							motor[motorB] = reversemotortarget;
							motor[motorC] = reversemotortarget;
						}
						resetmotors();
						exit = 4;
						array[3][3] = exitarray;
					}
					else if ((xvalue+yvalue+zvalue)/triple>=silvervalue || (avalue+bvalue+cvalue)/triple>=silvervalue)
					{
						resetmotors();
						while (nMotorEncoder[motorB] > circle/(wheeldiameter * PI) * (0 - halfgrid))
						{
							motor[motorB] = reversemotortarget;
							motor[motorC] = reversemotortarget;
						}
						resetmotors();
						entrance = 4;
						array[3][3] = entrancearray;
					}
				}
				else
				{
					array[3][3] = emptyarray;
				}
				if (startturndirection == 'l')
				{
					resetmotors();
					turnDegrees('r', turntarget, motortarget, reversemotortarget);
					resetmotors();
				}
				else if (startturndirection == 'r')
				{
					resetmotors();
					turnDegrees('l', turntarget, reversemotortarget, motortarget);
					resetmotors();
				}
				length = 4;
				sensorvalues();
				findgreen();
				if (SensorValue[S4] > walldistance)
				{
					resetmotors();
					while (nMotorEncoder[motorB] < circle/(wheeldiameter * PI) * grid && (l == no && r == no) && ((xvalue+yvalue+zvalue)/triple<silvervalue && (avalue+bvalue+cvalue)/triple<silvervalue))
					{
						motor[motorB] = motortarget;
						motor[motorC] = motortarget;
						sensorvalues();
						findgreen();
					}
					resetmotors();
					if (l == yes || r == yes)
					{
						resetmotors();
						while (nMotorEncoder[motorB] > circle/(wheeldiameter * PI) * (0 - halfgrid))
						{
							motor[motorB] = reversemotortarget;
							motor[motorC] = reversemotortarget;
						}
						resetmotors();
						array[3][3] = exitarray;
						if (length == 4 && startturndirection == 'l')
						{
							eraseEllipse(14.83333, 32, 44.5, 44.8);
							drawEllipse(14.83333, 32, 44.5, 44.8);
						}
						else if (length == 4 && startturndirection == 'r')
						{
							eraseEllipse(14.83333, 83.2, 44.5, 96);
							drawEllipse(14.83333, 83.2, 44.5, 96);
						}
					}
					else if ((xvalue+yvalue+zvalue)/triple>=silvervalue || (avalue+bvalue+cvalue)/triple>=silvervalue)
					{
						resetmotors();
						while (nMotorEncoder[motorB] > circle/(wheeldiameter * PI) * (0 - halfgrid))
						{
							motor[motorB] = reversemotortarget;
							motor[motorC] = reversemotortarget;
						}
						resetmotors();
						array[3][3] = entrancearray;
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
		}
		sensorvalues();
		if (xvalue<sensoraverage || avalue<sensoraverage)
		{
			triangle = yes;
		}
		else
		{
			triangle = no;
		}
		if (triangle == yes && length == 3)
		{
			array[2][3] = trianglearray;
		}
		else if (triangle == yes && length == 4)
		{
			array[3][3] = trianglearray;
		}
		if (length == 4 && startturndirection == 'l')
		{
			eraseRect(133.5, 32, 163.16666, 44.8);
			drawRect(133.5, 32, 163.16666, 44.8);
			if (exit == 2)
			{
				eraseEllipse(96.41666, 38.4, 111.25, 12.8);
				drawEllipse(96.41666, 38.4, 111.25, 12.8);
			}
			else if (exit == 3)
			{
				eraseEllipse(66.75, 38.4, 81.58333, 12.8);
				drawEllipse(66.75, 38.4, 81.58333, 12.8);
			}
			else if (exit == 4)
			{
				eraseEllipse(37.08333, 38.4, 51.91666, 12.8);
				drawEllipse(37.08333, 38.4, 51.91666, 12.8);
			}
			if (entrance == 2)
			{
				fillEllipse(96.41666, 38.4, 111.25, 12.8);
			}
			else if (entrance == 3)
			{
				fillEllipse(66.75, 38.4, 81.58333, 12.8);
			}
			else if (entrance == 4)
			{
				fillEllipse(37.08333, 38.4, 51.91666, 12.8);
			}
			if (triangle == yes)
			{
				drawLine(29.66666, 51.2, 59.333333, 25.6);
			}
		}
		else if (length == 4 && startturndirection == 'r')
		{
			eraseRect(133.5, 83.2, 163.16666, 96);
			drawRect(133.5, 83.2, 163.16666, 96);
			if (exit == 2)
			{
				eraseEllipse(96.41666, 115.2, 111.25, 89.6);
				drawEllipse(96.41666, 115.2, 111.25, 89.6);
			}
			else if (exit == 3)
			{
				eraseEllipse(66.75, 115.2, 81.58333, 89.6);
				drawEllipse(66.75, 115.2, 81.58333, 89.6);
			}
			else if (exit == 4)
			{
				eraseEllipse(37.08333, 115.2, 51.91666, 89.6);
				drawEllipse(37.08333, 115.2, 51.91666, 89.6);
			}
			if (entrance == 2)
			{
				fillEllipse(96.41666, 115.2, 111.25, 89.6);
			}
			else if (entrance == 3)
			{
				fillEllipse(66.75, 115.2, 81.58333, 89.6);
			}
			else if (entrance == 4)
			{
				fillEllipse(37.08333, 115.2, 51.91666, 89.6);
			}
			if (triangle == yes)
			{
				drawLine(29.66666, 76.8, 59.333333, 102.4);
			}
		}
		else if (length == 3 && startturndirection == 'l')
		{
			eraseRect(37.08333, 38.4, 51.91666, 12.8);
			drawRect(37.08333, 38.4, 51.91666, 12.8);
			if (exit == 2)
			{
				eraseEllipse(14.83333, 70.4, 44.5, 57.6);
				drawEllipse(14.83333, 70.4, 44.5, 57.6);
			}
			else if (exit == 3)
			{
				eraseEllipse(14.83333, 96, 44.5, 83.2);
				drawEllipse(14.83333, 96, 44.5, 83.2);
			}
			if (entrance == 2)
			{
				fillEllipse(14.83333, 70.4, 44.5, 57.6);
			}
			else if (entrance == 3)
			{
				fillEllipse(14.83333, 96, 44.5, 83.2);
			}
			if (triangle == yes)
			{
				drawLine(29.66666, 76.8, 59.333333, 102.4);
			}
		}
		else if (length == 3 && startturndirection == 'r')
		{
			eraseRect(126.08333, 38.4, 140.91666, 12.8);
			drawRect(126.08333, 38.4, 140.91666, 12.8);
			if (exit == 2)
			{
				eraseEllipse(133.5, 70.4, 163.16666, 57.6);
				drawEllipse(133.5, 70.4, 163.16666, 57.6);
			}
			else if (exit == 3)
			{
				eraseEllipse(133.5, 96, 163.16666, 83.2);
				drawEllipse(133.5, 96, 163.16666, 83.2);
			}
			if (entrance == 2)
			{
				fillEllipse(133.5, 70.4, 163.16666, 57.6);
			}
			else if (entrance == 3)
			{
				fillEllipse(133.5, 96, 163.16666, 83.2);
			}
			if (triangle == yes)
			{
				drawLine(118.66666, 102.4, 148.33333, 76.8);
			}
		}
		entrance = 0;
		exit = 0;
		triangle = no;
		resetmotors();
		if (startturndirection == 'l')
		{
			resetmotors();
			turnDegrees('r', turntarget, motortarget, reversemotortarget);
			resetmotors();
		}
		else if (startturndirection == 'r')
		{
			resetmotors();
			turnDegrees('l', turntarget, reversemotortarget, motortarget);
			resetmotors();
		}
		eraseDisplay();
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
		resetmotors();
		while (nMotorEncoder[motorB] < circle/(wheeldiameter * PI) * grid)
		{
			motor[motorB] = motortarget;
			motor[motorC] = motortarget;
		}
		resetmotors();
		if (startturndirection == 'l')
		{
			resetmotors();
			turnDegrees('l', turntarget, reversemotortarget, motortarget);
			resetmotors();
		}
		else if (startturndirection == 'r')
		{
			resetmotors();
			turnDegrees('r', turntarget, motortarget, reversemotortarget);
			resetmotors();
		}
		sensorvalues();
		findgreen();
		if (SensorValue[S4] > walldistance)
		{
			resetmotors();
			while (nMotorEncoder[motorB] < circle/(wheeldiameter * PI) * grid && (l == no && r == no) && ((xvalue+yvalue+zvalue)/triple<silvervalue && (avalue+bvalue+cvalue)/triple<silvervalue))
			{
				motor[motorB] = motortarget;
				motor[motorC] = motortarget;
				sensorvalues();
				findgreen();
			}
			resetmotors();
			if (l == yes || r == yes)
			{
				resetmotors();
				while (nMotorEncoder[motorB] > circle/(wheeldiameter * PI) * (0 - halfgrid))
				{
					motor[motorB] = reversemotortarget;
					motor[motorC] = reversemotortarget;
				}
				resetmotors();
				exit = 2;
				array[2][2] = exitarray;
			}
			else if ((xvalue+yvalue+zvalue)/triple>=silvervalue || (avalue+bvalue+cvalue)/triple>=silvervalue)
			{
				resetmotors();
				while (nMotorEncoder[motorB] > circle/(wheeldiameter * PI) * (0 - halfgrid))
				{
					motor[motorB] = reversemotortarget;
					motor[motorC] = reversemotortarget;
				}
				resetmotors();
				entrance = 2;
				array[2][2] = entrancearray;
			}
		}
		else
		{
			array[2][2] = emptyarray;
		}
		if (startturndirection == 'l')
		{
			resetmotors();
			turnDegrees('r', turntarget, motortarget, reversemotortarget);
			resetmotors();
		}
		else if (startturndirection == 'r')
		{
			resetmotors();
			turnDegrees('l', turntarget, reversemotortarget, motortarget);
			resetmotors();
		}
		resetmotors();
		while (nMotorEncoder[motorB] < circle/(wheeldiameter * PI) * grid)
		{
			motor[motorB] = motortarget;
			motor[motorC] = motortarget;
		}
		resetmotors();
		if (startturndirection == 'l')
		{
			resetmotors();
			turnDegrees('l', turntarget, reversemotortarget, motortarget);
			resetmotors();
		}
		else if (startturndirection == 'r')
		{
			resetmotors();
			turnDegrees('r', turntarget, motortarget, reversemotortarget);
			resetmotors();
		}
		sensorvalues();
		findgreen();
		if (SensorValue[S4] > walldistance)
		{
			resetmotors();
			while (nMotorEncoder[motorB] < circle/(wheeldiameter * PI) * grid && (l == no && r == no) && ((xvalue+yvalue+zvalue)/triple<silvervalue && (avalue+bvalue+cvalue)/triple<silvervalue))
			{
				motor[motorB] = motortarget;
				motor[motorC] = motortarget;
				sensorvalues();
				findgreen();
			}
			resetmotors();
			if (l == yes || r == yes)
			{
				resetmotors();
				while (nMotorEncoder[motorB] > circle/(wheeldiameter * PI) * (0 - halfgrid))
				{
					motor[motorB] = reversemotortarget;
					motor[motorC] = reversemotortarget;
				}
				resetmotors();
				exit = 3;
				array[2][1] = exitarray;
			}
			else if ((xvalue+yvalue+zvalue)/triple>=silvervalue || (avalue+bvalue+cvalue)/triple>=silvervalue)
			{
				resetmotors();
				while (nMotorEncoder[motorB] > circle/(wheeldiameter * PI) * (0 - halfgrid))
				{
					motor[motorB] = reversemotortarget;
					motor[motorC] = reversemotortarget;
				}
				resetmotors();
				entrance = 3;
				array[2][1] = entrancearray;
			}
		}
		else
		{
			array[2][1] = emptyarray;
		}
		if (startturndirection == 'l')
		{
			resetmotors();
			turnDegrees('r', turntarget, motortarget, reversemotortarget);
			resetmotors();
		}
		else if (startturndirection == 'r')
		{
			resetmotors();
			turnDegrees('l', turntarget, reversemotortarget, motortarget);
			resetmotors();
		}
		if (SensorValue[S4] < walldistance)
		{
			length = 3;
		}
		else
		{
			sensorvalues();
			findgreen();
			resetmotors();
			while (nMotorEncoder[motorB] < circle/(wheeldiameter * PI) * grid && (l == no && r == no) && ((xvalue+yvalue+zvalue)/triple<silvervalue && (avalue+bvalue+cvalue)/triple<silvervalue))
			{
				motor[motorB] = motortarget;
				motor[motorC] = motortarget;
				sensorvalues();
				findgreen();
			}
			resetmotors();
			if (l == yes || r == yes)
			{
				resetmotors();
				while (nMotorEncoder[motorB] > circle/(wheeldiameter * PI) * (0 - halfgrid))
				{
					motor[motorB] = reversemotortarget;
					motor[motorC] = reversemotortarget;
				}
				resetmotors();
				array[2][1] = exitarray;
				if (length == 3 && startturndirection == 'l')
				{
					eraseEllipse(37.08333, 115.2, 51.91666, 89.6);
					drawEllipse(37.08333, 115.2, 51.91666, 89.6);
				}
				else if (length == 3 && startturndirection == 'r')
				{
					eraseEllipse(126.08333, 115.2, 140.91666, 89.6);
					drawEllipse(126.08333, 115.2, 140.91666, 89.6);
				}
			}
			else if ((xvalue+yvalue+zvalue)/triple>=silvervalue || (avalue+bvalue+cvalue)/triple>=silvervalue)
			{
				resetmotors();
				while (nMotorEncoder[motorB] > circle/(wheeldiameter * PI) * (0 - halfgrid))
				{
					motor[motorB] = reversemotortarget;
					motor[motorC] = reversemotortarget;
				}
				resetmotors();
				array[2][1] = entrancearray;
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
					resetmotors();
					turnDegrees('l', turntarget, reversemotortarget, motortarget);
					resetmotors();
				}
				else if (startturndirection == 'r')
				{
					resetmotors();
					turnDegrees('r', turntarget, motortarget, reversemotortarget);
					resetmotors();
				}
				sensorvalues();
				findgreen();
				if (SensorValue[S4] > walldistance)
				{
					resetmotors();
					while (nMotorEncoder[motorB] < circle/(wheeldiameter * PI) * grid && (l == no && r == no) && ((xvalue+yvalue+zvalue)/triple<silvervalue && (avalue+bvalue+cvalue)/triple<silvervalue))
					{
						motor[motorB] = motortarget;
						motor[motorC] = motortarget;
						sensorvalues();
						findgreen();
					}
					resetmotors();
					if (l == yes || r == yes)
					{
						resetmotors();
						while (nMotorEncoder[motorB] > circle/(wheeldiameter * PI) * (0 - halfgrid))
						{
							motor[motorB] = reversemotortarget;
							motor[motorC] = reversemotortarget;
						}
						resetmotors();
						exit = 4;
						array[2][0] = exitarray;
					}
					else if ((xvalue+yvalue+zvalue)/triple>=silvervalue || (avalue+bvalue+cvalue)/triple>=silvervalue)
					{
						resetmotors();
						while (nMotorEncoder[motorB] > circle/(wheeldiameter * PI) * (0 - halfgrid))
						{
							motor[motorB] = reversemotortarget;
							motor[motorC] = reversemotortarget;
						}
						resetmotors();
						entrance = 4;
						array[2][0] = entrancearray;
					}
				}
				else
				{
					array[2][0] = emptyarray;
				}
				if (startturndirection == 'l')
				{
					resetmotors();
					turnDegrees('r', turntarget, motortarget, reversemotortarget);
					resetmotors();
				}
				else if (startturndirection == 'r')
				{
					resetmotors();
					turnDegrees('l', turntarget, reversemotortarget, motortarget);
					resetmotors();
				}
				length = 4;
				sensorvalues();
				findgreen();
				if (SensorValue[S4] > walldistance)
				{
					resetmotors();
					while (nMotorEncoder[motorB] < circle/(wheeldiameter * PI) * grid && (l == no && r == no) && ((xvalue+yvalue+zvalue)/triple<silvervalue && (avalue+bvalue+cvalue)/triple<silvervalue))
					{
						motor[motorB] = motortarget;
						motor[motorC] = motortarget;
						sensorvalues();
						findgreen();
					}
					resetmotors();
					if (l == yes || r == yes)
					{
						resetmotors();
						while (nMotorEncoder[motorB] > circle/(wheeldiameter * PI) * (0 - halfgrid))
						{
							motor[motorB] = reversemotortarget;
							motor[motorC] = reversemotortarget;
						}
						resetmotors();
						array[2][0] = exitarray;
						if (length == 4 && startturndirection == 'l')
						{
							eraseEllipse(14.83333, 32, 44.5, 44.8);
							drawEllipse(14.83333, 32, 44.5, 44.8);
						}
						else if (length == 4 && startturndirection == 'r')
						{
							eraseEllipse(14.83333, 83.2, 44.5, 96);
							drawEllipse(14.83333, 83.2, 44.5, 96);
						}
					}
					else if ((xvalue+yvalue+zvalue)/triple>=silvervalue || (avalue+bvalue+cvalue)/triple>=silvervalue)
					{
						resetmotors();
						while (nMotorEncoder[motorB] > circle/(wheeldiameter * PI) * (0 - halfgrid))
						{
							motor[motorB] = reversemotortarget;
							motor[motorC] = reversemotortarget;
						}
						resetmotors();
						array[2][0] = entrancearray;
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
		}
		sensorvalues();
		if (xvalue<sensoraverage || avalue<sensoraverage)
		{
			triangle = yes;
		}
		else
		{
			triangle = no;
		}
		if (triangle == yes && length == 3)
		{
			array[2][1] = trianglearray;
		}
		else if (triangle == yes && length == 4)
		{
			array[2][0] = trianglearray;
		}
		if (length == 4 && startturndirection == 'l')
		{
			eraseRect(133.5, 32, 163.16666, 44.8);
			drawRect(133.5, 32, 163.16666, 44.8);
			if (exit == 2)
			{
				eraseEllipse(96.41666, 38.4, 111.25, 12.8);
				drawEllipse(96.41666, 38.4, 111.25, 12.8);
			}
			else if (exit == 3)
			{
				eraseEllipse(66.75, 38.4, 81.58333, 12.8);
				drawEllipse(66.75, 38.4, 81.58333, 12.8);
			}
			else if (exit == 4)
			{
				eraseEllipse(37.08333, 38.4, 51.91666, 12.8);
				drawEllipse(37.08333, 38.4, 51.91666, 12.8);
			}
			if (entrance == 2)
			{
				fillEllipse(96.41666, 38.4, 111.25, 12.8);
			}
			else if (entrance == 3)
			{
				fillEllipse(66.75, 38.4, 81.58333, 12.8);
			}
			else if (entrance == 4)
			{
				fillEllipse(37.08333, 38.4, 51.91666, 12.8);
			}
			if (triangle == yes)
			{
				drawLine(29.66666, 51.2, 59.333333, 25.6);
			}
		}
		else if (length == 4 && startturndirection == 'r')
		{
			eraseRect(133.5, 83.2, 163.16666, 96);
			drawRect(133.5, 83.2, 163.16666, 96);
			if (exit == 2)
			{
				eraseEllipse(96.41666, 115.2, 111.25, 89.6);
				drawEllipse(96.41666, 115.2, 111.25, 89.6);
			}
			else if (exit == 3)
			{
				eraseEllipse(66.75, 115.2, 81.58333, 89.6);
				drawEllipse(66.75, 115.2, 81.58333, 89.6);
			}
			else if (exit == 4)
			{
				eraseEllipse(37.08333, 115.2, 51.91666, 89.6);
				drawEllipse(37.08333, 115.2, 51.91666, 89.6);
			}
			if (entrance == 2)
			{
				fillEllipse(96.41666, 115.2, 111.25, 89.6);
			}
			else if (entrance == 3)
			{
				fillEllipse(66.75, 115.2, 81.58333, 89.6);
			}
			else if (entrance == 4)
			{
				fillEllipse(37.08333, 115.2, 51.91666, 89.6);
			}
			if (triangle == yes)
			{
				drawLine(29.66666, 76.8, 59.333333, 102.4);
			}
		}
		else if (length == 3 && startturndirection == 'l')
		{
			eraseRect(37.08333, 38.4, 51.91666, 12.8);
			drawRect(37.08333, 38.4, 51.91666, 12.8);
			if (exit == 2)
			{
				eraseEllipse(14.83333, 70.4, 44.5, 57.6);
				drawEllipse(14.83333, 70.4, 44.5, 57.6);
			}
			else if (exit == 3)
			{
				eraseEllipse(14.83333, 96, 44.5, 83.2);
				drawEllipse(14.83333, 96, 44.5, 83.2);
			}
			if (entrance == 2)
			{
				fillEllipse(14.83333, 70.4, 44.5, 57.6);
			}
			else if (entrance == 3)
			{
				fillEllipse(14.83333, 96, 44.5, 83.2);
			}
			if (triangle == yes)
			{
				drawLine(29.66666, 76.8, 59.333333, 102.4);
			}
		}
		else if (length == 3 && startturndirection == 'r')
		{
			eraseRect(126.08333, 38.4, 140.91666, 12.8);
			drawRect(126.08333, 38.4, 140.91666, 12.8);
			if (exit == 2)
			{
				eraseEllipse(133.5, 70.4, 163.16666, 57.6);
				drawEllipse(133.5, 70.4, 163.16666, 57.6);
			}
			else if (exit == 3)
			{
				eraseEllipse(133.5, 96, 163.16666, 83.2);
				drawEllipse(133.5, 96, 163.16666, 83.2);
			}
			if (entrance == 2)
			{
				fillEllipse(133.5, 70.4, 163.16666, 57.6);
			}
			else if (entrance == 3)
			{
				fillEllipse(133.5, 96, 163.16666, 83.2);
			}
			if (triangle == yes)
			{
				drawLine(118.66666, 102.4, 148.33333, 76.8);
			}
		}
		entrance = 0;
		exit = 0;
		triangle = no;
		resetmotors();
		if (startturndirection == 'l')
		{
			resetmotors();
			turnDegrees('r', turntarget, motortarget, reversemotortarget);
			resetmotors();
		}
		else if (startturndirection == 'r')
		{
			resetmotors();
			turnDegrees('l', turntarget, reversemotortarget, motortarget);
			resetmotors();
		}
		eraseDisplay();
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
		resetmotors();
		while (nMotorEncoder[motorB] < circle/(wheeldiameter * PI) * grid)
		{
			motor[motorB] = motortarget;
			motor[motorC] = motortarget;
		}
		resetmotors();
		if (startturndirection == 'l')
		{
			resetmotors();
			turnDegrees('l', turntarget, reversemotortarget, motortarget);
			resetmotors();
		}
		else if (startturndirection == 'r')
		{
			resetmotors();
			turnDegrees('r', turntarget, motortarget, reversemotortarget);
			resetmotors();
		}
		sensorvalues();
		findgreen();
		if (SensorValue[S4] > walldistance)
		{
			resetmotors();
			while (nMotorEncoder[motorB] < circle/(wheeldiameter * PI) * grid && (l == no && r == no) && ((xvalue+yvalue+zvalue)/triple<silvervalue && (avalue+bvalue+cvalue)/triple<silvervalue))
			{
				motor[motorB] = motortarget;
				motor[motorC] = motortarget;
				sensorvalues();
				findgreen();
			}
			resetmotors();
			if (l == yes || r == yes)
			{
				resetmotors();
				while (nMotorEncoder[motorB] > circle/(wheeldiameter * PI) * (0 - halfgrid))
				{
					motor[motorB] = reversemotortarget;
					motor[motorC] = reversemotortarget;
				}
				resetmotors();
				exit = 2;
				array[1][0] = exitarray;
			}
			else if ((xvalue+yvalue+zvalue)/triple>=silvervalue || (avalue+bvalue+cvalue)/triple>=silvervalue)
			{
				resetmotors();
				while (nMotorEncoder[motorB] > circle/(wheeldiameter * PI) * (0 - halfgrid))
				{
					motor[motorB] = reversemotortarget;
					motor[motorC] = reversemotortarget;
				}
				resetmotors();
				entrance = 2;
				array[1][0] = entrancearray;
			}
		}
		else
		{
			array[1][0] = emptyarray;
		}
		if (startturndirection == 'l')
		{
			resetmotors();
			turnDegrees('r', turntarget, motortarget, reversemotortarget);
			resetmotors();
		}
		else if (startturndirection == 'r')
		{
			resetmotors();
			turnDegrees('l', turntarget, reversemotortarget, motortarget);
			resetmotors();
		}
		resetmotors();
		while (nMotorEncoder[motorB] < circle/(wheeldiameter * PI) * grid)
		{
			motor[motorB] = motortarget;
			motor[motorC] = motortarget;
		}
		resetmotors();
		if (startturndirection == 'l')
		{
			resetmotors();
			turnDegrees('l', turntarget, reversemotortarget, motortarget);
			resetmotors();
		}
		else if (startturndirection == 'r')
		{
			resetmotors();
			turnDegrees('r', turntarget, motortarget, reversemotortarget);
			resetmotors();
		}
		sensorvalues();
		findgreen();
		if (SensorValue[S4] > walldistance)
		{
			resetmotors();
			while (nMotorEncoder[motorB] < circle/(wheeldiameter * PI) * grid && (l == no && r == no) && ((xvalue+yvalue+zvalue)/triple<silvervalue && (avalue+bvalue+cvalue)/triple<silvervalue))
			{
				motor[motorB] = motortarget;
				motor[motorC] = motortarget;
				sensorvalues();
				findgreen();
			}
			resetmotors();
			if (l == yes || r == yes)
			{
				resetmotors();
				while (nMotorEncoder[motorB] > circle/(wheeldiameter * PI) * (0 - halfgrid))
				{
					motor[motorB] = reversemotortarget;
					motor[motorC] = reversemotortarget;
				}
				resetmotors();
				exit = 3;
				array[0][0] = exitarray;
			}
			else if ((xvalue+yvalue+zvalue)/triple>=silvervalue || (avalue+bvalue+cvalue)/triple>=silvervalue)
			{
				resetmotors();
				while (nMotorEncoder[motorB] > circle/(wheeldiameter * PI) * (0 - halfgrid))
				{
					motor[motorB] = reversemotortarget;
					motor[motorC] = reversemotortarget;
				}
				resetmotors();
				entrance = 3;
				array[0][0] = entrancearray;
			}
		}
		else
		{
			array[0][0] = emptyarray;
		}
		if (startturndirection == 'l')
		{
			resetmotors();
			turnDegrees('r', turntarget, motortarget, reversemotortarget);
			resetmotors();
		}
		else if (startturndirection == 'r')
		{
			resetmotors();
			turnDegrees('l', turntarget, reversemotortarget, motortarget);
			resetmotors();
		}
		if (SensorValue[S4] < walldistance)
		{
			length = 3;
		}
		else
		{
			sensorvalues();
			findgreen();
			resetmotors();
			while (nMotorEncoder[motorB] < circle/(wheeldiameter * PI) * grid && (l == no && r == no) && ((xvalue+yvalue+zvalue)/triple<silvervalue && (avalue+bvalue+cvalue)/triple<silvervalue))
			{
				motor[motorB] = motortarget;
				motor[motorC] = motortarget;
				sensorvalues();
				findgreen();
			}
			resetmotors();
			if (l == yes || r == yes)
			{
				resetmotors();
				while (nMotorEncoder[motorB] > circle/(wheeldiameter * PI) * (0 - halfgrid))
				{
					motor[motorB] = reversemotortarget;
					motor[motorC] = reversemotortarget;
				}
				resetmotors();
				array[0][0] = exitarray;
				if (length == 3 && startturndirection == 'l')
				{
					eraseEllipse(37.08333, 115.2, 51.91666, 89.6);
					drawEllipse(37.08333, 115.2, 51.91666, 89.6);
				}
				else if (length == 3 && startturndirection == 'r')
				{
					eraseEllipse(126.08333, 115.2, 140.91666, 89.6);
					drawEllipse(126.08333, 115.2, 140.91666, 89.6);
				}
			}
			else if ((xvalue+yvalue+zvalue)/triple>=silvervalue || (avalue+bvalue+cvalue)/triple>=silvervalue)
			{
				resetmotors();
				while (nMotorEncoder[motorB] > circle/(wheeldiameter * PI) * (0 - halfgrid))
				{
					motor[motorB] = reversemotortarget;
					motor[motorC] = reversemotortarget;
				}
				resetmotors();
				array[0][0] = entrancearray;
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
					resetmotors();
					turnDegrees('l', turntarget, reversemotortarget, motortarget);
					resetmotors();
				}
				else if (startturndirection == 'r')
				{
					resetmotors();
					turnDegrees('r', turntarget, motortarget, reversemotortarget);
					resetmotors();
				}
				sensorvalues();
				findgreen();
				if (SensorValue[S4] > walldistance)
				{
					resetmotors();
					while (nMotorEncoder[motorB] < circle/(wheeldiameter * PI) * grid && (l == no && r == no) && ((xvalue+yvalue+zvalue)/triple<silvervalue && (avalue+bvalue+cvalue)/triple<silvervalue))
					{
						motor[motorB] = motortarget;
						motor[motorC] = motortarget;
						sensorvalues();
						findgreen();
					}
					resetmotors();
					if (l == yes || r == yes)
					{
						resetmotors();
						while (nMotorEncoder[motorB] > circle/(wheeldiameter * PI) * (0 - halfgrid))
						{
							motor[motorB] = reversemotortarget;
							motor[motorC] = reversemotortarget;
						}
						resetmotors();
						exit = 4;
					}
					else if ((xvalue+yvalue+zvalue)/triple>=silvervalue || (avalue+bvalue+cvalue)/triple>=silvervalue)
					{
						resetmotors();
						while (nMotorEncoder[motorB] > circle/(wheeldiameter * PI) * (0 - halfgrid))
						{
							motor[motorB] = reversemotortarget;
							motor[motorC] = reversemotortarget;
						}
						resetmotors();
						entrance = 4;
					}
				}
				else
				{
				}
				if (startturndirection == 'l')
				{
					resetmotors();
					turnDegrees('r', turntarget, motortarget, reversemotortarget);
					resetmotors();
				}
				else if (startturndirection == 'r')
				{
					resetmotors();
					turnDegrees('l', turntarget, reversemotortarget, motortarget);
					resetmotors();
				}
				length = 4;
				sensorvalues();
				findgreen();
				if (SensorValue[S4] > walldistance)
				{
					resetmotors();
					while (nMotorEncoder[motorB] < circle/(wheeldiameter * PI) * grid && (l == no && r == no) && ((xvalue+yvalue+zvalue)/triple<silvervalue && (avalue+bvalue+cvalue)/triple<silvervalue))
					{
						motor[motorB] = motortarget;
						motor[motorC] = motortarget;
						sensorvalues();
						findgreen();
					}
					resetmotors();
					if (l == yes || r == yes)
					{
						resetmotors();
						while (nMotorEncoder[motorB] > circle/(wheeldiameter * PI) * (0 - halfgrid))
						{
							motor[motorB] = reversemotortarget;
							motor[motorC] = reversemotortarget;
						}
						resetmotors();
						if (length == 4 && startturndirection == 'l')
						{
							eraseEllipse(14.83333, 32, 44.5, 44.8);
							drawEllipse(14.83333, 32, 44.5, 44.8);
						}
						else if (length == 4 && startturndirection == 'r')
						{
							eraseEllipse(14.83333, 83.2, 44.5, 96);
							drawEllipse(14.83333, 83.2, 44.5, 96);
						}
					}
					else if ((xvalue+yvalue+zvalue)/triple>=silvervalue || (avalue+bvalue+cvalue)/triple>=silvervalue)
					{
						resetmotors();
						while (nMotorEncoder[motorB] > circle/(wheeldiameter * PI) * (0 - halfgrid))
						{
							motor[motorB] = reversemotortarget;
							motor[motorC] = reversemotortarget;
						}
						resetmotors();
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
		}
		sensorvalues();
		if (xvalue<sensoraverage || avalue<sensoraverage)
		{
			triangle = yes;
		}
		else
		{
			triangle = no;
		}
		if (triangle == yes && length == 3)
		{
			array[0][0] = trianglearray;
		}
		else if (triangle == yes && length == 4)
		{
		}
		if (length == 4 && startturndirection == 'l')
		{
			eraseRect(133.5, 32, 163.16666, 44.8);
			drawRect(133.5, 32, 163.16666, 44.8);
			if (exit == 2)
			{
				eraseEllipse(96.41666, 38.4, 111.25, 12.8);
				drawEllipse(96.41666, 38.4, 111.25, 12.8);
			}
			else if (exit == 3)
			{
				eraseEllipse(66.75, 38.4, 81.58333, 12.8);
				drawEllipse(66.75, 38.4, 81.58333, 12.8);
			}
			else if (exit == 4)
			{
				eraseEllipse(37.08333, 38.4, 51.91666, 12.8);
				drawEllipse(37.08333, 38.4, 51.91666, 12.8);
			}
			if (entrance == 2)
			{
				fillEllipse(96.41666, 38.4, 111.25, 12.8);
			}
			else if (entrance == 3)
			{
				fillEllipse(66.75, 38.4, 81.58333, 12.8);
			}
			else if (entrance == 4)
			{
				fillEllipse(37.08333, 38.4, 51.91666, 12.8);
			}
			if (triangle == yes)
			{
				drawLine(29.66666, 51.2, 59.333333, 25.6);
			}
		}
		else if (length == 4 && startturndirection == 'r')
		{
			eraseRect(133.5, 83.2, 163.16666, 96);
			drawRect(133.5, 83.2, 163.16666, 96);
			if (exit == 2)
			{
				eraseEllipse(96.41666, 115.2, 111.25, 89.6);
				drawEllipse(96.41666, 115.2, 111.25, 89.6);
			}
			else if (exit == 3)
			{
				eraseEllipse(66.75, 115.2, 81.58333, 89.6);
				drawEllipse(66.75, 115.2, 81.58333, 89.6);
			}
			else if (exit == 4)
			{
				eraseEllipse(37.08333, 115.2, 51.91666, 89.6);
				drawEllipse(37.08333, 115.2, 51.91666, 89.6);
			}
			if (entrance == 2)
			{
				fillEllipse(96.41666, 115.2, 111.25, 89.6);
			}
			else if (entrance == 3)
			{
				fillEllipse(66.75, 115.2, 81.58333, 89.6);
			}
			else if (entrance == 4)
			{
				fillEllipse(37.08333, 115.2, 51.91666, 89.6);
			}
			if (triangle == yes)
			{
				drawLine(29.66666, 76.8, 59.333333, 102.4);
			}
		}
		else if (length == 3 && startturndirection == 'l')
		{
			eraseRect(37.08333, 38.4, 51.91666, 12.8);
			drawRect(37.08333, 38.4, 51.91666, 12.8);
			if (exit == 2)
			{
				eraseEllipse(14.83333, 70.4, 44.5, 57.6);
				drawEllipse(14.83333, 70.4, 44.5, 57.6);
			}
			else if (exit == 3)
			{
				eraseEllipse(14.83333, 96, 44.5, 83.2);
				drawEllipse(14.83333, 96, 44.5, 83.2);
			}
			if (entrance == 2)
			{
				fillEllipse(14.83333, 70.4, 44.5, 57.6);
			}
			else if (entrance == 3)
			{
				fillEllipse(14.83333, 96, 44.5, 83.2);
			}
			if (triangle == yes)
			{
				drawLine(29.66666, 76.8, 59.333333, 102.4);
			}
		}
		else if (length == 3 && startturndirection == 'r')
		{
			eraseRect(126.08333, 38.4, 140.91666, 12.8);
			drawRect(126.08333, 38.4, 140.91666, 12.8);
			if (exit == 2)
			{
				eraseEllipse(133.5, 70.4, 163.16666, 57.6);
				drawEllipse(133.5, 70.4, 163.16666, 57.6);
			}
			else if (exit == 3)
			{
				eraseEllipse(133.5, 96, 163.16666, 83.2);
				drawEllipse(133.5, 96, 163.16666, 83.2);
			}
			if (entrance == 2)
			{
				fillEllipse(133.5, 70.4, 163.16666, 57.6);
			}
			else if (entrance == 3)
			{
				fillEllipse(133.5, 96, 163.16666, 83.2);
			}
			if (triangle == yes)
			{
				drawLine(118.66666, 102.4, 148.33333, 76.8);
			}
		}
		entrance = 0;
		exit = 0;
		triangle = no;
		resetmotors();
	}
	else if (length == 3)
	{
		if (startturndirection == 'l')
		{
			resetmotors();
			turnDegrees('r', turntarget, motortarget, reversemotortarget);
			resetmotors();
		}
		else if (startturndirection == 'r')
		{
			resetmotors();
			turnDegrees('l', turntarget, reversemotortarget, motortarget);
			resetmotors();
		}
		eraseDisplay();
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
		resetmotors();
		while (nMotorEncoder[motorB] < circle/(wheeldiameter * PI) * grid)
		{
			motor[motorB] = motortarget;
			motor[motorC] = motortarget;
		}
		resetmotors();
		if (startturndirection == 'l')
		{
			resetmotors();
			turnDegrees('l', turntarget, reversemotortarget, motortarget);
			resetmotors();
		}
		else if (startturndirection == 'r')
		{
			resetmotors();
			turnDegrees('r', turntarget, motortarget, reversemotortarget);
			resetmotors();
		}
		sensorvalues();
		findgreen();
		if (SensorValue[S4] > walldistance)
		{
			resetmotors();
			while (nMotorEncoder[motorB] < circle/(wheeldiameter * PI) * grid && (l == no && r == no) && ((xvalue+yvalue+zvalue)/triple<silvervalue && (avalue+bvalue+cvalue)/triple<silvervalue))
			{
				motor[motorB] = motortarget;
				motor[motorC] = motortarget;
				sensorvalues();
				findgreen();
			}
			resetmotors();
			if (l == yes || r == yes)
			{
				resetmotors();
				while (nMotorEncoder[motorB] > circle/(wheeldiameter * PI) * (0 - halfgrid))
				{
					motor[motorB] = reversemotortarget;
					motor[motorC] = reversemotortarget;
				}
				resetmotors();
				exit = 2;
				array[1][2] = exitarray;
			}
			else if ((xvalue+yvalue+zvalue)/triple>=silvervalue || (avalue+bvalue+cvalue)/triple>=silvervalue)
			{
				resetmotors();
				while (nMotorEncoder[motorB] > circle/(wheeldiameter * PI) * (0 - halfgrid))
				{
					motor[motorB] = reversemotortarget;
					motor[motorC] = reversemotortarget;
				}
				resetmotors();
				entrance = 2;
				array[1][2] = entrancearray;
			}
		}
		else
		{
			array[1][2] = emptyarray;
		}
		if (startturndirection == 'l')
		{
			resetmotors();
			turnDegrees('r', turntarget, motortarget, reversemotortarget);
			resetmotors();
		}
		else if (startturndirection == 'r')
		{
			resetmotors();
			turnDegrees('l', turntarget, reversemotortarget, motortarget);
			resetmotors();
		}
		resetmotors();
		while (nMotorEncoder[motorB] < circle/(wheeldiameter * PI) * grid)
		{
			motor[motorB] = motortarget;
			motor[motorC] = motortarget;
		}
		resetmotors();
		if (startturndirection == 'l')
		{
			resetmotors();
			turnDegrees('l', turntarget, reversemotortarget, motortarget);
			resetmotors();
		}
		else if (startturndirection == 'r')
		{
			resetmotors();
			turnDegrees('r', turntarget, motortarget, reversemotortarget);
			resetmotors();
		}
		sensorvalues();
		findgreen();
		if (SensorValue[S4] > walldistance)
		{
			resetmotors();
			while (nMotorEncoder[motorB] < circle/(wheeldiameter * PI) * grid && (l == no && r == no) && ((xvalue+yvalue+zvalue)/triple<silvervalue && (avalue+bvalue+cvalue)/triple<silvervalue))
			{
				motor[motorB] = motortarget;
				motor[motorC] = motortarget;
				sensorvalues();
				findgreen();
			}
			resetmotors();
			if (l == yes || r == yes)
			{
				resetmotors();
				while (nMotorEncoder[motorB] > circle/(wheeldiameter * PI) * (0 - halfgrid))
				{
					motor[motorB] = reversemotortarget;
					motor[motorC] = reversemotortarget;
				}
				resetmotors();
				exit = 3;
				array[2][2] = exitarray;
			}
			else if ((xvalue+yvalue+zvalue)/triple>=silvervalue || (avalue+bvalue+cvalue)/triple>=silvervalue)
			{
				resetmotors();
				while (nMotorEncoder[motorB] > circle/(wheeldiameter * PI) * (0 - halfgrid))
				{
					motor[motorB] = reversemotortarget;
					motor[motorC] = reversemotortarget;
				}
				resetmotors();
				entrance = 3;
				array[2][2] = entrancearray;
			}
		}
		else
		{
			array[2][2] = emptyarray;
		}
		if (startturndirection == 'l')
		{
			resetmotors();
			turnDegrees('r', turntarget, motortarget, reversemotortarget);
			resetmotors();
		}
		else if (startturndirection == 'r')
		{
			resetmotors();
			turnDegrees('l', turntarget, reversemotortarget, motortarget);
			resetmotors();
		}
		if (SensorValue[S4] < walldistance)
		{
			length = 3;
		}
		else
		{
			sensorvalues();
			findgreen();
			resetmotors();
			while (nMotorEncoder[motorB] < circle/(wheeldiameter * PI) * grid && (l == no && r == no) && ((xvalue+yvalue+zvalue)/triple<silvervalue && (avalue+bvalue+cvalue)/triple<silvervalue))
			{
				motor[motorB] = motortarget;
				motor[motorC] = motortarget;
				sensorvalues();
				findgreen();
			}
			resetmotors();
			if (l == yes || r == yes)
			{
				resetmotors();
				while (nMotorEncoder[motorB] > circle/(wheeldiameter * PI) * (0 - halfgrid))
				{
					motor[motorB] = reversemotortarget;
					motor[motorC] = reversemotortarget;
				}
				resetmotors();
				array[2][2] = exitarray;
				if (length == 3 && startturndirection == 'l')
				{
					eraseEllipse(37.08333, 115.2, 51.91666, 89.6);
					drawEllipse(37.08333, 115.2, 51.91666, 89.6);
				}
				else if (length == 3 && startturndirection == 'r')
				{
					eraseEllipse(126.08333, 115.2, 140.91666, 89.6);
					drawEllipse(126.08333, 115.2, 140.91666, 89.6);
				}
			}
			else if ((xvalue+yvalue+zvalue)/triple>=silvervalue || (avalue+bvalue+cvalue)/triple>=silvervalue)
			{
				resetmotors();
				while (nMotorEncoder[motorB] > circle/(wheeldiameter * PI) * (0 - halfgrid))
				{
					motor[motorB] = reversemotortarget;
					motor[motorC] = reversemotortarget;
				}
				resetmotors();
				array[2][2] = entrancearray;
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
					resetmotors();
					turnDegrees('l', turntarget, reversemotortarget, motortarget);
					resetmotors();
				}
				else if (startturndirection == 'r')
				{
					resetmotors();
					turnDegrees('r', turntarget, motortarget, reversemotortarget);
					resetmotors();
				}
				sensorvalues();
				findgreen();
				if (SensorValue[S4] > walldistance)
				{
					resetmotors();
					while (nMotorEncoder[motorB] < circle/(wheeldiameter * PI) * grid && (l == no && r == no) && ((xvalue+yvalue+zvalue)/triple<silvervalue && (avalue+bvalue+cvalue)/triple<silvervalue))
					{
						motor[motorB] = motortarget;
						motor[motorC] = motortarget;
						sensorvalues();
						findgreen();
					}
					resetmotors();
					if (l == yes || r == yes)
					{
						resetmotors();
						while (nMotorEncoder[motorB] > circle/(wheeldiameter * PI) * (0 - halfgrid))
						{
							motor[motorB] = reversemotortarget;
							motor[motorC] = reversemotortarget;
						}
						resetmotors();
						exit = 4;
						array[3][2] = exitarray;
					}
					else if ((xvalue+yvalue+zvalue)/triple>=silvervalue || (avalue+bvalue+cvalue)/triple>=silvervalue)
					{
						resetmotors();
						while (nMotorEncoder[motorB] > circle/(wheeldiameter * PI) * (0 - halfgrid))
						{
							motor[motorB] = reversemotortarget;
							motor[motorC] = reversemotortarget;
						}
						resetmotors();
						entrance = 4;
						array[3][2] = entrancearray;
					}
				}
				else
				{
					array[3][2] = emptyarray;
				}
				if (startturndirection == 'l')
				{
					resetmotors();
					turnDegrees('r', turntarget, motortarget, reversemotortarget);
					resetmotors();
				}
				else if (startturndirection == 'r')
				{
					resetmotors();
					turnDegrees('l', turntarget, reversemotortarget, motortarget);
					resetmotors();
				}
				length = 4;
				sensorvalues();
				findgreen();
				if (SensorValue[S4] > walldistance)
				{
					resetmotors();
					while (nMotorEncoder[motorB] < circle/(wheeldiameter * PI) * grid && (l == no && r == no) && ((xvalue+yvalue+zvalue)/triple<silvervalue && (avalue+bvalue+cvalue)/triple<silvervalue))
					{
						motor[motorB] = motortarget;
						motor[motorC] = motortarget;
						sensorvalues();
						findgreen();
					}
					resetmotors();
					if (l == yes || r == yes)
					{
						resetmotors();
						while (nMotorEncoder[motorB] > circle/(wheeldiameter * PI) * (0 - halfgrid))
						{
							motor[motorB] = reversemotortarget;
							motor[motorC] = reversemotortarget;
						}
						resetmotors();
						array[3][2] = exitarray;
						if (length == 4 && startturndirection == 'l')
						{
							eraseEllipse(14.83333, 32, 44.5, 44.8);
							drawEllipse(14.83333, 32, 44.5, 44.8);
						}
						else if (length == 4 && startturndirection == 'r')
						{
							eraseEllipse(14.83333, 83.2, 44.5, 96);
							drawEllipse(14.83333, 83.2, 44.5, 96);
						}
					}
					else if ((xvalue+yvalue+zvalue)/triple>=silvervalue || (avalue+bvalue+cvalue)/triple>=silvervalue)
					{
						resetmotors();
						while (nMotorEncoder[motorB] > circle/(wheeldiameter * PI) * (0 - halfgrid))
						{
							motor[motorB] = reversemotortarget;
							motor[motorC] = reversemotortarget;
						}
						resetmotors();
						array[3][2] = entrancearray;
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
		}
		sensorvalues();
		if (xvalue<sensoraverage || avalue<sensoraverage)
		{
			triangle = yes;
		}
		else
		{
			triangle = no;
		}
		if (triangle == yes && length == 3)
		{
			array[2][2] = trianglearray;
		}
		else if (triangle == yes && length == 4)
		{
			array[3][2] = trianglearray;
		}
		if (length == 4 && startturndirection == 'l')
		{
			eraseRect(133.5, 32, 163.16666, 44.8);
			drawRect(133.5, 32, 163.16666, 44.8);
			if (exit == 2)
			{
				eraseEllipse(96.41666, 38.4, 111.25, 12.8);
				drawEllipse(96.41666, 38.4, 111.25, 12.8);
			}
			else if (exit == 3)
			{
				eraseEllipse(66.75, 38.4, 81.58333, 12.8);
				drawEllipse(66.75, 38.4, 81.58333, 12.8);
			}
			else if (exit == 4)
			{
				eraseEllipse(37.08333, 38.4, 51.91666, 12.8);
				drawEllipse(37.08333, 38.4, 51.91666, 12.8);
			}
			if (entrance == 2)
			{
				fillEllipse(96.41666, 38.4, 111.25, 12.8);
			}
			else if (entrance == 3)
			{
				fillEllipse(66.75, 38.4, 81.58333, 12.8);
			}
			else if (entrance == 4)
			{
				fillEllipse(37.08333, 38.4, 51.91666, 12.8);
			}
			if (triangle == yes)
			{
				drawLine(29.66666, 51.2, 59.333333, 25.6);
			}
		}
		else if (length == 4 && startturndirection == 'r')
		{
			eraseRect(133.5, 83.2, 163.16666, 96);
			drawRect(133.5, 83.2, 163.16666, 96);
			if (exit == 2)
			{
				eraseEllipse(96.41666, 115.2, 111.25, 89.6);
				drawEllipse(96.41666, 115.2, 111.25, 89.6);
			}
			else if (exit == 3)
			{
				eraseEllipse(66.75, 115.2, 81.58333, 89.6);
				drawEllipse(66.75, 115.2, 81.58333, 89.6);
			}
			else if (exit == 4)
			{
				eraseEllipse(37.08333, 115.2, 51.91666, 89.6);
				drawEllipse(37.08333, 115.2, 51.91666, 89.6);
			}
			if (entrance == 2)
			{
				fillEllipse(96.41666, 115.2, 111.25, 89.6);
			}
			else if (entrance == 3)
			{
				fillEllipse(66.75, 115.2, 81.58333, 89.6);
			}
			else if (entrance == 4)
			{
				fillEllipse(37.08333, 115.2, 51.91666, 89.6);
			}
			if (triangle == yes)
			{
				drawLine(29.66666, 76.8, 59.333333, 102.4);
			}
		}
		else if (length == 3 && startturndirection == 'l')
		{
			eraseRect(37.08333, 38.4, 51.91666, 12.8);
			drawRect(37.08333, 38.4, 51.91666, 12.8);
			if (exit == 2)
			{
				eraseEllipse(14.83333, 70.4, 44.5, 57.6);
				drawEllipse(14.83333, 70.4, 44.5, 57.6);
			}
			else if (exit == 3)
			{
				eraseEllipse(14.83333, 96, 44.5, 83.2);
				drawEllipse(14.83333, 96, 44.5, 83.2);
			}
			if (entrance == 2)
			{
				fillEllipse(14.83333, 70.4, 44.5, 57.6);
			}
			else if (entrance == 3)
			{
				fillEllipse(14.83333, 96, 44.5, 83.2);
			}
			if (triangle == yes)
			{
				drawLine(29.66666, 76.8, 59.333333, 102.4);
			}
		}
		else if (length == 3 && startturndirection == 'r')
		{
			eraseRect(126.08333, 38.4, 140.91666, 12.8);
			drawRect(126.08333, 38.4, 140.91666, 12.8);
			if (exit == 2)
			{
				eraseEllipse(133.5, 70.4, 163.16666, 57.6);
				drawEllipse(133.5, 70.4, 163.16666, 57.6);
			}
			else if (exit == 3)
			{
				eraseEllipse(133.5, 96, 163.16666, 83.2);
				drawEllipse(133.5, 96, 163.16666, 83.2);
			}
			if (entrance == 2)
			{
				fillEllipse(133.5, 70.4, 163.16666, 57.6);
			}
			else if (entrance == 3)
			{
				fillEllipse(133.5, 96, 163.16666, 83.2);
			}
			if (triangle == yes)
			{
				drawLine(118.66666, 102.4, 148.33333, 76.8);
			}
		}
		entrance = 0;
		exit = 0;
		triangle = no;
		resetmotors();
		if (startturndirection == 'l')
		{
			resetmotors();
			turnDegrees('r', turntarget, motortarget, reversemotortarget);
			resetmotors();
		}
		else if (startturndirection == 'r')
		{
			resetmotors();
			turnDegrees('l', turntarget, reversemotortarget, motortarget);
			resetmotors();
		}
		eraseDisplay();
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
		resetmotors();
		while (nMotorEncoder[motorB] < circle/(wheeldiameter * PI) * grid)
		{
			motor[motorB] = motortarget;
			motor[motorC] = motortarget;
		}
		resetmotors();
		if (startturndirection == 'l')
		{
			resetmotors();
			turnDegrees('l', turntarget, reversemotortarget, motortarget);
			resetmotors();
		}
		else if (startturndirection == 'r')
		{
			resetmotors();
			turnDegrees('r', turntarget, motortarget, reversemotortarget);
			resetmotors();
		}
		sensorvalues();
		findgreen();
		if (SensorValue[S4] > walldistance)
		{
			resetmotors();
			while (nMotorEncoder[motorB] < circle/(wheeldiameter * PI) * grid && (l == no && r == no) && ((xvalue+yvalue+zvalue)/triple<silvervalue && (avalue+bvalue+cvalue)/triple<silvervalue))
			{
				motor[motorB] = motortarget;
				motor[motorC] = motortarget;
				sensorvalues();
				findgreen();
			}
			resetmotors();
			if (l == yes || r == yes)
			{
				resetmotors();
				while (nMotorEncoder[motorB] > circle/(wheeldiameter * PI) * (0 - halfgrid))
				{
					motor[motorB] = reversemotortarget;
					motor[motorC] = reversemotortarget;
				}
				resetmotors();
				exit = 2;
				array[3][1] = exitarray;
			}
			else if ((xvalue+yvalue+zvalue)/triple>=silvervalue || (avalue+bvalue+cvalue)/triple>=silvervalue)
			{
				resetmotors();
				while (nMotorEncoder[motorB] > circle/(wheeldiameter * PI) * (0 - halfgrid))
				{
					motor[motorB] = reversemotortarget;
					motor[motorC] = reversemotortarget;
				}
				resetmotors();
				entrance = 2;
				array[3][1] = entrancearray;
			}
		}
		else
		{
			array[3][1] = emptyarray;
		}
		if (startturndirection == 'l')
		{
			resetmotors();
			turnDegrees('r', turntarget, motortarget, reversemotortarget);
			resetmotors();
		}
		else if (startturndirection == 'r')
		{
			resetmotors();
			turnDegrees('l', turntarget, reversemotortarget, motortarget);
			resetmotors();
		}
		resetmotors();
		while (nMotorEncoder[motorB] < circle/(wheeldiameter * PI) * grid)
		{
			motor[motorB] = motortarget;
			motor[motorC] = motortarget;
		}
		resetmotors();
		if (startturndirection == 'l')
		{
			resetmotors();
			turnDegrees('l', turntarget, reversemotortarget, motortarget);
			resetmotors();
		}
		else if (startturndirection == 'r')
		{
			resetmotors();
			turnDegrees('r', turntarget, motortarget, reversemotortarget);
			resetmotors();
		}
		sensorvalues();
		findgreen();
		if (SensorValue[S4] > walldistance)
		{
			resetmotors();
			while (nMotorEncoder[motorB] < circle/(wheeldiameter * PI) * grid && (l == no && r == no) && ((xvalue+yvalue+zvalue)/triple<silvervalue && (avalue+bvalue+cvalue)/triple<silvervalue))
			{
				motor[motorB] = motortarget;
				motor[motorC] = motortarget;
				sensorvalues();
				findgreen();
			}
			resetmotors();
			if (l == yes || r == yes)
			{
				resetmotors();
				while (nMotorEncoder[motorB] > circle/(wheeldiameter * PI) * (0 - halfgrid))
				{
					motor[motorB] = reversemotortarget;
					motor[motorC] = reversemotortarget;
				}
				resetmotors();
				exit = 3;
				array[3][0] = exitarray;
			}
			else if ((xvalue+yvalue+zvalue)/triple>=silvervalue || (avalue+bvalue+cvalue)/triple>=silvervalue)
			{
				resetmotors();
				while (nMotorEncoder[motorB] > circle/(wheeldiameter * PI) * (0 - halfgrid))
				{
					motor[motorB] = reversemotortarget;
					motor[motorC] = reversemotortarget;
				}
				resetmotors();
				entrance = 3;
				array[3][0] = entrancearray;
			}
		}
		else
		{
			array[3][0] = emptyarray;
		}
		if (startturndirection == 'l')
		{
			resetmotors();
			turnDegrees('r', turntarget, motortarget, reversemotortarget);
			resetmotors();
		}
		else if (startturndirection == 'r')
		{
			resetmotors();
			turnDegrees('l', turntarget, reversemotortarget, motortarget);
			resetmotors();
		}
		if (SensorValue[S4] < walldistance)
		{
			length = 3;
		}
		else
		{
			sensorvalues();
			findgreen();
			resetmotors();
			while (nMotorEncoder[motorB] < circle/(wheeldiameter * PI) * grid && (l == no && r == no) && ((xvalue+yvalue+zvalue)/triple<silvervalue && (avalue+bvalue+cvalue)/triple<silvervalue))
			{
				motor[motorB] = motortarget;
				motor[motorC] = motortarget;
				sensorvalues();
				findgreen();
			}
			resetmotors();
			if (l == yes || r == yes)
			{
				resetmotors();
				while (nMotorEncoder[motorB] > circle/(wheeldiameter * PI) * (0 - halfgrid))
				{
					motor[motorB] = reversemotortarget;
					motor[motorC] = reversemotortarget;
				}
				resetmotors();
				array[3][0] = exitarray;
				if (length == 3 && startturndirection == 'l')
				{
					eraseEllipse(37.08333, 115.2, 51.91666, 89.6);
					drawEllipse(37.08333, 115.2, 51.91666, 89.6);
				}
				else if (length == 3 && startturndirection == 'r')
				{
					eraseEllipse(126.08333, 115.2, 140.91666, 89.6);
					drawEllipse(126.08333, 115.2, 140.91666, 89.6);
				}
			}
			else if ((xvalue+yvalue+zvalue)/triple>=silvervalue || (avalue+bvalue+cvalue)/triple>=silvervalue)
			{
				resetmotors();
				while (nMotorEncoder[motorB] > circle/(wheeldiameter * PI) * (0 - halfgrid))
				{
					motor[motorB] = reversemotortarget;
					motor[motorC] = reversemotortarget;
				}
				resetmotors();
				array[3][0] = entrancearray;
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
					resetmotors();
					turnDegrees('l', turntarget, reversemotortarget, motortarget);
					resetmotors();
				}
				else if (startturndirection == 'r')
				{
					resetmotors();
					turnDegrees('r', turntarget, motortarget, reversemotortarget);
					resetmotors();
				}
				sensorvalues();
				findgreen();
				if (SensorValue[S4] > walldistance)
				{
					resetmotors();
					while (nMotorEncoder[motorB] < circle/(wheeldiameter * PI) * grid && (l == no && r == no) && ((xvalue+yvalue+zvalue)/triple<silvervalue && (avalue+bvalue+cvalue)/triple<silvervalue))
					{
						motor[motorB] = motortarget;
						motor[motorC] = motortarget;
						sensorvalues();
						findgreen();
					}
					resetmotors();
					if (l == yes || r == yes)
					{
						resetmotors();
						while (nMotorEncoder[motorB] > circle/(wheeldiameter * PI) * (0 - halfgrid))
						{
							motor[motorB] = reversemotortarget;
							motor[motorC] = reversemotortarget;
						}
						resetmotors();
						exit = 4;
					}
					else if ((xvalue+yvalue+zvalue)/triple>=silvervalue || (avalue+bvalue+cvalue)/triple>=silvervalue)
					{
						resetmotors();
						while (nMotorEncoder[motorB] > circle/(wheeldiameter * PI) * (0 - halfgrid))
						{
							motor[motorB] = reversemotortarget;
							motor[motorC] = reversemotortarget;
						}
						resetmotors();
						entrance = 4;
					}
				}
				else
				{
				}
				if (startturndirection == 'l')
				{
					resetmotors();
					turnDegrees('r', turntarget, motortarget, reversemotortarget);
					resetmotors();
				}
				else if (startturndirection == 'r')
				{
					resetmotors();
					turnDegrees('l', turntarget, reversemotortarget, motortarget);
					resetmotors();
				}
				length = 4;
				sensorvalues();
				findgreen();
				if (SensorValue[S4] > walldistance)
				{
					resetmotors();
					while (nMotorEncoder[motorB] < circle/(wheeldiameter * PI) * grid && (l == no && r == no) && ((xvalue+yvalue+zvalue)/triple<silvervalue && (avalue+bvalue+cvalue)/triple<silvervalue))
					{
						motor[motorB] = motortarget;
						motor[motorC] = motortarget;
						sensorvalues();
						findgreen();
					}
					resetmotors();
					if (l == yes || r == yes)
					{
						resetmotors();
						while (nMotorEncoder[motorB] > circle/(wheeldiameter * PI) * (0 - halfgrid))
						{
							motor[motorB] = reversemotortarget;
							motor[motorC] = reversemotortarget;
						}
						resetmotors();
						if (length == 4 && startturndirection == 'l')
						{
							eraseEllipse(14.83333, 32, 44.5, 44.8);
							drawEllipse(14.83333, 32, 44.5, 44.8);
						}
						else if (length == 4 && startturndirection == 'r')
						{
							eraseEllipse(14.83333, 83.2, 44.5, 96);
							drawEllipse(14.83333, 83.2, 44.5, 96);
						}
					}
					else if ((xvalue+yvalue+zvalue)/triple>=silvervalue || (avalue+bvalue+cvalue)/triple>=silvervalue)
					{
						resetmotors();
						while (nMotorEncoder[motorB] > circle/(wheeldiameter * PI) * (0 - halfgrid))
						{
							motor[motorB] = reversemotortarget;
							motor[motorC] = reversemotortarget;
						}
						resetmotors();
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
		}
		sensorvalues();
		if (xvalue<sensoraverage || avalue<sensoraverage)
		{
			triangle = yes;
		}
		else
		{
			triangle = no;
		}
		if (triangle == yes && length == 3)
		{
			array[3][0] = trianglearray;
		}
		else if (triangle == yes && length == 4)
		{
		}
		if (length == 4 && startturndirection == 'l')
		{
			eraseRect(133.5, 32, 163.16666, 44.8);
			drawRect(133.5, 32, 163.16666, 44.8);
			if (exit == 2)
			{
				eraseEllipse(96.41666, 38.4, 111.25, 12.8);
				drawEllipse(96.41666, 38.4, 111.25, 12.8);
			}
			else if (exit == 3)
			{
				eraseEllipse(66.75, 38.4, 81.58333, 12.8);
				drawEllipse(66.75, 38.4, 81.58333, 12.8);
			}
			else if (exit == 4)
			{
				eraseEllipse(37.08333, 38.4, 51.91666, 12.8);
				drawEllipse(37.08333, 38.4, 51.91666, 12.8);
			}
			if (entrance == 2)
			{
				fillEllipse(96.41666, 38.4, 111.25, 12.8);
			}
			else if (entrance == 3)
			{
				fillEllipse(66.75, 38.4, 81.58333, 12.8);
			}
			else if (entrance == 4)
			{
				fillEllipse(37.08333, 38.4, 51.91666, 12.8);
			}
			if (triangle == yes)
			{
				drawLine(29.66666, 51.2, 59.333333, 25.6);
			}
		}
		else if (length == 4 && startturndirection == 'r')
		{
			eraseRect(133.5, 83.2, 163.16666, 96);
			drawRect(133.5, 83.2, 163.16666, 96);
			if (exit == 2)
			{
				eraseEllipse(96.41666, 115.2, 111.25, 89.6);
				drawEllipse(96.41666, 115.2, 111.25, 89.6);
			}
			else if (exit == 3)
			{
				eraseEllipse(66.75, 115.2, 81.58333, 89.6);
				drawEllipse(66.75, 115.2, 81.58333, 89.6);
			}
			else if (exit == 4)
			{
				eraseEllipse(37.08333, 115.2, 51.91666, 89.6);
				drawEllipse(37.08333, 115.2, 51.91666, 89.6);
			}
			if (entrance == 2)
			{
				fillEllipse(96.41666, 115.2, 111.25, 89.6);
			}
			else if (entrance == 3)
			{
				fillEllipse(66.75, 115.2, 81.58333, 89.6);
			}
			else if (entrance == 4)
			{
				fillEllipse(37.08333, 115.2, 51.91666, 89.6);
			}
			if (triangle == yes)
			{
				drawLine(29.66666, 76.8, 59.333333, 102.4);
			}
		}
		else if (length == 3 && startturndirection == 'l')
		{
			eraseRect(37.08333, 38.4, 51.91666, 12.8);
			drawRect(37.08333, 38.4, 51.91666, 12.8);
			if (exit == 2)
			{
				eraseEllipse(14.83333, 70.4, 44.5, 57.6);
				drawEllipse(14.83333, 70.4, 44.5, 57.6);
			}
			else if (exit == 3)
			{
				eraseEllipse(14.83333, 96, 44.5, 83.2);
				drawEllipse(14.83333, 96, 44.5, 83.2);
			}
			if (entrance == 2)
			{
				fillEllipse(14.83333, 70.4, 44.5, 57.6);
			}
			else if (entrance == 3)
			{
				fillEllipse(14.83333, 96, 44.5, 83.2);
			}
			if (triangle == yes)
			{
				drawLine(29.66666, 76.8, 59.333333, 102.4);
			}
		}
		else if (length == 3 && startturndirection == 'r')
		{
			eraseRect(126.08333, 38.4, 140.91666, 12.8);
			drawRect(126.08333, 38.4, 140.91666, 12.8);
			if (exit == 2)
			{
				eraseEllipse(133.5, 70.4, 163.16666, 57.6);
				drawEllipse(133.5, 70.4, 163.16666, 57.6);
			}
			else if (exit == 3)
			{
				eraseEllipse(133.5, 96, 163.16666, 83.2);
				drawEllipse(133.5, 96, 163.16666, 83.2);
			}
			if (entrance == 2)
			{
				fillEllipse(133.5, 70.4, 163.16666, 57.6);
			}
			else if (entrance == 3)
			{
				fillEllipse(133.5, 96, 163.16666, 83.2);
			}
			if (triangle == yes)
			{
				drawLine(118.66666, 102.4, 148.33333, 76.8);
			}
		}
		entrance = 0;
		exit = 0;
		triangle = no;
		resetmotors();
		if (startturndirection == 'l')
		{
			resetmotors();
			turnDegrees('r', turntarget, motortarget, reversemotortarget);
			resetmotors();
		}
		else if (startturndirection == 'r')
		{
			resetmotors();
			turnDegrees('l', turntarget, reversemotortarget, motortarget);
			resetmotors();
		}
		eraseDisplay();
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
		resetmotors();
		while (nMotorEncoder[motorB] < circle/(wheeldiameter * PI) * grid)
		{
			motor[motorB] = motortarget;
			motor[motorC] = motortarget;
		}
		resetmotors();
		if (startturndirection == 'l')
		{
			resetmotors();
			turnDegrees('l', turntarget, reversemotortarget, motortarget);
			resetmotors();
		}
		else if (startturndirection == 'r')
		{
			resetmotors();
			turnDegrees('r', turntarget, motortarget, reversemotortarget);
			resetmotors();
		}
		sensorvalues();
		findgreen();
		if (SensorValue[S4] > walldistance)
		{
			resetmotors();
			while (nMotorEncoder[motorB] < circle/(wheeldiameter * PI) * grid && (l == no && r == no) && ((xvalue+yvalue+zvalue)/triple<silvervalue && (avalue+bvalue+cvalue)/triple<silvervalue))
			{
				motor[motorB] = motortarget;
				motor[motorC] = motortarget;
				sensorvalues();
				findgreen();
			}
			resetmotors();
			if (l == yes || r == yes)
			{
				resetmotors();
				while (nMotorEncoder[motorB] > circle/(wheeldiameter * PI) * (0 - halfgrid))
				{
					motor[motorB] = reversemotortarget;
					motor[motorC] = reversemotortarget;
				}
				resetmotors();
				exit = 2;
				array[2][0] = exitarray;
			}
			else if ((xvalue+yvalue+zvalue)/triple>=silvervalue || (avalue+bvalue+cvalue)/triple>=silvervalue)
			{
				resetmotors();
				while (nMotorEncoder[motorB] > circle/(wheeldiameter * PI) * (0 - halfgrid))
				{
					motor[motorB] = reversemotortarget;
					motor[motorC] = reversemotortarget;
				}
				resetmotors();
				entrance = 2;
				array[2][0] = entrancearray;
			}
		}
		else
		{
			array[2][0] = emptyarray;
		}
		if (startturndirection == 'l')
		{
			resetmotors();
			turnDegrees('r', turntarget, motortarget, reversemotortarget);
			resetmotors();
		}
		else if (startturndirection == 'r')
		{
			resetmotors();
			turnDegrees('l', turntarget, reversemotortarget, motortarget);
			resetmotors();
		}
		resetmotors();
		while (nMotorEncoder[motorB] < circle/(wheeldiameter * PI) * grid)
		{
			motor[motorB] = motortarget;
			motor[motorC] = motortarget;
		}
		resetmotors();
		if (startturndirection == 'l')
		{
			resetmotors();
			turnDegrees('l', turntarget, reversemotortarget, motortarget);
			resetmotors();
		}
		else if (startturndirection == 'r')
		{
			resetmotors();
			turnDegrees('r', turntarget, motortarget, reversemotortarget);
			resetmotors();
		}
		sensorvalues();
		findgreen();
		if (SensorValue[S4] > walldistance)
		{
			resetmotors();
			while (nMotorEncoder[motorB] < circle/(wheeldiameter * PI) * grid && (l == no && r == no) && ((xvalue+yvalue+zvalue)/triple<silvervalue && (avalue+bvalue+cvalue)/triple<silvervalue))
			{
				motor[motorB] = motortarget;
				motor[motorC] = motortarget;
				sensorvalues();
				findgreen();
			}
			resetmotors();
			if (l == yes || r == yes)
			{
				resetmotors();
				while (nMotorEncoder[motorB] > circle/(wheeldiameter * PI) * (0 - halfgrid))
				{
					motor[motorB] = reversemotortarget;
					motor[motorC] = reversemotortarget;
				}
				resetmotors();
				exit = 3;
				array[1][0] = exitarray;
			}
			else if ((xvalue+yvalue+zvalue)/triple>=silvervalue || (avalue+bvalue+cvalue)/triple>=silvervalue)
			{
				resetmotors();
				while (nMotorEncoder[motorB] > circle/(wheeldiameter * PI) * (0 - halfgrid))
				{
					motor[motorB] = reversemotortarget;
					motor[motorC] = reversemotortarget;
				}
				resetmotors();
				entrance = 3;
				array[1][0] = entrancearray;
			}
		}
		else
		{
			array[1][0] = emptyarray;
		}
		if (startturndirection == 'l')
		{
			resetmotors();
			turnDegrees('r', turntarget, motortarget, reversemotortarget);
			resetmotors();
		}
		else if (startturndirection == 'r')
		{
			resetmotors();
			turnDegrees('l', turntarget, reversemotortarget, motortarget);
			resetmotors();
		}
		if (SensorValue[S4] < walldistance)
		{
			length = 3;
		}
		else
		{
			sensorvalues();
			findgreen();
			resetmotors();
			while (nMotorEncoder[motorB] < circle/(wheeldiameter * PI) * grid && (l == no && r == no) && ((xvalue+yvalue+zvalue)/triple<silvervalue && (avalue+bvalue+cvalue)/triple<silvervalue))
			{
				motor[motorB] = motortarget;
				motor[motorC] = motortarget;
				sensorvalues();
				findgreen();
			}
			resetmotors();
			if (l == yes || r == yes)
			{
				resetmotors();
				while (nMotorEncoder[motorB] > circle/(wheeldiameter * PI) * (0 - halfgrid))
				{
					motor[motorB] = reversemotortarget;
					motor[motorC] = reversemotortarget;
				}
				resetmotors();
				array[1][0] = exitarray;
				if (length == 3 && startturndirection == 'l')
				{
					eraseEllipse(37.08333, 115.2, 51.91666, 89.6);
					drawEllipse(37.08333, 115.2, 51.91666, 89.6);
				}
				else if (length == 3 && startturndirection == 'r')
				{
					eraseEllipse(126.08333, 115.2, 140.91666, 89.6);
					drawEllipse(126.08333, 115.2, 140.91666, 89.6);
				}
			}
			else if ((xvalue+yvalue+zvalue)/triple>=silvervalue || (avalue+bvalue+cvalue)/triple>=silvervalue)
			{
				resetmotors();
				while (nMotorEncoder[motorB] > circle/(wheeldiameter * PI) * (0 - halfgrid))
				{
					motor[motorB] = reversemotortarget;
					motor[motorC] = reversemotortarget;
				}
				resetmotors();
				array[1][0] = entrancearray;
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
					resetmotors();
					turnDegrees('l', turntarget, reversemotortarget, motortarget);
					resetmotors();
				}
				else if (startturndirection == 'r')
				{
					resetmotors();
					turnDegrees('r', turntarget, motortarget, reversemotortarget);
					resetmotors();
				}
				sensorvalues();
				findgreen();
				if (SensorValue[S4] > walldistance)
				{
					resetmotors();
					while (nMotorEncoder[motorB] < circle/(wheeldiameter * PI) * grid && (l == no && r == no) && ((xvalue+yvalue+zvalue)/triple<silvervalue && (avalue+bvalue+cvalue)/triple<silvervalue))
					{
						motor[motorB] = motortarget;
						motor[motorC] = motortarget;
						sensorvalues();
						findgreen();
					}
					resetmotors();
					if (l == yes || r == yes)
					{
						resetmotors();
						while (nMotorEncoder[motorB] > circle/(wheeldiameter * PI) * (0 - halfgrid))
						{
							motor[motorB] = reversemotortarget;
							motor[motorC] = reversemotortarget;
						}
						resetmotors();
						exit = 4;
						array[0][0] = exitarray;
					}
					else if ((xvalue+yvalue+zvalue)/triple>=silvervalue || (avalue+bvalue+cvalue)/triple>=silvervalue)
					{
						resetmotors();
						while (nMotorEncoder[motorB] > circle/(wheeldiameter * PI) * (0 - halfgrid))
						{
							motor[motorB] = reversemotortarget;
							motor[motorC] = reversemotortarget;
						}
						resetmotors();
						entrance = 4;
						array[0][0] = entrancearray;
					}
				}
				else
				{
					array[0][0] = emptyarray;
				}
				if (startturndirection == 'l')
				{
					resetmotors();
					turnDegrees('r', turntarget, motortarget, reversemotortarget);
					resetmotors();
				}
				else if (startturndirection == 'r')
				{
					resetmotors();
					turnDegrees('l', turntarget, reversemotortarget, motortarget);
					resetmotors();
				}
				length = 4;
				sensorvalues();
				findgreen();
				if (SensorValue[S4] > walldistance)
				{
					resetmotors();
					while (nMotorEncoder[motorB] < circle/(wheeldiameter * PI) * grid && (l == no && r == no) && ((xvalue+yvalue+zvalue)/triple<silvervalue && (avalue+bvalue+cvalue)/triple<silvervalue))
					{
						motor[motorB] = motortarget;
						motor[motorC] = motortarget;
						sensorvalues();
						findgreen();
					}
					resetmotors();
					if (l == yes || r == yes)
					{
						resetmotors();
						while (nMotorEncoder[motorB] > circle/(wheeldiameter * PI) * (0 - halfgrid))
						{
							motor[motorB] = reversemotortarget;
							motor[motorC] = reversemotortarget;
						}
						resetmotors();
						array[0][0] = exitarray;
						if (length == 4 && startturndirection == 'l')
						{
							eraseEllipse(14.83333, 32, 44.5, 44.8);
							drawEllipse(14.83333, 32, 44.5, 44.8);
						}
						else if (length == 4 && startturndirection == 'r')
						{
							eraseEllipse(14.83333, 83.2, 44.5, 96);
							drawEllipse(14.83333, 83.2, 44.5, 96);
						}
					}
					else if ((xvalue+yvalue+zvalue)/triple>=silvervalue || (avalue+bvalue+cvalue)/triple>=silvervalue)
					{
						resetmotors();
						while (nMotorEncoder[motorB] > circle/(wheeldiameter * PI) * (0 - halfgrid))
						{
							motor[motorB] = reversemotortarget;
							motor[motorC] = reversemotortarget;
						}
						resetmotors();
						array[0][0] = entrancearray;
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
		}
		sensorvalues();
		if (xvalue<sensoraverage || avalue<sensoraverage)
		{
			triangle = yes;
		}
		else
		{
			triangle = no;
		}
		if (triangle == yes && length == 3)
		{
			array[1][0] = trianglearray;
		}
		else if (triangle == yes && length == 4)
		{
			array[0][0] = trianglearray;
		}

		if (length == 4 && startturndirection == 'l')
		{
			eraseRect(133.5, 32, 163.16666, 44.8);
			drawRect(133.5, 32, 163.16666, 44.8);
			if (exit == 2)
			{
				eraseEllipse(96.41666, 38.4, 111.25, 12.8);
				drawEllipse(96.41666, 38.4, 111.25, 12.8);
			}
			else if (exit == 3)
			{
				eraseEllipse(66.75, 38.4, 81.58333, 12.8);
				drawEllipse(66.75, 38.4, 81.58333, 12.8);
			}
			else if (exit == 4)
			{
				eraseEllipse(37.08333, 38.4, 51.91666, 12.8);
				drawEllipse(37.08333, 38.4, 51.91666, 12.8);
			}
			if (entrance == 2)
			{
				fillEllipse(96.41666, 38.4, 111.25, 12.8);
			}
			else if (entrance == 3)
			{
				fillEllipse(66.75, 38.4, 81.58333, 12.8);
			}
			else if (entrance == 4)
			{
				fillEllipse(37.08333, 38.4, 51.91666, 12.8);
			}
			if (triangle == yes)
			{
				drawLine(29.66666, 51.2, 59.333333, 25.6);
			}
		}
		else if (length == 4 && startturndirection == 'r')
		{
			eraseRect(133.5, 83.2, 163.16666, 96);
			drawRect(133.5, 83.2, 163.16666, 96);
			if (exit == 2)
			{
				eraseEllipse(96.41666, 115.2, 111.25, 89.6);
				drawEllipse(96.41666, 115.2, 111.25, 89.6);
			}
			else if (exit == 3)
			{
				eraseEllipse(66.75, 115.2, 81.58333, 89.6);
				drawEllipse(66.75, 115.2, 81.58333, 89.6);
			}
			else if (exit == 4)
			{
				eraseEllipse(37.08333, 115.2, 51.91666, 89.6);
				drawEllipse(37.08333, 115.2, 51.91666, 89.6);
			}
			if (entrance == 2)
			{
				fillEllipse(96.41666, 115.2, 111.25, 89.6);
			}
			else if (entrance == 3)
			{
				fillEllipse(66.75, 115.2, 81.58333, 89.6);
			}
			else if (entrance == 4)
			{
				fillEllipse(37.08333, 115.2, 51.91666, 89.6);
			}
			if (triangle == yes)
			{
				drawLine(29.66666, 76.8, 59.333333, 102.4);
			}
		}
		else if (length == 3 && startturndirection == 'l')
		{
			eraseRect(37.08333, 38.4, 51.91666, 12.8);
			drawRect(37.08333, 38.4, 51.91666, 12.8);
			if (exit == 2)
			{
				eraseEllipse(14.83333, 70.4, 44.5, 57.6);
				drawEllipse(14.83333, 70.4, 44.5, 57.6);
			}
			else if (exit == 3)
			{
				eraseEllipse(14.83333, 96, 44.5, 83.2);
				drawEllipse(14.83333, 96, 44.5, 83.2);
			}
			if (entrance == 2)
			{
				fillEllipse(14.83333, 70.4, 44.5, 57.6);
			}
			else if (entrance == 3)
			{
				fillEllipse(14.83333, 96, 44.5, 83.2);
			}
			if (triangle == yes)
			{
				drawLine(29.66666, 76.8, 59.333333, 102.4);
			}
		}
		else if (length == 3 && startturndirection == 'r')
		{
			eraseRect(126.08333, 38.4, 140.91666, 12.8);
			drawRect(126.08333, 38.4, 140.91666, 12.8);
			if (exit == 2)
			{
				eraseEllipse(133.5, 70.4, 163.16666, 57.6);
				drawEllipse(133.5, 70.4, 163.16666, 57.6);
			}
			else if (exit == 3)
			{
				eraseEllipse(133.5, 96, 163.16666, 83.2);
				drawEllipse(133.5, 96, 163.16666, 83.2);
			}
			if (entrance == 2)
			{
				fillEllipse(133.5, 70.4, 163.16666, 57.6);
			}
			else if (entrance == 3)
			{
				fillEllipse(133.5, 96, 163.16666, 83.2);
			}
			if (triangle == yes)
			{
				drawLine(118.66666, 102.4, 148.33333, 76.8);
			}
		}

		entrance = 0;
		exit = 0;
		triangle = no;
		resetmotors();
	}
	if (startturndirection == 'l')
	{
		resetmotors();
		turnDegrees('r', turntarget, motortarget, reversemotortarget);
		resetmotors();
	}
	else if (startturndirection == 'r')
	{
		resetmotors();
		turnDegrees('l', turntarget, reversemotortarget, motortarget);
		resetmotors();
	}
	eraseDisplay();
	for (int i = 0; i < sizeof(array)/sizeof(array[0]); i++)
	{
		for (int ii = 0; ii < sizeof(array[0])/sizeof(array[0][0]); ii++)
		{
			if (array[i][ii] > 0)
			{
				eraseDisplay();
				displayTextLine(4, "%i, %i, %i", i, ii, array[i][ii]);
				delay(5000);
			}
		}
	}
}
