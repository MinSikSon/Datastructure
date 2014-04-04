#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    char star;
    int num;
	double *arr;
	int count = 0;
    double *sum;
	double *sum2;
	int buf = 0;
    int i, j;

    FILE *input_fp, *output_fp;

    if( (input_fp = fopen("program1.inp", "r")) == NULL )
    {
    	fprintf(stderr, "can't open %s\n", "program1.inp" );
    }
    
    if( (output_fp = fopen("program1.out", "w")) == NULL )
    {
    	fprintf(stderr, "can't open %s\n", "program1.out" );
    }

	fscanf(input_fp, "%d", &num);

    // calloc(3, sizeof(int) )
    if( ( sum = (double *)malloc( sizeof(double)*3 )) == NULL )
    {
    	fprintf(stderr, "memory allocation error %s\n", "sum" );
    }
	if( ( sum2 = (double *)malloc( sizeof(double)*3 )) == NULL )
    {
    	fprintf(stderr, "memory allocation error %s\n", "sum2" );
    }
	if( ( arr = (double *)malloc( sizeof(double)*(num*3) )) == NULL )
    {
    	fprintf(stderr, "memory allocation error %s\n", "arr" );
    }

	// √ ±‚»≠
	for(i=0 ; i<3 ; i++)
	{
		sum[i] = 0;
		sum2[i] = 0;
	}

	for(i=0 ; i<num; i++)
	{
		for(j=0 ; j<3 ; j++)
		{
			fscanf(input_fp, "%d", &buf);
			sum[j] += buf; 
			arr[count] = buf;
			count++;
		}
	}

	sum[0] = sum[0]/num;
	sum[1] = sum[1]/num;
	sum[2] = sum[2]/num;

	for(i=0 ; i<3 ; i++)
	{
		fprintf(output_fp, "%.1f", sum[i]-0.05);
		if(i!= 2)
			fprintf(output_fp, " ");
	}
	fprintf(output_fp, "\n");

	for(i=0 ; i<(num*3) ; i++)
	{
		if(i%3 == 0)
		{
			sum2[0] += (arr[i]-sum[0])*(arr[i]-sum[0]);
		}
		else if(i%3 == 1)
		{
			sum2[1] += (arr[i]-sum[1])*(arr[i]-sum[1]);
		}
		else if(i%3 == 2)
		{
			sum2[2] += (arr[i]-sum[2])*(arr[i]-sum[2]);
		}
	}

	sum2[0] = sum2[0]/num;
	sum2[1] = sum2[1]/num;
	sum2[2] = sum2[2]/num;

	sum2[0] = sqrt(sum2[0]);
	sum2[1] = sqrt(sum2[1]);
	sum2[2] = sqrt(sum2[2]);

	for(i=0 ; i<3 ; i++)
	{
		fprintf(output_fp, "%.1f", sum2[i]-0.05);
		if(i!= 2)
			fprintf(output_fp, " ");
	}
	fprintf(output_fp, "\n*");
    
    fclose( input_fp );
    fclose( output_fp );
    free( sum );
    free( sum2 );
    free( arr );

    return 0;
}
