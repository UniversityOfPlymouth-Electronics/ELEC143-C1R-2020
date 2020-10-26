#include "../lib/uopmsb/uop_msb_2_0_0.h"
using namespace uop_msb_200;

PortOut lights(PortC, 0b0000000001001100);

int main()
{
    //All three ON
    lights = 0b0000000001001100;
    wait_us(1000000);

    //All three OFF
    lights = 0b0000000000000000;
    wait_us(1000000);

    while (true)
    {
        //Switch on the RED led by assigning a numeric literal value
        lights = 0b0000000000000100;
        wait_us(1000000);               

        //1. Turn ON the yellow LED using a bit-wise OR operator (without affecting the others)


        //2. Turn ON the green LED using a bit-wise OR operator (without affecting the others)


        //3. Turn OFF the yellow LED using a bit-wise AND operator (without affecting the others)


        //4. Flash the red LED 2-times using the bit-wise XOR operator (without affecting the others)

        
    }
}


