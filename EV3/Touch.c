#pragma config(Sensor, S1,     Touch,          sensorEV3_Touch)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

void P1 (int n) {
	int x = 0;
	int y;
	while(x<n)
	{
		y = x + 1;
		displayTextLine (x, "%d", y);
		x++;
	}
}

void P2 (int n) {
	int x = 5;
	int y = 0;
	while(x>0)
	{
		displayTextLine (y, "%d", x);
		x--;
		y++;
	}
}

void P3 (int n) {
	int x = 0;
	int y;
	int z = 0;
	while(x<n)
	{
		y = x + 1;
		z = z + y;
		displayTextLine (x, "%d  %d", y,z);
		x++;
	}
}

void P4 (int n) {
	int x = 0;
	int y;
	int z = 1;
	while(x<n)
	{
		y = x + 1;
		z = z * y;
		displayTextLine (x, "%d  %d", y,z);
		x++;
	}
}

void P5 (int n) {
	int x = 0;
	int y = 0.1;
	while(x<n+1)
	{
		y = y * 10 + x;
		displayTextLine (x-1, "%d%d", y);
		x++;
	}
}

void P6 (int n) {
	int x = 0;
	while(x<n)
	{
		if (SensorValue(S1) == 1)
		{
			displayTextLine(x, "%d pressed", x++);
			x++;
		}
		else
		{
		}
	}
}

task main()
	{
		P6(10);
	}
