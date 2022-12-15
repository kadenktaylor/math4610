//
// load in a couple of header files
// --------------------------------
//
  #include <stdio.h>
  #include <omp.h>
//
// main method for an entry point for the code
// ------------------------------------------- 
//
int main()
{
  //
  // initialize some integer variables
  // ---------------------------------
  //
  int nthreads, tid;
  //
  /*
   * Use the following compiler directive to fork a team of threads 
   * with each thread having a private tid variable
   *
   * Note that for C programs, the code to which the pragma is 
   * applied, must be enclosed in curly braces {...}
   *
   */
#pragma omp parallel private(tid)
  {

    /* Obtain and print thread id */
    tid = omp_get_thread_num();
    printf("Hello World from thread = %d\n", tid);
  
    /* Only master thread does this */
    if(tid == 0)
      {
	nthreads = omp_get_num_threads();
	printf("Number of threads = %d\n", nthreads);
      }
  }

  printf("This is the end\n");
  /*
   * All threads join master thread and terminate
   */
}
