# code_challenge

I was challenged to make a video game for a job interview using SFML or SDL.
I took the chance to learn how SDL works and made this simple Slot Machine game.


I was required to have:
- a start button
- an insert credits button
- a take credits button
- a visible "credits inserted in" counter
- a visible "credits taken out" counter
- a visible "games played" counter
- at least 50 different objects moving in a pre-determined path
- each play costs one credit
- the games played counter must update only after the game is finished
- the star button should be able to pause and continue the game

### compiling

To compile the code on linux simply make sure you have SDL, SDL_Image and SDL_ttf installed, if not:

`sudo apt-get install libsdl2-dev`

`sudo apt-get install libsdl2-image-dev`

`sudo apt-get install libsdl2-ttf-dev`

And then just run the Makefile. As long as the assets folder is in the same folder as the binary file, the program should run fine.
