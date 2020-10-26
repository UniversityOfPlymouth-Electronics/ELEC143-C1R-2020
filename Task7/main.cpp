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
Buzzer player;

// Note array. The string "-" is a rest
typedef struct {
    char note[3];
    Buzzer::OCTAVE_REGISTER octave;
    unsigned int time_ms;
} NOTE;

// https://en.wikipedia.org/wiki/List_of_musical_symbols
#define SEMIBREVE 1200          //Whole beat
#define MINIM (SEMIBREVE >> 1)  //Half
#define CROTCHET (MINIM >> 1)   //Quarter
#define QUAVER (CROTCHET >> 1)  //Eighth
#define SEMIQUAVER (QUAVER >> 1) //Sixteenth

//Triplets
#define SEMIBREVE_TRIP 900          //Whole beat
#define MINIM_TRIP (SEMIBREVE_TRIP >> 1)  //Half
#define CROTCHET_TRIP (MINIM_TRIP >> 1)   //Quarter
#define QUAVER_TRIP (CROTCHET_TRIP >> 1)  //Eighth
#define SEMIQUAVER_TRIP (QUAVER_TRIP >> 1) //Sixteenth

NOTE notes[] = {
    {.note="E", .octave=Buzzer::MIDDLE_OCTAVE, .time_ms=QUAVER},
    {.note="E", .octave=Buzzer::MIDDLE_OCTAVE, .time_ms=QUAVER},
    {.note="-", .octave=Buzzer::MIDDLE_OCTAVE, .time_ms=QUAVER},
    {.note="E", .octave=Buzzer::MIDDLE_OCTAVE, .time_ms=QUAVER},
    {.note="-", .octave=Buzzer::MIDDLE_OCTAVE, .time_ms=QUAVER},    
    {.note="C", .octave=Buzzer::MIDDLE_OCTAVE, .time_ms=QUAVER},
    {.note="E", .octave=Buzzer::MIDDLE_OCTAVE, .time_ms=CROTCHET},
    {.note="G", .octave=Buzzer::MIDDLE_OCTAVE, .time_ms=CROTCHET},
    {.note="-", .octave=Buzzer::MIDDLE_OCTAVE, .time_ms=CROTCHET},
    {.note="G", .octave=Buzzer::LOWER_OCTAVE,  .time_ms=CROTCHET},
    {.note="-", .octave=Buzzer::MIDDLE_OCTAVE, .time_ms=CROTCHET},

    {.note="C", .octave=Buzzer::MIDDLE_OCTAVE, .time_ms=QUAVER},
    {.note="-", .octave=Buzzer::MIDDLE_OCTAVE, .time_ms=CROTCHET}, 
    {.note="G", .octave=Buzzer::LOWER_OCTAVE,  .time_ms=QUAVER},
    {.note="-", .octave=Buzzer::MIDDLE_OCTAVE, .time_ms=CROTCHET}, 
    {.note="E", .octave=Buzzer::LOWER_OCTAVE,  .time_ms=QUAVER+CROTCHET},
    {.note="A", .octave=Buzzer::MIDDLE_OCTAVE, .time_ms=CROTCHET},
    {.note="B", .octave=Buzzer::MIDDLE_OCTAVE, .time_ms=CROTCHET},
    {.note="A#", .octave=Buzzer::MIDDLE_OCTAVE, .time_ms=QUAVER},
    {.note="A", .octave=Buzzer::MIDDLE_OCTAVE, .time_ms=CROTCHET},

    {.note="G", .octave=Buzzer::LOWER_OCTAVE,  .time_ms=CROTCHET_TRIP},
    {.note="E", .octave=Buzzer::MIDDLE_OCTAVE, .time_ms=CROTCHET_TRIP},
    {.note="G", .octave=Buzzer::MIDDLE_OCTAVE, .time_ms=CROTCHET_TRIP},
    {.note="A", .octave=Buzzer::HIGHER_OCTAVE, .time_ms=CROTCHET},
    {.note="F", .octave=Buzzer::MIDDLE_OCTAVE, .time_ms=QUAVER},
    {.note="G", .octave=Buzzer::MIDDLE_OCTAVE, .time_ms=QUAVER},

    {.note="-", .octave=Buzzer::MIDDLE_OCTAVE, .time_ms=QUAVER}, 
    {.note="E", .octave=Buzzer::MIDDLE_OCTAVE, .time_ms=CROTCHET},
    {.note="C", .octave=Buzzer::MIDDLE_OCTAVE, .time_ms=QUAVER},
    {.note="D", .octave=Buzzer::MIDDLE_OCTAVE, .time_ms=QUAVER},
    {.note="B", .octave=Buzzer::MIDDLE_OCTAVE, .time_ms=QUAVER+CROTCHET},    

    // Repeat

    {.note="C", .octave=Buzzer::MIDDLE_OCTAVE, .time_ms=QUAVER},
    {.note="-", .octave=Buzzer::MIDDLE_OCTAVE, .time_ms=CROTCHET}, 
    {.note="G", .octave=Buzzer::LOWER_OCTAVE,  .time_ms=QUAVER},
    {.note="-", .octave=Buzzer::MIDDLE_OCTAVE, .time_ms=CROTCHET}, 
    {.note="E", .octave=Buzzer::LOWER_OCTAVE,  .time_ms=QUAVER+CROTCHET},
    {.note="A", .octave=Buzzer::MIDDLE_OCTAVE, .time_ms=CROTCHET},
    {.note="B", .octave=Buzzer::MIDDLE_OCTAVE, .time_ms=CROTCHET},
    {.note="A#", .octave=Buzzer::MIDDLE_OCTAVE, .time_ms=QUAVER},
    {.note="A", .octave=Buzzer::MIDDLE_OCTAVE, .time_ms=CROTCHET},

    {.note="G", .octave=Buzzer::LOWER_OCTAVE,  .time_ms=CROTCHET_TRIP},
    {.note="E", .octave=Buzzer::MIDDLE_OCTAVE, .time_ms=CROTCHET_TRIP},
    {.note="G", .octave=Buzzer::MIDDLE_OCTAVE, .time_ms=CROTCHET_TRIP},
    {.note="A", .octave=Buzzer::HIGHER_OCTAVE, .time_ms=CROTCHET},
    {.note="F", .octave=Buzzer::MIDDLE_OCTAVE, .time_ms=QUAVER},
    {.note="G", .octave=Buzzer::MIDDLE_OCTAVE, .time_ms=QUAVER},

    {.note="-", .octave=Buzzer::MIDDLE_OCTAVE, .time_ms=QUAVER}, 
    {.note="E", .octave=Buzzer::MIDDLE_OCTAVE, .time_ms=CROTCHET},
    {.note="C", .octave=Buzzer::MIDDLE_OCTAVE, .time_ms=QUAVER},
    {.note="D", .octave=Buzzer::MIDDLE_OCTAVE, .time_ms=QUAVER},
    {.note="B", .octave=Buzzer::MIDDLE_OCTAVE, .time_ms=QUAVER+CROTCHET},    

};


int main()
{
    //Start up Beep
    player.playTone("A", Buzzer::HIGHER_OCTAVE);
    unsigned int NumberOfNotes = sizeof(notes)/sizeof(NOTE);
    wait_us(500000);

    while (true)
    {
        leds = 0;
        player.rest();
        
        //Wait for the blue button
        while (SW1==0);

        // TASK - The code below plays the start of a popular melody
        //        Some of this melody is repeated twice. It turns out the array `notes` has some duplicate data
        //        To save memory, find and remove the repeated section from the array 
        //        Modify the code below to play the exact same tune, only using less memory

        // ***** MODIFY THE CODE BELOW HERE *****

        for (unsigned int n=0; n<NumberOfNotes; n++) {
            unsigned int dur_us = notes[n].time_ms*1000;
            
            if (notes[n].note[0]=='-') {
                player.rest();
            } else {
                player.playTone(notes[n].note,notes[n].octave);
            }
            wait_us(dur_us-500);
            player.rest();
            wait_us(500);
        }

        // ***** MODIFY THE CODE ABOVE HERE *****
        
    }
}


