Duke Nukem 3D *SDL* for PSP source port revision by Nick [MrPeanut] Cavallo
===========================================================================

Special thanks to 3dRealms, StereoMike (for the original PSP port) and anyone else who helped
make duke nukem 3d on the PSP possible.


Notes on this "release":


This is NOT complete.  I won't assign it a version number or anything like that, it's far from done.
The only thing I wanted to address was the save/load problem and give the people a version of
duke nukem where they could actually play through the game.

This is my developer build of duke nukem 3d, from Stereomike's port.  I've sort of made some
"hacks" to the code to allow the saving/loading of files.  By hacks I mean "workarounds" even
though I will fix them in the future, I want to show the community that the project is actually being worked
on, and more improvements are underway.

I'll make a short description of the modifications to the code in lamens terms, and what the effects 
mean to us.

The unmodified code of duke3d uses two functions named, saveplayer and loadplayer to read/write
information from the game#.sav files.  The stock functions add a lot of additional data to the save
files that in the case of the psp port made the game hang with the light on the memory stick (in use) on.  I patched the code so 
it doesn't write this additional data and it starts a NEW GAME every time the load
operation is initialized.

WHAT THAT MEANS TO YOU:

When you load a game, you will start from the beginning of the map you're currently playing.  It is, in essence, a
NEW GAME, but a new game on the map you've been playing.  The extra information that was included in the original are things
like health, weapons, script actions, etc.  When you load a save file, you will start on the level that you were playing
when you saved it on, but all of the flags will be reset.. The positive is that you'll be able to atleast save the map where
you left off on but not the location to a pinpoint (hell, it's better than playing the game from the first level from scratch again).

Anyway, I'm ranting.  More fixes are in the works.  I haven't had too much time to work on this but more improvements are underway.

Thanks, and have fun playing!

Nick [MrPeanut] Cavallo 