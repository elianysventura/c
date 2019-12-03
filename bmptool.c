//Elianys Ventura Rodriguez
//////Panther ID: 5652936
//////This is a program that manipulates an imgae from a 24 bit bmp file
//////“I affirm that I wrote this program myself without any help form any other people or sources from the internet.”.

#include <stdlib.h>
#include "bmplib.h"
#include "bmplib.c"


/*
 * This method enlarges a 24-bit, uncompressed .bmp file
 * that has been read in using readFile()
 i*
 * original - an array containing the original PIXELs, 3 bytes per each
 * rows     - the original number of rows
 * cols     - the original number of columns
 *
 * scale    - the multiplier applied to EACH OF the rows and columns, e.g.
 *           if scale=2, then 2* rows and 2*cols
 *
 * new      - the new array containing the PIXELs, allocated within
 * newrows  - the new number of rows (scale*rows)
 * newcols  - the new number of cols (scale*cols)
 */

int enlarge(PIXEL* original, int rows, int cols, int scale, 
	    PIXEL** new, int* newrows, int* newcols) 
{
	//Variables
	int row, col, newIndex, originalIndex;

	*newrows = scale * rows;
	*newcols = scale * cols;
	
	//Checks if image is empty
	if ((rows <= 0) || (cols <= 0)) return -1;
	
	//Allocating memory for larger image
	*new=(PIXEL*)malloc((*newrows)*(*newcols)*sizeof(PIXEL));
	

	//Scale image
	for(row=0;row<(*newrows);row++)
    	{	
		for(col=0;col<(*newcols);col++)
		{
			newIndex = row * (*newcols) + col;
			originalIndex = (row * rows / (*newrows)) * cols + col * cols / (*newcols);
			(*new)[newIndex] = original[originalIndex];
		}
    	}
	
	
	return 0;
}

/*
 * This method rotates a 24-bit, uncompressed .bmp file that has been read 
 * in using readFile(). The rotation is expressed in degrees and can be
 * positive, negative, or 0 -- but it must be a multiple of 90 degrees
 * 
 * original - an array containing the original PIXELs, 3 bytes per each
 * rows     - the number of rows
 * cols     - the number of columns
 * rotation - a positive or negative rotation, 
 *
 * new      - the new array containing the PIXELs, allocated within
 * newrows  - the new number of rows
 * newcols  - the new number of cols
 */
 
int rotate(PIXEL* original, int rows, int cols, int rotation,
	   PIXEL** new, int* newrows, int* newcols)
{
	//Variables
	int col, row;
	PIXEL* n;
	
	//Checking if the image is empty
	if ((rows <= 0) || (cols <= 0)) return -1;
	
	//If degrees is not a multiple of 90
	if(rotation % 90 != 0)
	{
		
		printf("Invalid number. Please enter a multiple of 90\n");//Let the user know
		exit(100);//Error
	}
	
		
	//Sets rotation
	rotation = rotation % 360;
	
	//Sees the negative rotation and sets newrows and newcols
	if(rotation < 0)
	{
		if(rotation == -90)
		{
			rotation = 270;
			*newrows = cols;	
			*newcols = rows;
		}
		else if(rotation == -270)
		{
			rotation = 90;
			*newrows = cols;	
			*newcols = rows;
		}
		else if(rotation == -180)
		{
			rotation = 180;
			*newrows = rows;
			*newcols = cols;
		}
	}
	
	//Positive rotation of 90
	if(rotation == 90)
	{
		*newrows = cols;	
		*newcols = rows;
	}
	
	//Positive rotation of 180
	if(rotation == 180)
	{
		*newrows = rows;
		*newcols = cols;
	}
	
	//Positive rotation of 270
	if(rotation == 270)
	{
		*newrows = cols;	
		*newcols = rows;
	}
	
	//Positive rotation of 0
	if(rotation == 0)
	{
		*newrows = rows;
		*newcols = cols;
	}
	
	//Allocates memory space for new image
	*new = (PIXEL*)malloc((*newrows)*(*newcols)*sizeof(PIXEL));
	
	//Rotates the image
	for (row = 0; row < rows; row++)
	{
		//For every columb	
		for (col = 0; col < cols; col++)
		{
			
			PIXEL* o = original + row * cols + col;
			
			//If rotation is 90 then rotate 90 degrees
			if (rotation == 90)	
			{
				n = (*new) + (cols - 1 - col) * rows + row;
				*n = *o;
			}
			
			//If rotation is 180 then rotate 
			else if (rotation == 180)
			{
				n = (*new) + (rows - 1 - row) * cols + (cols - 1 - col);
				*n = *o;
			}
			
			//If rotation is 270 then rotate 270 degrees
			else if (rotation == 270)
			{
				n = (*new) + (col * rows) + (rows - 1 - row);
				
				*n = *o;
			}
			
			//If rotation is 0 then leave it
			else if (rotation == 0)
			{
				
				n = (*new) + row + col;
				*n = *o;
			}
		}
	}
	return 0;
}

