#include<stdlib.h>
#include<unistd.h>

int main()
{
        for(int i = 0; i < 10; i++){
                double *mem = (double*)calloc(1280000000, sizeof(double));
		sleep(1);
        }
}
