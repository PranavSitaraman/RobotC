
// modification:  change the program beeps only 5 times
task main()
{
	int i = 1;
  while (i<=5)
  {
    playSound(soundBeepBeep);
    playSoundFile( "Woops.rso");
    i++;
    delay(5000);
  }
}
