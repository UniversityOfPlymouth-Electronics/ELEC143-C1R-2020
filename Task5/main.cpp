#include "../lib/uopmsb/uop_msb_2_0_0.h"
using namespace uop_msb_200;

// You are to use these ojects to read the switch inputs
DigitalIn SW1(USER_BUTTON);
DigitalIn SW2(BTN1_PIN);
DigitalIn SW3(BTN2_PIN);
DigitalInOut SW4(BTN3_PIN,PIN_INPUT,PullDown,0);
DigitalInOut SW5(BTN4_PIN,PIN_INPUT,PullDown,0);

// You are to use this object to control the LEDs
BusOut leds(TRAF_RED1_PIN, TRAF_YEL1_PIN, TRAF_GRN1_PIN);

//Use this to sound an error
Buzzer alarm;

int main()
{
    while (true)
    {
        leds = 0;

        //Beep
        alarm.playTone("A", uop_msb_200::Buzzer::HIGHER_OCTAVE);
        wait_us(250000);
        alarm.rest();

        //Wait for the blue button
        while (SW1==0);

        
        // For full marks, debounce the switches with suitable delays

        // This is a "combination lock" activity. Write some code to detect the following sequence 
        //      SW5 and SW2 held down together then released
        //      SW3 and SW4 held down together then released
        //      SW5 and SW4 held down together then released

        // If the full sequence is entered, correctly, the green LED should flash 3 times
        // If a sequence is entered incorrectly, the red LED should light and the buzzer should sound for 5 seconds
        // For full marks, use flow control structures and arrays to avoid deep nesting of code

        // ***** MODIFY THE CODE BELOW HERE *****

        

        // ***** MODIFY THE CODE ABOVE HERE *****
    }
}


