CXX=clang-omp++
CXX_FLAGS=-O3 -fopenmp -I.

all : sequential omp_parallel_pi omp_parallel_for_pi test_section

sequential : sequential_pi.C
	$(CXX) $(CXX_FLAGS) sequential_pi.C -o sequential

omp_parallel_pi : omp_parallel_pi.C
	$(CXX) $(CXX_FLAGS) omp_parallel_pi.C -o omp_parallel_pi

omp_parallel_for_pi : omp_parallel_for_pi.C
	$(CXX) $(CXX_FLAGS) omp_parallel_for_pi.C -o omp_parallel_for_pi

test_section : test_section.C
	$(CXX) $(CXX_FLAGS) test_section.C -o test_section

clean : 
	rm sequential omp_parallel_pi omp_parallel_for_pi test_section