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

#### Workflow
Basically Git works as a non-automatic version of a cloud storage service that keeps track of the changes and allows one to revert some of them or to move forward and backward in time. This is called version control system (VCS) and is a widely used approach in complex code development.

To make it easy you want to `push` the local edits to the remote repository and to `pull` new stuff from the remote repository. Once a repository is available on a machine you can step into it, do `git pull` to sync, modify whatever you want and then commit and `git push` everything to GitHub.

For this exercises we'll use Git to share code between the coding machine (your laptop) and the computing machine (the remote VM).


### Instructions
First of all check out this basic and valid Git guide: [basic git guide](https://git-scm.com/docs/gittutorial)

If you haven't done so yet register of GitHub with a free account and install git on your computer: [how to install git](https://git-scm.com/book/en/v2/Getting-Started-Installing-Git)

At the top of [this page](https://github.com/gabrielefronze/iCSC) find the fork button and press it while being logged in to GitHub. Once done you will find a clone (technically a fork) of this repository on your GitHub page.

####Using...

##### ...your laptop
Now you are ready to clone your forked repository locally on your machine to start working:

```cd <your_path> && git clone https://github.com/<your_account_name>/iCSC.git```

Start editing the files, modify the code. Once you got to a point where a feature has been fully implemented (e.g. you are done with an exercise) do:

```git add -A && git commit -m "<your_commit_message> && git push"```

##### ...your VM
For the iCSC you can use  remote VM to test the parallel code on multiple CPUs.

Connect to the machine using ssh.
Clone locally the repository you have just forked, just as you did on your laptop:

```cd <your_path> && git clone https://github.com/<your_account_name>/iCSC.git```

Every time you commit new code from your laptop use the following command to sync the VM with the remote code:

```cd <your_path> && git pull```