#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/resource.h>

int main()
{

	struct rusage usage;

	for(int i = 0; i < 10; i++){
		double *mem = (double*)calloc(1280000000, sizeof(double));
		sleep(1);
		getrusage(RUSAGE_SELF, &usage);

		printf("mem_usage: %ld\n", usage.ru_maxrss);
	}
}
