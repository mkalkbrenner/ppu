// Markus Kalkbrenner 2020
// Note to self: Play more pinball!

#include <PPUCEffectsController.h>
#include <PPUCEvent.h>
#include <PPUCLedBlinkEffect.h>
#include <PPUCNullEffect.h>
#include <PPUCCrossLinkDebugger.h>

PPUCEffectsController effectsController("Teensy4.1");

void setup() {
    effectsController.eventDispatcher()->setCrossLinkSerial(Serial8);

    effectsController.addEffect(
         new PPUCLedBlinkEffect(),
         effectsController.ledBuiltInDevice(),
         new PPUCEvent(EVENT_SOURCE_SWITCH, 203),
         1, // priority
         5, // repeat
         0  // mode
    );


    effectsController.addEffect(
         new PPUCNullEffect(),
         effectsController.ledBuiltInDevice(),
         new PPUCEvent(EVENT_SOURCE_SWITCH, 204),
         2, // priority
         0, // repeat
         0  // mode
    );

    Serial.begin(9600); // USB is always 12 Mbit/sec
    effectsController.eventDispatcher()->addListener(new PPUCCrossLinkDebugger());
}

void loop() {
    effectsController.update();
}
