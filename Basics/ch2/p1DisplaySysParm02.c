// this program will display all minute, sec, and millisecond from Program and System Time
task main()
{
	string str="";
	int pMsec, sMsec, pSec, sSec, pMin, sMin;
	float batt;

	while (true)
	{
		pMsec = nPgmTime %1000;
		pSec = nPgmTime/1000%60;
		pMin = nPgmTime/1000/60;
		{
			nxtDisplayTextLine(0, "%d", nPgmTime);
			sprintf(str, "Prog- %03d:%02d:%03d", pMin, pSec, pMsec);
			nxtDisplayTextLine(1, "%s", str);
		}
		sMsec = nSysTime%1000;
		sSec = nSysTime/1000%60;
		sMin = nSysTime/1000/60;

		nxtDisplayTextLine(3, "%d", nSysTime);
		sprintf(str, "Sys- %03d:%02d:%03d", sMin, sSec, sMsec);
		nxtDisplayTextLine(4, "%s", str);

		batt= (float) nAvgBatteryLevel/1000;
		nxtDisplayTextLine(6, "Batt: %4.2f", batt);

		wait1Msec(10000);
	}
}
