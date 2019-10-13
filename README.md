# IDD-Fa19-Lab5
# Music Box

*A lab report by Vini Tripathii*

In this lab I created a music box: when the button is pushed, the ballerina begins to spin in rhythm with the song. 
The easiest part of this lab was probably the design of the music box itself. I used open source vector floral design and then used Adobe
to edited the designs and add them onto boxTall template pdf given to us. The hardest part was probably the code. This was challenging 
because the arduino processor can only do one thing at a time. The standard servo motor sweep uses a for loop, as does the playing a 
melody with the speaker. Thus, my intial design where I called seperate functions for the servo motor movement and the speaker to play 
music in the *void loop* resulted in each sequential execution instead of simultaneous. (This is scene in MusicBox.ino) 
The arduino processor could not run both loops for at once. 
Thus, to get the music to play at the same time as the ballerina spun, I rewrote both functions into the a single while loop and used 
seperate, previously declared variables control their progression. The while loop continued until every note of the song was played.Thus, everytime the loop ran, the motor moved while the note played. This also had the added bonus of giving the impression the ballerina was dancing to the music.
To get the motor to move in a sweeping movement, I created a flag variable that checked whether or not the servo had already reached 180
degrees -- if it had, the servo had to decrease (move in the opposite direction) until it reach zero before it could sweep forward again.
I also experimented with the number of degrees that should be added in each iteration of the loop and settled on 20; smaller increments were hard to notice. 
In a music box, every time the button is pressed the song restarts. To recreate that I began by taking the basic LED-ON design and using
a button, several flag variables and millis() -- a function that keeps tracks of the passing miliseconds -- so that when I pushed the button, the LED would turn on for a set amount of time and then automatically turn off. If the button was pressed again, the LED would turn 
on again.
I then expanded this basic framework to include the servo motor and speaker headphones. The final code that was used in the demo is
MusicBox2.ino

Here are two video's of the music box in action:
Tchaikovsky's Swan Lake:https://drive.google.com/file/d/1SDtanDW2EF9xu3KOIvH1cm2Td3b8dWyg/view?usp=sharing
Star War's Theme: https://drive.google.com/file/d/1GogaMLaw0csEqe0OMecpfb8omjKMvHu1/view?usp=sharing

I got the melody and noteDuration for the Star War's theme from a previous lab. I found a online sheet of Tachaikovsky's Swan Lake(https://www.music-scores.com/midi.php?sheetmusic=Tchaikovsky_Swan_Lake_easy_piano) and
converted it to the arduino format using online refferences(https://jythonmusic.me/ch-2-elements-of-music-and-code/). 
(I modified the pitches.h file to include a "rest" defination)

Photos are included in this repository
