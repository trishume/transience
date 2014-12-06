#include "screensurface.h"
#include <Cocoa/Cocoa.h>

void ScreenSurface::platformSpecificSetup() {
    NSView *view = (NSView*)winId();
    NSWindow *win = [view window];
    [win setIgnoresMouseEvents:YES];
    win.level = NSScreenSaverWindowLevel;
}
