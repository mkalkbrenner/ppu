// Markus Kalkbrenner 2020
// Note to self: Play more pinball!

#include <PPUCK.h>

PPUCK ppuck("PPUC-Arduino-1.0.0");

void setup() {
    ppuck.pupSerial()->setSerial(Serial);
    ppuck.pin2Dmd()->setSerial(Serial1);
    //ppuck.tiltAudio()->setSerial(Serial2);

    ppuck.switchMatrix()->registerSwitchAsEvent(3, 1, 31); // Borg Lock
    ppuck.switchMatrix()->registerSwitchAsEvent(6, 8, 68); // Shooter
    
    ppuck.eventDispatcher()->setCrossLinkSerial(Serial3);
    ppuck.eventDispatcher()->addListener(ppuck.pupSerial(), EVENT_SOURCE_ANY);
}

void loop() {
    ppuck.pin2Dmd()->update();

    if (ppuck.switchMatrix()->getOnce(68, /* ignore for further reads for milli seconds */ 200)) {
        ppuck.switchMatrix()->reset();
    }
}
