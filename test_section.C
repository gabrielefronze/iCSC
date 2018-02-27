#include "StopWatch.h"
#include <omp.h>
#include <iostream>
#include <thread>
#include <chrono>

using namespace std::chrono;

int main(){
    
    const long maxIteration = 100000;

    omp_set_nested(1);

    int outputCounter = 0;
    bool done = false;

#pragma omp parallel sections shared(outputCounter,done) num_threads(2)
{
    #pragma omp section
    {
        if ( omp_get_thread_num()==0 ){ 
            printf("monitor th_id: %d, n_th: %d\n",omp_get_thread_num(), omp_get_num_threads());
            while(!done){
                printf("%d/%d\r",outputCounter,maxIteration);
            }
            printf("%d/%d\n",outputCounter,maxIteration);
        }
    }

    #pragma omp section
    {
        int section = 2;
        #pragma omp parallel num_threads(16)
        {
            printf("computing th_id: %d, n_th: %d\n",omp_get_thread_num(), omp_get_num_threads());
            #pragma omp for
            for( int i=0; i<maxIteration; i++){
                std::this_thread::sleep_for (microseconds(100));
            #pragma omp critical
                {
                    outputCounter++;
                }
            }
        }
        done = true;
    }
}

    return 0;
}