/*
 *  * This method Vertically flips a 24-bit, uncompressed bmp file
 *   * that has been read in using readFile().
 *    *
 *     * original - an array containing the original PIXELs, 3 bytes per each
 *      * rows     - the number of rows
 *       * cols     - the number of columns
 *        *
 *         * new      - the new array containing the PIXELs, allocated within
 *          */

int verticalflip (PIXEL *original, PIXEL **new, int rows, int cols)
{
	//Veriables
	int row, col;

	//Checks if image is empty
	if ((rows <= 0) || (cols <= 0)) return -1;

	//Allocates memory
	*new = (PIXEL*)malloc(rows*cols*sizeof(PIXEL));
		
	//Flips image vertically, the colums stay the same but rows chanefe
	for(row=0; row< rows;row++)
               for( col=0; col< cols; col++) 
		{
		 PIXEL* o= original + row *cols + col;
	         PIXEL* n= (*new) + (rows-1-row)* cols + col ;//Changes rows
	         *n = *o;
		}
  return 0;
}

/*
 * This method horizontally flips a 24-bit, uncompressed bmp file
 * that has been read in using readFile(). 
 * 
 * THIS IS GIVEN TO YOU SOLELY TO LOOK AT AS AN EXAMPLE
 * TRY TO UNDERSTAND HOW IT WORKS
 *
 * original - an array containing the original PIXELs, 3 bytes per each
 * rows     - the number of rows
 * cols     - the number of columns
 *
 * new      - the new array containing the PIXELs, allocated within
 */
 
int flip (PIXEL *original, PIXEL **new, int rows, int cols){
	//Variables and initialization
	int row, col;

	//Checking if image is empty
	if ((rows <= 0) || (cols <= 0)) return -1;

	//Allocating memory for new image
	*new = (PIXEL*)malloc(rows*cols*sizeof(PIXEL));

	//Flips image
	for (row=0; row < rows; row++)
		for (col=0; col < cols; col++) {
		  PIXEL* o = original + row*cols + col;
		  PIXEL* n = (*new) + row*cols + (cols-1-col);
		  *n = *o;
		}
  return 0;
}


