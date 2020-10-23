// Markus Kalkbrenner 2020
// Note to self:  Play more pinball!

#include <ppuck.h>

ppuck ppuck("TNG");

void setup() {
    Serial.begin(115200);
}

void loop() {
    ppuck.pin2Dmd()->update();

    if (ppuck.switchMatrix()->getOnce(/* row */ 2, /* column */ 1, /* ignore for further reads for milli seconds */ 200)) {
        ppuck.switchMatrix()->reset();
    }
}
