task main()
{
  int b;

  b = 5;

  if (b < 8600)
   nxtDisplayTextLine(2, "Nice Batt level: %d", b);
  else if (b < 4300)
    nxtDisplayTextLine(2, "Acceptable Batt: %d", b);
  else
    nxtDisplayTextLine(3, "Need to change:  %d", b);
  wait10Msec(500);
}
