// Markus Kalkbrenner 2020
// Note to self: Play more pinball!

#include <PPUCEffectsController.h>
#include <PPUCEvent.h>
#include <PPUCEffects/PPUCLedBlinkEffect.h>
#include <PPUCEffects/PPUCNullEffect.h>
#include <PPUCEffects/PPUCRGBColorCycleEffect.h>
#include <PPUCCrossLinkDebugger.h>

const int   ws2812NumLeds1 = 1;                        // number of LEDs
const int   ws2812Type1    = WS2812_GRBW;              // type of LEDs
byte        ws2812DrawingMemory1[ws2812NumLeds1 * 4];  // 3 bytes per LED for RGB, 4 bytes for RGBW
DMAMEM byte ws2812DisplayMemory1[ws2812NumLeds1 * 16]; // 12 bytes per LED for RGB, 16 bytes for RGBW

const int   ws2812NumLeds2 = 0;                        // number of LEDs
const int   ws2812Type2    = WS2812_GRBW;              // type of LEDs
byte        ws2812DrawingMemory2[ws2812NumLeds2 * 4];  // 3 bytes per LED for RGB, 4 bytes for RGBW
DMAMEM byte ws2812DisplayMemory2[ws2812NumLeds2 * 16]; // 12 bytes per LED for RGB, 16 bytes for RGBW

const int   ws2812NumLeds3 = 0;                        // number of LEDs
const int   ws2812Type3    = WS2812_GRBW;              // type of LEDs
byte        ws2812DrawingMemory3[ws2812NumLeds3 * 4];  // 3 bytes per LED for RGB, 4 bytes for RGBW
DMAMEM byte ws2812DisplayMemory3[ws2812NumLeds3 * 16]; // 12 bytes per LED for RGB, 16 bytes for RGBW

const int   ws2812NumLeds4 = 0;                        // number of LEDs
const int   ws2812Type4    = WS2812_GRBW;              // type of LEDs
byte        ws2812DrawingMemory4[ws2812NumLeds4 * 4];  // 3 bytes per LED for RGB, 4 bytes for RGBW
DMAMEM byte ws2812DisplayMemory4[ws2812NumLeds4 * 16]; // 12 bytes per LED for RGB, 16 bytes for RGBW

const int   ws2812NumLeds5 = 0;                        // number of LEDs
const int   ws2812Type5    = WS2812_GRBW;              // type of LEDs
byte        ws2812DrawingMemory5[ws2812NumLeds5 * 4];  // 3 bytes per LED for RGB, 4 bytes for RGBW
DMAMEM byte ws2812DisplayMemory5[ws2812NumLeds5 * 16]; // 12 bytes per LED for RGB, 16 bytes for RGBW

const int   ws2812NumLeds6 = 0;                        // number of LEDs
const int   ws2812Type6    = WS2812_GRBW;              // type of LEDs
byte        ws2812DrawingMemory6[ws2812NumLeds6 * 4];  // 3 bytes per LED for RGB, 4 bytes for RGBW
DMAMEM byte ws2812DisplayMemory6[ws2812NumLeds6 * 16]; // 12 bytes per LED for RGB, 16 bytes for RGBW

const int   ws2812NumLeds7 = 0;                        // number of LEDs
const int   ws2812Type7    = WS2812_GRBW;              // type of LEDs
byte        ws2812DrawingMemory7[ws2812NumLeds7 * 4];  // 3 bytes per LED for RGB, 4 bytes for RGBW
DMAMEM byte ws2812DisplayMemory7[ws2812NumLeds7 * 16]; // 12 bytes per LED for RGB, 16 bytes for RGBW

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
         new PPUCRGBColorCycleEffect(1),
         effectsController.ws2812Serial(1),
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
