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

	float derivative = 0.0;

	float lastError = 0.0;

	float turn;

	float powerB;

	float powerC;

	int whitevalue = 55;

	int blackvalue = 5;

	int st = (whitevalue + blackvalue)/2;

	int mt = 40;

	float Kp = 5;

	float Ki = 0.000018;

	float Kd = 0.000018;

	while (true)

	{

		long x;

		long y;

		long z;

		getColorRGB(S2, x, y, z);

		error = x - st;

		integral = integral+error;

		derivative = error-lastError;

		turn = (Kp*error)+(Ki*integral)+(Kd*derivative);

		powerB = mt+turn;

		powerC = mt-turn;

		motor[motorB] = powerB;

		motor[motorC] = powerC;

		lastError = error;

	}

}
