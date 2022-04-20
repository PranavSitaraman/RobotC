task main()
{
	int x = 1;
while(x<=4)
{
motor[motorB] = 50;
motor[motorC] = 50;
delay(2250);
motor[motorC] = 0;
delay(1050);
x=x + 1;
}
}
