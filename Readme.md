# Transience

Transience is a WIP daemon for displaying overlays on the screen that can be used by other programs for fancy OS control
and window management operations.

It's written in Qt and will be controlled by other programs using dbus.

## Example Applications

### Window Hints

Displaying app icons along with a letter so that the user can switch windows quickly.

See my other project [mjolnir.th.hints](//github.com/trishume/mjolnir.th.hints) for an example of what this is like.

### Eye Tracking Pointers

This is my personal main intended use. I have an [eye tracker](https://theeyetribe.com/) that is just imprecise enough
to make a poor direct method of clicking. My plan is to use the OSX accessibility API to find clickable things near where
I'm looking and the use this program to display subtle translucent colored dots over them, I can then hit a key on my keyboard
corresponding to the color of the dot to click that item.
