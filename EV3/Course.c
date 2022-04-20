#pragma config(Sensor, S2,     colorSensor,    sensorEV3_Color, modeEV3Color_RGB_Raw)
#pragma config(Sensor, S3,     colorSensor,    sensorEV3_Color, modeEV3Color_RGB_Raw)
#pragma config(Sensor, S4,     sonarSensor,    sensorEV3_Ultrasonic)
#pragma config(Motor,  motorB,          leftMotor,     tmotorEV3_Large, PIDControl, driveLeft, encoder)
#pragma config(Motor,  motorC,          rightMotor,    tmotorEV3_Large, PIDControl, driveRight, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//
task main()
{
	float Kp = 6;
	float Ki = 0.01;
	float Kd = 0.1;
	float leftgreenlower = 2.75;
	float leftgreenupper = 4.25;
	float rightgreenlower = 1.25;
	float rightgreenupper = 2.75;
	float integraluplimit = 50.0;
	float taruplimit = 10;
	float motortarget = 30.0;
	float leftvalue = 60.0;
	float rightvalue = 63.0;
	float tardownlimit = 0.0 - taruplimit;
	float integraldownlimit = 0.0 - integraluplimit;
	float integral = 0.0;
	float integraltarget = 0.0;
	float derivative = 0.0;
	float derivativesetpoint = 0.0;
	float lastError = 0.0;
	float error;
	float turn;
	float powerB;
	float powerC;
	float tar = leftvalue-rightvalue;
	float l;
	float r;
	float yes = 1.0;
	float no = 0.0;
	long x;
	float xvalue;
	float yvalue;
	float zvalue;
	long y;
	long z;
	long a;
	float avalue;
	float bvalue;
	float cvalue;
	long b;
	long c;
	float straighttarget = 360/(1.2 * PI) * 0.79;
	float turnaroundtarget = (90 * 7.5/1.2);
	float turntarget = (40 * 7.5/1.2);
	float turntarget2 = (10 * 7.5/1.2);
	while (true)
	{
		while (l == no & r == no)
		{
			if (tardownlimit<xvalue-avalue & xvalue-avalue<taruplimit)
			{
				tar = xvalue - avalue;
			}
			else
			{
				tar = leftvalue-rightvalue;
			}
			error = xvalue - avalue - tar;
			integral = integral+error;
			if (error < derivativesetpoint)
			{
				derivative = derivativesetpoint - (fabs(error - lastError))/2;
			}
			else
			{
				derivative = (fabs(error - lastError))/2;
			}
			turn = (Kp*error)+(Ki*integral)+(Kd*derivative);
			powerB = motortarget+turn;
			powerC = motortarget-turn;
			motor[motorB] = powerB;
			motor[motorC] = powerC;
			lastError = error;
			if (integral > integraluplimit)
			{
				integral = integraltarget;
			}
			else
			{
				if (integral<integraldownlimit)
				{
					integral = integraltarget;
				}
				else
				{
				}
			}
			getColorRGB(S2, x, y, z);
			getColorRGB(S3, a, b, c);
			xvalue = (float)(x);
			yvalue = (float)(y);
			zvalue = (float)(z);
			avalue = (float)(a);
			bvalue = (float)(b);
			cvalue = (float)(c);
			if ((yvalue + 0.01)/(zvalue + 0.01) > (leftgreenlower) & (yvalue + 0.01)/(zvalue + 0.01) < (leftgreenupper) & yvalue>20)
			{
				l = yes;
			}
			else
			{
				l = no;
			}
			if ((bvalue + 0.01)/(cvalue + 0.01) > (rightgreenlower) & (bvalue + 0.01)/(cvalue + 0.01) < (rightgreenupper) & bvalue>20)
			{
				r = yes;
			}
			else
			{
				r = no;
			}
		}
		if (l == yes & r == yes)
		{
			displayTextLine (4, "%d" "%d", yes, yes);
			motor[motorB] = 0;
			motor[motorC] = 0;
			nMotorEncoder[motorB] = 0;
			nMotorEncoder[motorC] = 0;
			while(nMotorEncoder[motorB] < straighttarget)
			{
				motor[motorB] = 30;
				motor[motorC] = 30;
			}
			motor[motorB] = 0;
			motor[motorC] = 0;
			nMotorEncoder[motorB] = 0;
			nMotorEncoder[motorC] = 0;
			getColorRGB(S2, x, y, z);
			getColorRGB(S3, a, b, c);
			xvalue = (float)(x);
			yvalue = (float)(y);
			zvalue = (float)(z);
			avalue = (float)(a);
			bvalue = (float)(b);
			cvalue = (float)(c);
			if (xvalue<20 & avalue < 20)
			{
				motor[motorB] = 0;
				motor[motorC] = 0;
				nMotorEncoder[motorB] = 0;
				nMotorEncoder[motorC] = 0;
				while(nMotorEncoder[motorB] < turnaroundtarget)
				{
					motor[motorB] = 30;
					motor[motorC] = -30;
				}
				motor[motorB] = 0;
				motor[motorC] = 0;
				nMotorEncoder[motorB] = 0;
				nMotorEncoder[motorC] = 0;
				while(nMotorEncoder[motorB] < straighttarget)
				{
					motor[motorB] = 30;
					motor[motorC] = 30;
				}
				motor[motorB] = 0;
				motor[motorC] = 0;
				nMotorEncoder[motorB] = 0;
				nMotorEncoder[motorC] = 0;
				getColorRGB(S2, x, y, z);
				getColorRGB(S3, a, b, c);
				xvalue = (float)(x);
				yvalue = (float)(y);
				zvalue = (float)(z);
				avalue = (float)(a);
				bvalue = (float)(b);
				cvalue = (float)(c);
				l = no;
				r = no;
			}
			else
			{
				getColorRGB(S2, x, y, z);
				getColorRGB(S3, a, b, c);
				xvalue = (float)(x);
				yvalue = (float)(y);
				zvalue = (float)(z);
				avalue = (float)(a);
				bvalue = (float)(b);
				cvalue = (float)(c);
				l = no;
				r = no;
			}
		}
		else
		{
			if (l == yes & r == no)
			{
				displayTextLine (4, "%d" "%d", yes, no);
				motor[motorB] = 0;
				motor[motorC] = 0;
				nMotorEncoder[motorB] = 0;
				nMotorEncoder[motorC] = 0;
				while(nMotorEncoder[motorB] < straighttarget)
				{
					motor[motorB] = 30;
					motor[motorC] = 30;
				}
				motor[motorB] = 0;
				motor[motorC] = 0;
				nMotorEncoder[motorB] = 0;
				nMotorEncoder[motorC] = 0;
				getColorRGB(S2, x, y, z);
				getColorRGB(S3, a, b, c);
				xvalue = (float)(x);
				yvalue = (float)(y);
				zvalue = (float)(z);
				avalue = (float)(a);
				bvalue = (float)(b);
				cvalue = (float)(c);
				if (xvalue<20)
				{
					motor[motorB] = 0;
					motor[motorC] = 0;
					nMotorEncoder[motorB] = 0;
					nMotorEncoder[motorC] = 0;
					while(nMotorEncoder[motorC] < turntarget)
					{
						motor[motorC] = 30;
						motor[motorB] = -30;
					}
					motor[motorB] = 0;
					motor[motorC] = 0;
					nMotorEncoder[motorB] = 0;
					nMotorEncoder[motorC] = 0;
					while(nMotorEncoder[motorB] < straighttarget)
					{
						motor[motorB] = 30;
						motor[motorC] = 30;
					}
					motor[motorB] = 0;
					motor[motorC] = 0;
					nMotorEncoder[motorB] = 0;
					nMotorEncoder[motorC] = 0;
					getColorRGB(S2, x, y, z);
					getColorRGB(S3, a, b, c);
					xvalue = (float)(x);
					yvalue = (float)(y);
					zvalue = (float)(z);
					avalue = (float)(a);
					bvalue = (float)(b);
					cvalue = (float)(c);
					l = no;
					r = no;
				}
				else
				{
					motor[motorB] = 0;
					motor[motorC] = 0;
					nMotorEncoder[motorB] = 0;
					nMotorEncoder[motorC] = 0;
					getColorRGB(S2, x, y, z);
					getColorRGB(S3, a, b, c);
					xvalue = (float)(x);
					yvalue = (float)(y);
					zvalue = (float)(z);
					avalue = (float)(a);
					bvalue = (float)(b);
					cvalue = (float)(c);
					if (xvalue>20 & avalue>20)
					{
						motor[motorB] = 0;
						motor[motorC] = 0;
						nMotorEncoder[motorB] = 0;
						nMotorEncoder[motorC] = 0;
						while(nMotorEncoder[motorB] > (0 - (straighttarget)))
						{
							motor[motorB] = -30;
							motor[motorC] = -30;
						}
						motor[motorB] = 0;
						motor[motorC] = 0;
						nMotorEncoder[motorB] = 0;
						nMotorEncoder[motorC] = 0;
						while(nMotorEncoder[motorC] < turntarget2)
						{
							motor[motorC] = 30;
							motor[motorB] = -30;
						}
						motor[motorB] = 0;
						motor[motorC] = 0;
						nMotorEncoder[motorB] = 0;
						nMotorEncoder[motorC] = 0;
						while(nMotorEncoder[motorB] < straighttarget)
						{
							motor[motorB] = 30;
							motor[motorC] = 30;
						}
						motor[motorB] = 0;
						motor[motorC] = 0;
						nMotorEncoder[motorB] = 0;
						nMotorEncoder[motorC] = 0;
					}
					getColorRGB(S2, x, y, z);
					getColorRGB(S3, a, b, c);
					xvalue = (float)(x);
					yvalue = (float)(y);
					zvalue = (float)(z);
					avalue = (float)(a);
					bvalue = (float)(b);
					cvalue = (float)(c);
					l = no;
					r = no;
				}
			}
			else
			{
				if (l == no & r == yes)
				{
					displayTextLine (4, "%d" "%d", no, yes);
					motor[motorB] = 0;
					motor[motorC] = 0;
					nMotorEncoder[motorB] = 0;
					nMotorEncoder[motorC] = 0;
					while(nMotorEncoder[motorB] < straighttarget)
					{
						motor[motorB] = 30;
						motor[motorC] = 30;
					}
					motor[motorB] = 0;
					motor[motorC] = 0;
					nMotorEncoder[motorB] = 0;
					nMotorEncoder[motorC] = 0;
					getColorRGB(S2, x, y, z);
					getColorRGB(S3, a, b, c);
					xvalue = (float)(x);
					yvalue = (float)(y);
					zvalue = (float)(z);
					avalue = (float)(a);
					bvalue = (float)(b);
					cvalue = (float)(c);
					if (avalue < 20)
					{
						motor[motorB] = 0;
						motor[motorC] = 0;
						nMotorEncoder[motorB] = 0;
						nMotorEncoder[motorC] = 0;
						while(nMotorEncoder[motorB] < turntarget)
						{
							motor[motorB] = 30;
							motor[motorC] = -30;
						}
						motor[motorB] = 0;
						motor[motorC] = 0;
						nMotorEncoder[motorB] = 0;
						nMotorEncoder[motorC] = 0;
						while(nMotorEncoder[motorB] < straighttarget)
						{
							motor[motorB] = 30;
							motor[motorC] = 30;
						}
						motor[motorB] = 0;
						motor[motorC] = 0;
						nMotorEncoder[motorB] = 0;
						nMotorEncoder[motorC] = 0;
						getColorRGB(S2, x, y, z);
						getColorRGB(S3, a, b, c);
						xvalue = (float)(x);
						yvalue = (float)(y);
						zvalue = (float)(z);
						avalue = (float)(a);
						bvalue = (float)(b);
						cvalue = (float)(c);
						l = no;
						r = no;
					}
					else
					{
						motor[motorB] = 0;
						motor[motorC] = 0;
						nMotorEncoder[motorB] = 0;
						nMotorEncoder[motorC] = 0;
						getColorRGB(S2, x, y, z);
						getColorRGB(S3, a, b, c);
						xvalue = (float)(x);
						yvalue = (float)(y);
						zvalue = (float)(z);
						avalue = (float)(a);
						bvalue = (float)(b);
						cvalue = (float)(c);
						if (xvalue>20 & avalue>20)
						{
							motor[motorB] = 0;
							motor[motorC] = 0;
							nMotorEncoder[motorB] = 0;
							nMotorEncoder[motorC] = 0;
							while(nMotorEncoder[motorB] > (0 - (straighttarget)))
							{
								motor[motorB] = -30;
								motor[motorC] = -30;
							}
							motor[motorB] = 0;
							motor[motorC] = 0;
							nMotorEncoder[motorB] = 0;
							nMotorEncoder[motorC] = 0;
							while(nMotorEncoder[motorB] < turntarget2)
							{
								motor[motorC] = -30;
								motor[motorB] = 30;
							}
							motor[motorB] = 0;
							motor[motorC] = 0;
							nMotorEncoder[motorB] = 0;
							nMotorEncoder[motorC] = 0;
							while(nMotorEncoder[motorB] < straighttarget)
							{
								motor[motorB] = 30;
								motor[motorC] = 30;
							}
							motor[motorB] = 0;
							motor[motorC] = 0;
							nMotorEncoder[motorB] = 0;
							nMotorEncoder[motorC] = 0;
						}
						getColorRGB(S2, x, y, z);
						getColorRGB(S3, a, b, c);
						xvalue = (float)(x);
						yvalue = (float)(y);
						zvalue = (float)(z);
						avalue = (float)(a);
						bvalue = (float)(b);
						cvalue = (float)(c);
						l = no;
						r = no;
					}
				}
				else
				{
					displayTextLine (4, "%d" "%d", no, no);
					motor[motorB] = 0;
					motor[motorC] = 0;
					nMotorEncoder[motorB] = 0;
					nMotorEncoder[motorC] = 0;
					while(nMotorEncoder[motorB] < straighttarget)
					{
						motor[motorB] = 30;
						motor[motorC] = 30;
					}
					motor[motorB] = 0;
					motor[motorC] = 0;
					nMotorEncoder[motorB] = 0;
					nMotorEncoder[motorC] = 0;
					getColorRGB(S2, x, y, z);
					getColorRGB(S3, a, b, c);
					xvalue = (float)(x);
					yvalue = (float)(y);
					zvalue = (float)(z);
					avalue = (float)(a);
					bvalue = (float)(b);
					cvalue = (float)(c);
					l = no;
					r = no;
				}
			}
		}
		l = no;
		r = no;
	}
}
