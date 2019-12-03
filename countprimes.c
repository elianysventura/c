//Elianys Ventura Rodriguez
////Panther ID: 5652936
////This is a program that either finds all the prime numbers until 50000 using MPI
////“I affirm that I wrote this program myself without any help form any other people or sources from the internet.”
#include <stdio.h>
#include <unistd.h>
#include <mpi.h>
#include <time.h>

// Return 1 if 'i'th bit of 'n' is 1; 0 otherwise
#define EXTRACT_BIT(n,i) ((n&(1<<i))?1:0)
#define N 50000

// Checks if number is prime
int check_prime (int id, long z)
{
	long i;
	for(i = 2; i < z; i++)//Goes to every number
	{
		if(z % i == 0)//If prime
		return 0;
	}

	printf ("Process %d) %d\n", id, z); //Prints the process number and the prime numbers that process found
	fflush (stdout);
//	printf("Process %d is done\n",id);//Tells the user what processes finished
	return 1;
}

int main (int argc, char *argv[]) 
{
	int count;            // Solutions found by this proc 
	int global_count;     // Total number of solutions
	int i;
	int id;               // Process rank
	int p;                // Number of processes
	char hostname[1024];
 	clock_t tic = clock();//The begining of the clock for the whole process 
	
	long n = N;
  
	// OpenMPI
	MPI_Init (&argc, &argv);

	MPI_Comm_rank (MPI_COMM_WORLD, &id);//Process rank
	MPI_Comm_size (MPI_COMM_WORLD, &p);//Process number


  	// Goes through the numbers to check if they are prime and icreases  count
  	count = 0;
	for (i = id + 1; i < n; i += p)
	count += check_prime (id, i);

 	printf("Process %d is done\n",id);//Tells the user what processes finished
	fflush(stdout);

	MPI_Reduce (&count, &global_count, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD); 

	MPI_Finalize();//Shuts down MPI

	if (!id)//I there is no more
	{ 
		
		printf ("There are %d different solutions\n", global_count); // Prints out total number of prime numbers found
		clock_t toc = clock();//The final time
		printf("Elapsed: %f seconds\n", (double)(toc - tic) / CLOCKS_PER_SEC);//Prints the time taken for the whole process
	}
	return 0;
}

