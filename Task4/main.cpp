#include "../lib/uopmsb/uop_msb_2_0_0.h"
using namespace uop_msb_200;

// You are to the following PortIn oject to read both the switch inputs
BusIn sw(BTN1_PIN, BTN2_PIN);

// You are to use this object to control the LEDs
BusOut leds(TRAF_RED1_PIN, TRAF_YEL1_PIN, TRAF_GRN1_PIN);

int main()
{
    while (true)
    {
    // ***** MODIFY THE CODE BELOW HERE *****
    // For full marks, debounce the switches with suitable delays

    // 1. Wait for BOTH switches to be pressed and released

    // 2. Wait for EITHER switch to be released

    while (true) {

        // 3. If either switch is pressed and released, toggle the RED LED

    }


    // ***** MODIFY THE CODE ABOVE HERE *****
    }
}


