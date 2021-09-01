#import <Cocoa/Cocoa.h>

void setWindowTransparency(void *xid, unsigned char val) {
    NSWindow *win = (NSWindow *)xid;
    CGFloat alpha = ((CGFloat)val)/255.0;
    [win setAlphaValue:alpha];
    win.backgroundColor = NSColor.clearColor;
    [win setOpaque:NO];
}

NSView *my_getContentView(void *xid) {
    NSWindow *win = (NSWindow *)xid;
    return [win contentView];
}

double my_getScalingFactor(void *xid) {
    NSWindow *win = (NSWindow *)xid;
    return [win backingScaleFactor];
}