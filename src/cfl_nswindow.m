#import <Cocoa/Cocoa.h>

void setWindowTransparency(void *xid, unsigned char val) {
    NSWindow *win = (NSWindow *)xid;
    CGFloat alpha = ((CGFloat)val)/255.0;
    [win setAlphaValue:alpha];
    win.backgroundColor = NSColor.clearColor;
    [win setOpaque:NO];
}