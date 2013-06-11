#include <stdlib.h>
#include <math.h>
#include <time.h>

int main()
{
	srand(time(NULL)); 

	int dim,val,rIndex;
	double rUniform;
	unsigned char r,g,b;
	unsigned char *rgb = NULL;

	printf("RAND_MAX %d\n",RAND_MAX);
	dim = (int)pow(2.0f,24.0f) - 1;
	rIndex = rand();
	rUniform = (double)rIndex/(double)RAND_MAX;
	val = rUniform * dim;
	printf("rUniform %f val %d\n",rUniform,val);
	rgb = (unsigned char *)&val;
	r = rgb[0];
	g = rgb[1];
	b = rgb[2];
	printf("r,g,b %d,%d,%d\n",r,g,b);


	// #include <stdio.h>
	// #include <stdlib.h>
	// #include <math.h>
	// #include <time.h>

	// // srand ( time(NULL) ); // Seed for random numbers.
	// int RMAX = 1000000;
	// int dim = pow(2,24) - 1;
	// int rint = rand() % RMAX;
	// printf("rint %d rand max %d\n", rint,RMAX);
	// double rval = ((double)rint)/(double)RMAX;
	// int val = (int) ( (double)dim * rval);
	// printf("dim %d rval %f val %d\n", dim);
	// unsigned char r =  (unsigned char)val;
	// unsigned char g = (unsigned char)val >> 3;
	// unsigned char b = (unsigned char)val >> 6;
	// printf("r %d g %d b %d\n", r, g , b);
}