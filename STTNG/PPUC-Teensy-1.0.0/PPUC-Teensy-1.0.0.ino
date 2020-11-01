// Markus Kalkbrenner 2020
// Note to self: Play more pinball!

#include <PPUCK.h>

PPUCK ppuck("PPUC-Teensy-1.0.0");
CrossLinkDebugger crossLinkDebugger();

void setup() {
    ppuck.eventDispatcher()->setCrossLinkSerial(Serial8);
    ppuck.eventDispatcher()->addListener(crossLinkDebugger, EVENT_SOURCE_ANY);
}

void loop() {
    ppuck.eventDispatcher()->update();
}
