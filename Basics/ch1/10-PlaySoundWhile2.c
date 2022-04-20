
// modification:  change the program beeps only 5 times
task main()
{
	int ct=0;
  while (ct < 5)
  {
    playSoundFile( "Woops.rso");
    wait1Msec(1500);
    ++ct;
  }
}
