#include "../lib/uopmsb/uop_msb_2_0_0.h"
using namespace uop_msb_200;

// 3x3 Array
double P[4][4] = {
    {1.0, 2.0, 3.0, 4.0},
    {-3.0, -4.0, -5.0, -6.0},
    {10.0, 11.0, 12.0, 13.0}
};

double Q[4][4] = {
    {1.0, 1.0, 1.0, 1.0},
    {-1.0, -1.0, -1.0, -1.0},
    {10.0, 10.0, 10.0, 10.0}
};


void displayArray(const double A[][4])
{
    for (unsigned row=0; row<3; row++) {
        for (unsigned col=0; col<3; col++) {
            printf("%8.1f\t", A[row][col]);
        }
        printf("\n\n");
    }
}

// ***** WRITE YOUR FUNCTION HERE *****


// *****  END YOUR FUNCTION HERE  *****

int main()
{
    displayArray(P);
    displayArray(Q);

    // ***** MODIFY THE CODE BELOW HERE *****

    // 1. Create another 3x3 Array Y

    // 2. Write a nested loop to add matrix P to Matrix Q, such that Y[i][j]=P[i][j]+Q[i][j]
 
    // 3. Write a function to add two a NxM arrays and return the result. Write code below to demonstrate it

    // ***** MODIFY THE CODE ABOVE HERE *****


    while (true) {
    }
}

