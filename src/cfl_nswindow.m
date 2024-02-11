#include <AppKit/NSWindow.h>
#import <Cocoa/Cocoa.h>

void cfltk_setWindowTransparency(void *xid, unsigned char val) {
  NSWindow *win = (NSWindow *)xid;
  CGFloat alpha = ((CGFloat)val) / 255.0;
  [win setAlphaValue:alpha];
  win.backgroundColor = NSColor.clearColor;
  [win setOpaque:NO];
}

NSView *cfltk_getContentView(void *xid) {
  NSWindow *win = (NSWindow *)xid;
  return [win contentView];
}

double cfltk_getScalingFactor(void *xid) {
  NSWindow *win = (NSWindow *)xid;
  NSView *view = [win contentView];
  NSSize s = [view convertSizeToBacking:NSMakeSize(10, 10)];
  int scale = ((int)(s.width + 0.5) > 10 ? 2 : 1);
  return (double)scale;
}

void cfltk_winShow(void *xid) {
  NSWindow *win = (NSWindow *)xid;
  [win makeKeyAndOrderFront:win];
  [NSApp activateIgnoringOtherApps:YES];
}

void cfltk_winHide(void *xid) {
  NSWindow *win = (NSWindow *)xid;
  [win orderOut:win];
}

void cfltk_setOnTop(void *xid) {
  NSWindow *win = (NSWindow *)xid;
  [win setLevel:NSMainMenuWindowLevel + 2];
}