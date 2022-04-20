
// Infinite loop
task main()
{
  while (1)  // or while (true)
  {
    playSound(soundBeepBeep);
    playSoundFile( "Woops.rso");
    wait1Msec(5000);
  }
}
