// Markus Kalkbrenner 2020
// Note to self: Play more pinball!

#include <PPUCEffectsController.h>
#include <PPUCEvent.h>
#include <PPUCNullEffect.h>

PPUCEffectsController effectsController("Teensy4.1");

void setup() {
    effectsController.eventDispatcher()->setCrossLinkSerial(Serial1);
    effectsController.eventDispatcher()->addListener(effectsController.crossLinkDebugger());

    effectsController.addEffect(
        new PPUCNullEffect(),
        effectsController.nullDevice(),
        new PPUCEvent(1, 1),
        1,
        0,
        0
    );
}

void loop() {
    effectsController.eventDispatcher()->update();
}
