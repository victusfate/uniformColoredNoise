#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <limits.h>

#include <stdint.h>

int main()
{
    struct timeval tv;
    uint64_t time_in_micros,time_in_micros2;


    int dim,val,rIndex;
    double rUniform;
    unsigned char r,g,b;
    uint8_t *rgb = NULL;
    int i;
    const int NTRIALS = 100000000;

    gettimeofday(&tv,NULL);
    time_in_micros = 1000000 * tv.tv_sec + tv.tv_usec;
    srand(time_in_micros % UINT_MAX); 


    for (i = 0; i < NTRIALS;i++) {
        // printf("RAND_MAX %d\n",RAND_MAX);
        dim = (int)pow(2.0f,24.0f) - 1;
        rIndex = rand();
        rUniform = (double)rIndex/(double)RAND_MAX;
        val = rUniform * dim;
        // printf("rUniform %f val %d\n",rUniform,val);
        rgb = (unsigned char *)&val;
        r = rgb[0];
        g = rgb[1];
        b = rgb[2];
        // printf("r,g,b %d,%d,%d\n",r,g,b);
    }

    gettimeofday(&tv,NULL);
    time_in_micros2 = 1000000 * tv.tv_sec + tv.tv_usec;
    double dT_usec = (time_in_micros2 - time_in_micros);
    printf("%d random colored noise values, run time in sec %f, average time per noise val usec %f\n", NTRIALS, dT_usec / 1e6, dT_usec/NTRIALS );
}