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

    // There's one WS2812FXDevice ready to use for each LED port. Using createWS2812FXDevice() you can define additional
    // "virtual" WS2812FXDevice on a LED port to run independent effects on segments of the LED chain attached to that
    // port.
    effectsController.createWS2812FXDevice(
            1, // LED port
            0, // number of WS2812FX device, in total max 10 devices are allowed per LED port (counting starts with 0)
            1, // number of WS2812FX "segments" to assign to this device, in total max 10 segments are allowed per LED port
            0, // number of first LED in chain (counting starts with 0)
            0  // number of last LED in chain (counting starts with 0)
    );

    // Register effects
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
         new PPUCWS2812FXEffect(FX_MODE_BLINK, RED, 500, NO_OPTIONS),
         effectsController.ws2812FXDevice(/* port */ 1, /* device number */ 0),
         new PPUCEvent(EVENT_SOURCE_EFFECT, 1, 255), // controller start event
         1, // priority
         -1, // run endless
         0  // mode
    );

    // Start
    effectsController.start();
}

void loop() {
    effectsController.update();
}
