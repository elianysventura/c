//Elianys Ventura Rodriguez
//Panther ID: 5652936
//This is a program that acts like a minicalculator that multiples,adds and uses the power of 2.
//“I affirm that I wrote this program myself without any help form any other people or sources from the internet.”.
#include <stdio.h>
#include <stdlib.h>

int debug =0;

int main(int argc, char **argv)
{

	extern char *optarg;
	extern int optind;
	int c, err = 0; 
	int aflag=0, mflag=0, xflag = 0;
        int anum=0, mnum=0;
	static char usage[] = "usage: minicalc [-a num] [-m num] [-x] value\n";

        //Getopt as in the sample in class
	while ((c = getopt(argc, argv, "xm:a:")) != -1)
		switch (c)
		{
		case 'a':
			aflag = 1;
                        anum = atoi(optarg);
			break;
		case 'm':
			mflag = 1;
                        mnum = atoi(optarg);
			break;
		case 'x':
			xflag = 1;
			break;
		case '?':
			err = 1;
			break;
		}
	if ((optind+1) > argc) 
	{	
		printf("optind = %d, argc=%d\n", optind, argc);
		fprintf(stderr, "%s: missing value\n", argv[0]);
		fprintf(stderr, usage, argv[0]);
		exit(1);
	} 
	else if (err) 
	{
		fprintf(stderr, usage, argv[0]); //Usage message if error occurs
		exit(1);
	}
	
        double value = atoi(argv[optind]); //Saves value input into the value variable

        //Checks if input value is between 1 and 50
	if(value < 1 || value > 50)
	{ 
		printf("Input value needs to be between 1 and 50\n"); //Error message for input value not between 1 and 50
		fprintf(stderr, usage, argv[0]); //Usage message
		exit(1);
	}
	//Checks if num a is between 1 and 500
	if(anum < 1 || anum > 500)
	{

                printf("Num a needs to be between 1 and 500\n"); //Error message for num a not between 1 and 500
                fprintf(stderr, usage, argv[0]); //Usage message
                exit(1);
        } 
	//Checks if num m  is between 1 and 10
    	if(mnum < 1 || mnum > 10)
	{
                printf("Num m needs to be between 1 and 10\n"); //Error message for num m not between 1 and 10
                fprintf(stderr, usage, argv[0]); //Usage message
                exit(1);
        } 
    

        //Squares value
        if(xflag == 1)
	{
		value *= value;
	}
	//Mulitplies value by num m
	if(mflag == 1)
	{
		value *= mnum;
	}
	//Adds num a to value
	if(aflag == 1)
	{
		value += anum;
	}

        printf(" %.2f\n", value); //Prints the  result 
  
  exit(0);
}

                         

