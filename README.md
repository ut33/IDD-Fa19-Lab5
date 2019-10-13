# IDD-Fa19-Lab5
# Music Box

*A lab report by Vini Tripathii*

In this lab I created a music box: when the button is pushed, the ballerina begins to spin in rhythm with the song. 
The easiest part of this lab was probably the design of the music box itself. I used open source vector floral design and then used Adobe
to edited the designs and add them onto boxTall template pdf given to us. The hardest part was probably the code. This was challenging 
because the arduino processor can only do one thing at a time. The standard servo motor sweep uses a for loop, as does the playing a 
melody with the speaker. Thus, my intial design where I called seperate functions for the servo motor movement and the speaker to play 
music in the #void #loop resulted in each sequential execution instead of simultaneous. (This is scene in MusicBox.ino) 
The arduino processor could not run both loops for at once. 
Thus, to get the music to play at the same time as the ballerina spun, I rewrote both functions into the void loop and used previously 
seperate, previously declared variables control their progression. Thus, everytime the voidloop ran, the motor moved while the note played.
This also had the added bonus of making the motor move in time to the music, giving the impression the ballerina was dancing to the music.
