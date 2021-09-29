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
    NSView *view = [win contentView];
    NSSize s = [view convertSizeToBacking:NSMakeSize(10, 10)];
    double scale = (s.width + 0.5) > 10.0 ? 2.0 : 1.0;
    return scale;
}