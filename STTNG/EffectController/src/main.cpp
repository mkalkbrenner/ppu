// Markus Kalkbrenner 2020
// Note to self: Play more pinball!

#include <PPUCDefinitions.h>

#define PPUC_NUM_LEDS_1 1
#define PPUC_LED_TYPE_1 SK6812_GRBW

#include <PPUCEffectsController.h>

PPUCEffectsController effectsController("Teensy4.1");

void setup() {
    // Debug
    Serial.begin(9600); // USB is always 12 Mbit/sec
    effectsController.eventDispatcher()->addListener(new PPUCCrossLinkDebugger());

    // Setup
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

    effectsController.addEffect(
         new PPUCWS2812FXRainbowCycle(),
         effectsController.ws2812SerialDevice(1),
//         effectsController.ws2812SerialOverlayDevice(1, 0, 0, 1),
         new PPUCEvent(EVENT_SOURCE_EFFECT, 1, 255), // controller start event
         1, // priority
         -1, // run endless
         0  // mode
    );

/*
    effectsController.addEffect(
            new PPUCRGBColorCycleEffect(1),
            effectsController.ws2812SerialDevice(1),
            new PPUCEvent(EVENT_SOURCE_EFFECT, 1, 255), // controller start event
            1, // priority
            -1, // run endless
            0  // mode
    );
*/

    // Start
    effectsController.start();
}

void loop() {
    effectsController.update();
}
