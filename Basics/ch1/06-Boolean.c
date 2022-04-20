
//Remember :
// Be inquisitive.
//
// This program shows you the battery capacity remained.

task main()
{
  int level;

  level = nAvgBatteryLevel;  // save battery capacity remained in a local variable "level"

  if (level > 8600)
   displayTextLine(2, "Fresh Battery: %d", level);
  else if (level > 8300)
   displayTextLine(2, "Good Batt level: %d", level);
  else if (level > 7500)
    displayTextLine(2, "Acceptable Batt: %d", level);
  else
    displayTextLine(3, "Should change:  %d", level);

   wait1Msec(1000);  // same as sleep(), or delay() function
}
