# An introduction to OpenMP
#### Exercises for the "K.I.S.S. Parallel computing" course of the 2018 iCSC.

________________
This repository contains a series of exercises skeletons to be used during the exercises sessions of the aforementioned course.

All the exercises (except for the ```sequential_pi``` one) have to be compiled using an OpenMP compliant compiler, such as GCC, clang-omp, cl or icc. **Please note that on Mac OS X GCC is a wrapper around clang and as so is not able to handle OpenMP constructs.**
For a complete list of OpenMP compliant compilers please refer to [this page](http://www.openmp.org/resources/openmp-compilers/).

A ```makefile``` is present in the folder and is already configured with the build commands for all the skeletons available in the repository. **The ```CXX``` variable must be edited and must contain your compiler-of-choice executable name.** The ```CXX_FLAGS``` variable can be left as is. the ```makefile``` contains "recipes" for both ```all``` and ```clean``` arguments.

### Included files explanation
1.`common.h`:
This header contains common settings for all the executable. This choice allows to group all the settings to avoid discrepancies when measuring the speed-up of a parallel solution with respect to the sequential one. Triggering ```make all``` before any test sets up all the executables using the same ```common.h``` definitions.

2.`StopWatch.h` and `StopWatchOMP.h`:
These two classes are two equivalent wrappers around STL and OpenMP timing routines, respectively.
This implementation makes use of the default destructor call to trigger the output of the elapsed time. The overhead of this solution is negligible and as so is the best option for high precision timing.

3.`sequential__pi.C`:
This exercise represents the baseline. The algorithm for Pi computation is implemented sequentially and as so runs on a single thread. This implementation barely reflects the computation of the sum presented during the lessons.

4.`omp_parallel_pi.C`:
This exercise requires the student to modify the skeleton to avoid the different threads to perform exactly the same operations (which causes the Pi value to be ```Pi*n_threads```).

5.`omp_parallel_for_pi.C`:
This exercise requires the student to modify the skeleton to make use of the `for` construct which can automatically handle the job splitting across the spawned threads.

6.`test_section.C`:
This example represents the possibility to use one thread for asynchronous monitoring and the other threads for the real computing. This uses several OpenMP directives and is quite a complex and challenging code to read. Nevertheless it is a funny example to learn and can be used again and again alongside any OpenMP project to monitor the runtime status!