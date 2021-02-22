// Markus Kalkbrenner 2020
// Note to self: Play more pinball!

#include <PPUCInputController.h>
#include <PPUCCrossLinkDebugger.h>

PPUCInputController inputController("ArduinoMega");

void setup() {
    inputController.pupComLink()->setSerial(Serial);
    inputController.pin2Dmd()->setSerial(Serial1);
    //inputController.tiltAudio()->setSerial(Serial2);

    inputController.switchMatrix()->registerFieldAsEvent(3, 1, 31); // Borg Lock
    inputController.switchMatrix()->registerFieldAsEvent(6, 8, 68); // Shooter

    inputController.lightMatrix()->registerAllFieldsAsEvent("WPC");

    inputController.eventDispatcher()->setCrossLinkSerial(Serial3);
    inputController.eventDispatcher()->addListener(inputController.pupComLink(), EVENT_SOURCE_ANY);

    inputController.switchMatrix()->start();
    inputController.lightMatrix()->start();

    inputController.eventDispatcher()->addListener(new PPUCCrossLinkDebugger(), EVENT_SOURCE_ANY);
}

void loop() {
    // read data
    inputController.pin2Dmd()->update();
    inputController.switchMatrix()->update();
    inputController.lightMatrix()->update();
    inputController.testButtons()->update();

    // handle data
    inputController.eventDispatcher()->update();
}
