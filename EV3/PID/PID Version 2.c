#pragma config(Sensor, S2,     colorSensor,    sensorEV3_Color, modeEV3Color_RGB_Raw)
#pragma config(Sensor, S3,     colorSensor,    sensorEV3_Color, modeEV3Color_RGB_Raw)
#pragma config(Sensor, S4,     sonarSensor,    sensorEV3_Ultrasonic)
#pragma config(Motor,  motorA,          mediumMotor,   tmotorEV3_Medium, PIDControl, encoder)
#pragma config(Motor,  motorB,          leftMotor,     tmotorEV3_Large, PIDControl, driveLeft, encoder)
#pragma config(Motor,  motorC,          rightMotor,    tmotorEV3_Large, PIDControl, driveRight, encoder)

//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
	long x;
	long y;
	long z;
	long a;
	long b;
	long c;
	long q;
	long r;
	long s;
	long t;
	long u;
	long v;
	float offset;
	float Kp = 5;
	float Ki = 0.000018;
	float Kd = 0.000018;
	float Tp = 40;
	float error;
	float integral = 0.0;
	float derivative = 0.0;
	float lastError = 0.0;
	float turn;
	float powerB;
	float powerC;
	int tooLow;
	int tooHigh;
	getColorRGB(S2, x, y, z);
	tooLow = x;
	getColorRGB(S3, a, b, c);
	tooHigh = a;
	offset = (tooLow+tooHigh)/2;
	while(true)
	{
		getColorRGB(S2, q, r, s);
		getColorRGB(S3, t, u, v);
		error = (q + t)/2 - offset;
		integral = integral+error;
		derivative = error-lastError;
		turn = (Kp*error)+(Ki*integral)+(Kd*derivative);
		if (q<t)
		{
			powerB = Tp+turn;
			powerC = Tp-turn;
		}
		else
		{
			powerB = Tp-turn;
			powerC = Tp+turn;
		}
		motor[motorB] = powerB;
		motor[motorC] = powerC;
		lastError = error;
	}
}
