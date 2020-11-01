// Markus Kalkbrenner 2020
// Note to self: Play more pinball!

#include <PPUCK.h>

PPUCK ppuck("PPUC-Arduino-1.0.0");

void setup() {
    ppuck.pupComLink()->setSerial(Serial);
    ppuck.pin2Dmd()->setSerial(Serial1);
    //ppuck.tiltAudio()->setSerial(Serial2);

    ppuck.switchMatrix()->registerFieldAsEvent(3, 1, 31); // Borg Lock
    ppuck.switchMatrix()->registerFieldAsEvent(6, 8, 68); // Shooter
    
    ppuck.lightMatrix()->registerAllFieldsAsEvent("WPC");

    ppuck.eventDispatcher()->setCrossLinkSerial(Serial3);
    ppuck.eventDispatcher()->addListener(ppuck.pupComLink(), EVENT_SOURCE_ANY);

    ppuck.switchMatrix()->start();
    ppuck.lightMatrix()->start();
}

void loop() {
    // read data
    ppuck.pin2Dmd()->update();
    ppuck.switchMatrix()->update();
    ppuck.lightMatrix()->update();

    // handle data
    ppuck.eventDispatcher()->update();
}
