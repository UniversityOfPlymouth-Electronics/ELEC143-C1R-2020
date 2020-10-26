#include "../lib/uopmsb/uop_msb_2_0_0.h"
using namespace uop_msb_200;


// This clears out the serial interface - reccomended before reading the keyboard
void flushInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

int main()
{

    // ***** MODIFY THE CODE BELOW HERE *****

    // 1. Using a while-loop, count from 0 to 20 in steps of 2 - print the results to the serial terminal


    // 2. The code below asks the user to enter a number between 10 and 20.
    //    Add code to read the keyboard 
    //    Add a a do-while-loop to repeat until the correct value is added
    //    Print the entered value to the terminal

    //Prompt user
    printf("\nEnter a value (10..20)\n");
    //Clear out the serial interface (in case any old characters are still there)
    flushInputBuffer();
        
    // ***** MODIFY THE CODE ABOVE HERE *****

    while (true) {

    }
}

