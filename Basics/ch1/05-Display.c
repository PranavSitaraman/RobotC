
// nSysTime is an RobotC instrinsic variable to tell millisseconds since the controller
// has been turned on .
// This program will indicate how long your brick has been turned on.

task main()
{
  if (nSysTime< 10000)
    displayTextLine(1, "I am just awake.");
  else if (nSysTime < 100000)
    displayTextLine(1, "I am busy at work.");
  else if (nSysTime < 1000000)
    displayTextLine(1, "I am still busy at work.");
  else if (nSysTime < 10000000)
    displayTextLine(1, "I need a Break!");
  else
  {  displayTextLine(1, "ShutDown in 5 secs!");
  	// if you are using EV3, let's not do that as it takes 20+ secs to power EV3 back up.
    // powerOff();
  }
  delay(5000);
}
