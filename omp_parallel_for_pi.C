//---------------------------------------------------------------------
// This program is made to compute pi numerical value.
// It will numerically compute the integral of
//
//                   4/(1+x*x)
//
// from 0 to 1 using variable number of steps.
// The value of this integral is pi. The knowing of pi is quite 
// precise and the result can be compared to the "real" value.
//
// This parallel version uses omp parallel for.
// It uses a timer class defined in a separate header file.
//
// History: 
// Written by Gabriele Gaetano Fronzé, 01/18.
// Based on Tim Mattson implementation, 11/99.
//---------------------------------------------------------------------

#include "StopWatch.h"
#include <omp.h>
#include <iostream>

const long num_steps = 500000000; //number of x bins

int main()
{
    StopWatch stopWatch;

    double x, pi, sum = 0.0;
    step = 1.0/(double) num_steps; //x-step
    int n_threads=1;

    #pragma omp parallel
    {
        n_threads = omp_get_num_threads();

        // OpenMP can handle for us for loop ranges!
        // TIP: you have to add something in the following line...

        for (long i=1; i<=num_steps; i++) {
            x = (i - 0.5) * step; //computing the x value
            sum += 4.0 / (1.0 + x * x); //adding to the cumulus
        }
    }

    pi = step * sum;

    printf("Pi value: %f\n
            Number of steps: %d\n
            Number of threads: %d\n",
            pi,num_steps,n_threads;
    
    return 0;
    
}
