
// This program will play the sound "Woops" 4 times with 1 sec interval.
// Then, it will play a FastUpwardTone  4 times with 1 sec interval.
// IMPORTANT:  Observe the difference between two sets of loops.
//
// Question after you done;
// what happens if  "ct = 0;"  is not in the code?
// Answer: there would be no starting value for ct, and so there would be an error (with ct being undefined)

task main()
{
	int ct=0;

	while (ct < 4)  // while it is less than 4
  {
    playSoundFile( "Woops.rso");
    delay(1000);
    displayTextLine(ct, "woops");
    ct = ct + 1;  // have to add 1 for each loop.
  }
  ct = 0;         // must reset.
  while (ct++ < 4)
  {
    playSound(soundFastUpwardTones);
    delay(1000);
    displayTextLine(ct, "!FastTone");
  }
}
