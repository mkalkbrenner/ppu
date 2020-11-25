// Markus Kalkbrenner 2020
// Note to self: Play more pinball!

#include <EffectsController.h>
// TaskScheduler needs to be included here, see https://github.com/arkhipenko/TaskScheduler/issues/51
#include <TaskScheduler.h>

EffectsController effectsController("PPUC-Teensy-0.1.0");

void setup() {
    effectsController.eventDispatcher()->setCrossLinkSerial(Serial8);
    effectsController.eventDispatcher()->addListener(effectsController.crossLinkDebugger());
}

void loop() {
    effectsController.eventDispatcher()->update();
}
