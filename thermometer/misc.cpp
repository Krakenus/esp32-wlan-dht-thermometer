#include <Arduino.h>
#include "settings.h"

void blink_forever()
{
    while(true)
    {
        digitalWrite(LED_BUILTIN, HIGH);
        delay(BLINK_DELAY);
        digitalWrite(LED_BUILTIN, LOW);
        delay(BLINK_DELAY);
    }
}
