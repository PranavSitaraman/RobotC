task main()
{
int x=5082;

  float fx = (float)x/10000 * 60;
  nxtDisplayTextLine(4, "%d %f", x, fx);
  wait10Msec(1000);
}
