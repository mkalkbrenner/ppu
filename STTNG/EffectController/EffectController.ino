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
        new PPUCNullEffect(),
        effectsController.nullDevice(),
        new PPUCEvent(1, 1),
        1,
        0,
        0
    );

    effectsController.addEffect(
         new PPUCLedBlinkEffect(),
         effectsController.ledBuiltInDevice(),
         new PPUCEvent(EVENT_SOURCE_SWITCH, 203),
         1,
         0,
         0
    );


    Serial.begin(9600); // USB is always 12 Mbit/sec
    Serial.println("hello");
    effectsController.eventDispatcher()->addListener(new PPUCCrossLinkDebugger(), EVENT_SOURCE_ANY);
    digitalWrite(LED_BUILTIN, HIGH);
}

void loop() {
    effectsController.eventDispatcher()->update();
}
