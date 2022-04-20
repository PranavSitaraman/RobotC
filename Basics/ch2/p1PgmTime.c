
// program will stay running for 30 seconds

task main()
{ int beginAt = 0;
  int diff=0; // 30 seconds max

  beginAt = nPgmTime; // in milliseconds
  diff = (nPgmTime - beginAt) / 1000;
  while (diff < 30)
  {
    nxtDisplayTextLine(1, "Secs Left: %d", 30-diff);
    diff = (nPgmTime - beginAt)/1000;
  }
  nxtDisplayTextLine(1, "Over!");
  playSound(soundDownwardTones);
  while (bSoundActive)
    wait1Msec(10);
  //---------or the following will do the same thing ------------------------
  /*
  for (diff=0;diff < 30;  diff=(nPgmTime - beginAt)/1000 )
  {
    nxtDisplayTextLine(1, "Secs Left:%d", 30-diff);
  }
  nxtDisplayTextLine(1, "Over!");
  PlaySound(soundDownwardTones);
  while (bSoundActive)
    wait1Msec(10);
  */
}
