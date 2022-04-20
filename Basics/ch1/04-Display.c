
// nSysTime is an RobotC instrinsic variable to tell millisseconds since the controller
// has been turned on .
// nPgmTime is an RobotC instrinsic variable to tell millisseconds since this program
// has been turned on .
// This program shows you the timer - one for the system, one for your program

task main()
{
	displayTextLine(3, "Sys Awake:%d", nSysTime);
  displayTextLine(4, "Pgm Awake:%d", nPgmTime);
  sleep(3000);
  displayTextLine(6, "Sys Awake:%d", nSysTime);
  displayTextLine(7, "Pgm Awake:%d", nPgmTime);
  sleep(3000);
  displayTextLine(3, "Sys Awake:%d", nSysTime);
  displayTextLine(4, "Pgm Awake:%d", nPgmTime);
  sleep(3000);
}
