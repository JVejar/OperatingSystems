#include <iostream>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
using namespace std;

#define X	4
#define Y	4
#define Z	4
#define NUM_THREADS	2

int A [X][Y];
int B [Y][Z];
int C [X][Z];

struct matrixStruct
{
	int i;
	int j;
};

void *pthread_multiply(void * data);

int main(){
   	std::cout << endl << "In the main thread" << endl << endl;	
  
	//pthread_t threadID[X][Y];
	//pthread_attr_t attr;
	//pthread_attr_init(&attr);  	

	
	//Filling in Matricies
	for(int i=0; i < X; i++)
	{
	  for(int j=0; j < Z; j++)
	   {
		//struct matrixStruct *data = (struct matrixStruct *) malloc(sizeof(struct matrixStruct));
		//data->i = i;
		//data->j = j;

		//pthread_create(&threadID[i][j], NULL, *pthread_multiply, (void *) data);
	      
		A[i][j] = i+j;
	     	B[i][j] = i+j;
	      	C[i][j] = 0;

	      	
		std::cout << A[i][j] << " ";
		//std::cout << B[i][j] << " ";
		//std::cout << C[i][j] << " ";
	   }
	      printf("\n");
	}

   	std::cout << endl;

	//joining the threads together
	for(int i=0; i<X; i++)
	{
	  for(int j=0; j<Y; j++)
	   {
		//pthread_join(threadID[i][j], NULL);
	   }

	}

	return 0;

}


void *pthread_multiply(void *data){
   int row,col,inner;
   for(row=0; row<X; row++)
   {
	for(col=0; col<Z; col++)
	{
		C[row][col] = 0;
	  for(inner = 0; inner < Y; inner++)
	  {
	    C[row][col] += A[row][inner] * B[inner][col];

	  }

     	}
	
   }
	
    pthread_exit(0);
}
