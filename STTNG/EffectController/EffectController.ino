// Markus Kalkbrenner 2020
// Note to self: Play more pinball!

#include <EffectsController.h>
// TaskScheduler needs to be included here, see https://github.com/arkhipenko/TaskScheduler/issues/51
#include <TaskScheduler.h>

PPUCEffectsController effectsController("Teensy4.3");

void setup() {
    effectsController.eventDispatcher()->setCrossLinkSerial(Serial8);
    effectsController.eventDispatcher()->addListener(effectsController.crossLinkDebugger());

    // Test UV lights
    effectsController.uv()->fadeIn(1000);
    delay(2000);
    effectsController.uv()->fadeOut(1000);
}

void loop() {
    effectsController.eventDispatcher()->update();
}
