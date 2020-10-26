#include "../lib/uopmsb/uop_msb_2_0_0.h"
using namespace uop_msb_200;

BusOut leds(TRAF_RED1_PIN, TRAF_YEL1_PIN, TRAF_GRN1_PIN);

int main()
{
    leds = 0;
    // ***** MODIFY THE CODE BELOW HERE *****

    // 1. Write a for-loop to count from -50 to +50 in steps of 10 - print the results to the serial terminal

    // 2. Write a for-loop to count from 0 down to -100 in steps of 10 - print the results to the serial terminal

    // 3. Write some code to demonstrate nested for-loops (one loop within another)

    // ***** MODIFY THE CODE ABOVE HERE *****
    leds = 7;

    while (true) {

    }
}