int main(int argc, char** argv)
{
	
	
	int sflag=0, sval=0, rflag=0, rval=0, fflag=0, vflag=0, oflag=0, err=0, rows, cols, c;
	char* infile;
	char* outfile;
	PIXEL *original, *new1, *new2, *new3;
	extern char* optarg;
	extern int optind;	
	static char usage[] = "usage: % bmptool [-s scale | -r degree | -f | -v ] [-o output_file] [input_file]";
	
	//Checks usage input using getopt
	while ((c = getopt(argc, argv, "fvo:r:s:")) != -1)
	{
		
		switch(c)
		{
			
			//S is the scale case which must be positive
			case 's':
				sflag = 1;
				sval = atoi(optarg);
				if(sval < 1)
				{
					printf("Invalid argument. Please enter a postive number.\n");
					exit (100);
				}
				break;
			
			//R is the rotate case
			case 'r':
				if(rflag)
				{

				fprintf(stderr, "Duplicate options\n");

				exit(-1);

				}				

				rflag = 1;
				rval = atoi(optarg);
				break;
			
			//F is the flip horizontal case
			case 'f':
				if(fflag){

				fprintf(stderr, "Duplicate options\n");

				exit(-1);

				}
				fflag = 1;
				break;

			//V is the flip vertical case
			case 'v':
				vflag=1;
				break;
				
			//O is the output file case
			case 'o':
				oflag = 1;
				outfile = optarg;
				printf("outfile = %s\n", outfile);
				break;
				
			case '?':
				err = 1;
				break;
		}
	}
	
	//If there is an input file, sets input file to infile
	if (argc > optind)
	{
		infile = argv[optind];
	}
	
	//If there is an error
	if(err == 1)
	{
		printf("Invalid argument:\n");//Prints error
		printf("%s\n", usage);//Ussage statement
		exit (100);
	}
	
	//If there is no input file
	if(argv[optind] == NULL)
	{
		readFile(NULL, &rows, &cols, &original);
	}
	//Other wise there is an input file that has been set to infile and u must read
	else
	{
		readFile(infile, &rows, &cols, &original);//Reads input file
	}

	//If there is no output file
	if(oflag == 0)
	{
		
	}	
	
	//If you only scale the image
	if(sflag == 1 && rflag == 0 && fflag == 0 && vflag == 0)
	{
		enlarge(original, rows, cols, sval, &new1, &rows, &cols);//Call the enlarge method to scale the image
		writeFile(outfile, rows, cols, new1);//Writes the image in the output file
	}
	
	//If you only rotate the image
	if(sflag == 0 && rflag == 1 && fflag == 0 && vflag == 0)
	{
		if(rval % 360 != 0)
		{
			rotate(original, rows, cols, rval, &new1, &rows, &cols);//Call the rotate method to scale the image
		}
		//If rotation degree is not a multiple of 360
		else 
		{
			new1 = original;
		}
		writeFile(outfile, rows, cols, new1);//Writes the image in the output file
	}
	
	//If you only flip horizonatal
	if(sflag == 0 && rflag == 0 && fflag == 1 && vflag == 0)
	{
	
		flip (original, &new1, rows, cols);//Call the flip method to flip the image horizontally
		writeFile(outfile, rows, cols, new1);//Writes the image in the output file
	}

	//If you only flip vertical
	if(sflag == 0 && rflag == 0 && fflag == 0 && vflag == 1)
	{
		verticalflip (original, &new1, rows, cols);//Call the verticalflip method to flip the image vertically
		writeFile(outfile, rows, cols, new1);//Write the image in the output file
	}	

	//If you want to scale and rotate
	if (sflag == 1 && rflag == 1 && fflag == 0 && vflag == 0)
	{
		enlarge(original, rows, cols, sval, &new1, &rows, &cols);//Call the enlarge method to scale the image
		rotate(new1, rows, cols, rval, &new2, &rows, &cols);//Call the rotate method to rotate the image
		writeFile(outfile, rows, cols, new2);//Writes the inage to the output file
		free(original);//Frees original
		free(new1);//Frees new1
		free(new2);//Frees new2
	}
	
	//If you want tp scale and flip horizontal
	if (sflag == 1 && rflag == 0 && fflag == 1 && vflag == 0)
	{
		enlarge(original, rows, cols, sval, &new1, &rows, &cols);//Call the enlarge method to scale the image
		flip(new1, &new2, rows, cols);//Call the flip method to flip the image horizontally
		writeFile(outfile, rows, cols, new2);//Writes the image to the output file
		free(original);//Frees original
		free(new1);//Frees new1
		free(new2);//Frees new2
	}

	//If you want to scale and flip vertical
	if (sflag == 1 && rflag == 0 && fflag == 0 && vflag == 1)
	{
		enlarge(original, rows, cols, sval, &new1, &rows, &cols);//Call the enlarge method to scale the image
		verticalflip(new1, &new2, rows, cols);//Call the verticalflip method to flip the image vertically
		writeFile(outfile, rows, cols, new2);//Writes the image to the output file
		free(original);//Frees original
		free(new1);//Frees new1
		free(new2);//Frees new2
	}	
	//If you wsnt to rotate and flip horizontal
	if (sflag == 0 && rflag == 1 && fflag == 1 && vflag == 0)
	{
		rotate(original, rows, cols, rval, &new1, &rows, &cols);//Call the rotate method to rotate the image
		flip(new1, &new2, rows, cols);//Call the flip method to flip the image horizontally
		writeFile(outfile, rows, cols, new2);//Write the image to the output file
		free(original);//Free original
		free(new1);//Frees new1
		free(new2);//Frees new2
	}
	
	//If you want to rotate and flip vertical
	if (sflag ==0 && rflag == 1 && fflag == 0 && vflag == 1)
	{
		rotate(original, rows, cols, rval, &new1, &rows, &cols);//Call the rotate method to rotate the image
		verticalflip(new1, &new2, rows, cols);//Call the verticalflip method to flip the image vertically
		writeFile(outfile, rows, cols, new2);//Write the image to the output file
		free(original);//Frees original
		free(new1);//Frees new1
		free(new2);//Frees new2
	}

	//If you want to scale, rotate, and flip horizontal
	if (sflag == 1 && rflag == 1 && fflag == 1 && vflag == 0)
	{
		enlarge(original, rows, cols, sval, &new1, &rows, &cols);//Call the enlarge method to scale the image
		rotate(new1, rows, cols, rval, &new2, &rows, &cols);//Call the rotate method to rotate the image
		flip(new2, &new3, rows, cols);//Call the flip method to flip the image horizontally
		writeFile(outfile, rows, cols, new3);//Write the image to the output file
		free(original);//Frees original
		free(new1);//Frees new1
		free(new2);//Frees new2
		free(new3);//Frees new3
	}

	//If you want to scale, rotate, and flip vertically
	if (sflag == 1 && rflag == 1 && fflag == 0 && vflag ==1){
		enlarge(original, rows, cols, sval, &new1, &rows, &cols);//Call the enlarge method to scale the image
		rotate(new1, rows, cols, rval, &new2, &rows, &cols);//Call the rotate method to rotate the image
		verticalflip(new2, &new3, rows, cols);//Call the verticalflip method to flip the image vertically
		writeFile(outfile, rows, cols, new3);//Write the imgae to the output file
		free(original);//Frees original
		free(new1);//Frees new1
		free(new2);//Frees new2
		free(new3);//Frees new3
	}	
return 0;
	
}
