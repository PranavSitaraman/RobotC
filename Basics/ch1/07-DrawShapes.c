
// draw shapes
// Be resourceful - look up the available command "Display" from your Functions Window or Help.
// Modify this to alternate smiling and frowning

task main()
{
  displayBigTextLine(4, "Draw!");
  delay(1000);
	eraseDisplay();
  int topx=10, topy=60;
  int botx=80, boty=10;
	do
	{

  	drawEllipse(topx, topy, botx, boty);
  	delay(1000);
  	eraseEllipse(topx, topy, botx, boty);
  	topx++;
  	topy--;

	}	while (topx<botx && topy>boty);
}
