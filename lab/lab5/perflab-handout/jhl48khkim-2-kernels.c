/********************************************************
 * Kernels to be optimized for the CS:APP Performance Lab
 ********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "defs.h"

/* 
 * Please fill in the following team struct 
 */
team_t team = {
    "jk",              /* Team name */

    "jhl48",                /* First member Route-Y ID */
    "Jae Lee",     /* First member full name */
    "nagneeve@gmail.com",  /* First member email address */

    "khkim",                   /* Second member Route-Y ID */
    "Allen Kim",                   /* Second member full name (leave blank if none) */
    "allen0129@gmail.com"                    /* Second member email addr (leave blank if none) */
};

/***************
 * ROTATE KERNEL
 ***************/

/******************************************************
 * Your different versions of the rotate kernel go here
 ******************************************************/

/* 
 * naive_rotate - The naive baseline version of rotate 
 */
char naive_rotate_descr[] = "naive_rotate: Naive baseline implementation";
void naive_rotate(int dim, pixel *src, pixel *dst) 
{
    int i, j;

    for (i = 0; i < dim; i++)
	for (j = 0; j < dim; j++)
	    dst[RIDX(dim-1-j, i, dim)] = src[RIDX(i, j, dim)];
}

/* 
 * rotate - Your current working version of rotate
 * IMPORTANT: This is the version you will be graded on
 */
char rotate_descr[] = "rotate: Current working version";
void rotate(int dim, pixel *src, pixel *dst) 
{
    int i, j;
    int i1, j1;
	
	for(i = 0; i < dim; i+=16){
		for(j = 0; j < dim; j+=16){	
			for (i1 = i; i1 < i+16; i1++){
				for (j1 = j; j1 < j+16; j1++){
					dst[RIDX(dim-1-i1, j1, dim)] = src[RIDX(j1, i1, dim)];
				}
			}
		}
	}
}

/*********************************************************************
 * register_rotate_functions - Register all of your different versions
 *     of the rotate kernel with the driver by calling the
 *     add_rotate_function() for each test function. When you run the
 *     driver program, it will test and report the performance of each
 *     registered test function.  
 *********************************************************************/

void register_rotate_functions() 
{
    add_rotate_function(&naive_rotate, naive_rotate_descr);   
    add_rotate_function(&rotate, rotate_descr);   
    /* ... Register additional test functions here */
}


/***************
 * SMOOTH KERNEL
 **************/

/***************************************************************
 * Various typedefs and helper functions for the smooth function
 * You may modify these any way you like.
 **************************************************************/

/* A struct used to compute averaged pixel value */
typedef struct {
    int red;
    int green;
    int blue;
    int num;
} pixel_sum;

/* Compute min and max of two integers, respectively */
static int min(int a, int b) { return (a < b ? a : b); }
static int max(int a, int b) { return (a > b ? a : b); }

/* 
 * initialize_pixel_sum - Initializes all fields of sum to 0 
 */
static void initialize_pixel_sum(pixel_sum *sum) 
{
    sum->red = sum->green = sum->blue = 0;
    sum->num = 0;
    return;
}

/* 
 * accumulate_sum - Accumulates field values of p in corresponding 
 * fields of sum 
 */
static void accumulate_sum(pixel_sum *sum, pixel p) 
{
    sum->red += (int) p.red;
    sum->green += (int) p.green;
    sum->blue += (int) p.blue;
    sum->num++;
    return;
}

/* 
 * assign_sum_to_pixel - Computes averaged pixel value in current_pixel 
 */
static void assign_sum_to_pixel(pixel *current_pixel, pixel_sum sum) 
{
    current_pixel->red = (unsigned short) (sum.red/sum.num);
    current_pixel->green = (unsigned short) (sum.green/sum.num);
    current_pixel->blue = (unsigned short) (sum.blue/sum.num);
    return;
}

/* 
 * avg - Returns averaged pixel value at (i,j) 
 */
static pixel avg(int dim, int i, int j, pixel *src) 
{
    int ii, jj;
    pixel_sum sum;
    pixel current_pixel;

    initialize_pixel_sum(&sum);
    for(ii = max(i-1, 0); ii <= min(i+1, dim-1); ii++) 
	for(jj = max(j-1, 0); jj <= min(j+1, dim-1); jj++) 
	    accumulate_sum(&sum, src[RIDX(ii, jj, dim)]);

    assign_sum_to_pixel(&current_pixel, sum);
    return current_pixel;
}

/******************************************************
 * Your different versions of the smooth kernel go here
 ******************************************************/

/*
 * naive_smooth - The naive baseline version of smooth 
 */
char naive_smooth_descr[] = "naive_smooth: Naive baseline implementation";
void naive_smooth(int dim, pixel *src, pixel *dst) 
{
    int i, j;

    for (i = 0; i < dim; i++)
	for (j = 0; j < dim; j++)
	    dst[RIDX(i, j, dim)] = avg(dim, i, j, src);
}

/*
 * smooth - Your current working version of smooth. 
 * IMPORTANT: This is the version you will be graded on
 */
char smooth_descr[] = "smooth: Current working version";
void smooth(int dim, pixel *src, pixel *dst) 
{
	/*top-left*/
	dst[0].red = (src[0].red + src[1].red + src[dim].red + src[dim + 1].red)/4;
	dst[0].green = (src[0].green + src[1].green + src[dim].green + src[dim + 1].green)/4;
	dst[0].blue = (src[0].blue + src[1].blue + src[dim].blue + src[dim + 1].blue)/4;
	
	/*top-right*/
	dst[dim-1].red = (src[dim-2].red + src[dim-1].red + src[dim + dim - 2].red + src[dim + dim - 1].red)/4;
	dst[dim-1].green = (src[dim-2].green + src[dim-1].green + src[dim + dim -2].green + src[dim + dim - 1].green)/4;
	dst[dim-1].blue = (src[dim-2].blue + src[dim-1].blue + src[dim + dim -2].blue + src[dim + dim - 1].blue)/4;
	
	/*bot-left*/
	int bl = dim*dim - dim;
	dst[bl].red = (src[bl-dim].red + src[bl-dim+1].red + src[bl].red + src[bl+1].red)/4;
	dst[bl].green = (src[bl-dim].green + src[bl-dim+1].green + src[bl].green + src[bl+1].green)/4;
	dst[bl].blue = (src[bl-dim].blue + src[bl-dim+1].blue + src[bl].blue + src[bl+1].blue)/4;
	
	/*bot-right*/
	int br = dim*dim - 1;
	dst[br].red = (src[br-dim-1].red + src[br-dim].red + src[br-1].red + src[br].red)/4;
	dst[br].green = (src[br-dim-1].green + src[br-dim].green + src[br-1].green + src[br].green)/4;
	dst[br].blue = (src[br-dim-1].blue + src[br-dim].blue + src[br-1].blue + src[br].blue)/4;
	
	/*left*/
	int i, j, index;
	int length = dim*(dim-2);
	for(i = dim; i <= length; i+=dim){
		dst[i].red = (src[i-dim].red + src[i-dim+1].red + src[i].red + src[i+1].red + src[i+dim].red + src[i+dim+1].red)/6;
		dst[i].green = (src[i-dim].green + src[i-dim+1].green + src[i].green + src[i+1].green + src[i+dim].green + src[i+dim+1].green)/6;
		dst[i].blue = (src[i-dim].blue + src[i-dim+1].blue + src[i].blue + src[i+1].blue + src[i+dim].blue + src[i+dim+1].blue)/6;
	} 
	
	/*right*/
	length += dim-1;
	for(i = dim*2-1; i <= length; i+=dim){
		dst[i].red = (src[i-dim].red + src[i-dim-1].red + src[i].red + src[i-1].red + src[i+dim].red + src[i+dim-1].red)/6;		
		dst[i].green = (src[i-dim].green + src[i-dim-1].green + src[i].green + src[i-1].green + src[i+dim].green + src[i+dim-1].green)/6;		
		dst[i].blue = (src[i-dim].blue + src[i-dim-1].blue + src[i].blue + src[i-1].blue + src[i+dim].blue + src[i+dim-1].blue)/6;				
	}
	
	/*top*/
	length = dim-2;
	for(i = 1; i <= length; i++){
		dst[i].red = (src[i-1].red + src[i].red + src[i+1].red + src[dim+i-1].red + src[i+dim].red + src[i+dim+1].red)/6;		
		dst[i].green = (src[i-1].green + src[i].green + src[i+1].green + src[i+dim-1].green + src[i+dim].green + src[i+dim+1].green)/6;		
		dst[i].blue = (src[i-1].blue + src[i].blue + src[i+1].blue + src[dim+i-1].blue + src[i+dim].blue + src[i+dim+1].blue)/6;						
	}
	
	/*bottom*/
	length = dim*dim-2;
	for(i = dim*(dim-1)+1; i <= length; i++){
		dst[i].red = (src[i-1].red + src[i].red + src[i+1].red + src[i-dim-1].red + src[i-dim].red + src[i-dim+1].red)/6;		
		dst[i].green = (src[i-1].green + src[i].green + src[i+1].green + src[i-dim-1].green + src[i-dim].green + src[i-dim+1].green)/6;				
		dst[i].blue = (src[i-1].blue + src[i].blue + src[i+1].blue + src[i-dim-1].blue + src[i-dim].blue + src[i-dim+1].blue)/6;										
	}

	/*Center*/
	length = dim*(dim-2)+1;
	for(i = dim + 1; i <= length; i+=dim){
		for(j = 0; j <= dim-3; j++){
			index = i + j;
			dst[index].red = (src[index-dim-1].red + src[index-dim].red + src[index-dim+1].red + src[index-1].red + src[index].red + src[index+1].red +
								src[index+dim-1].red + src[index+dim].red + src[index+dim+1].red)/9;
			dst[index].green = (src[index-dim-1].green + src[index-dim].green + src[index-dim+1].green + src[index-1].green + src[index].green + src[index+1].green +
								src[index+dim-1].green + src[index+dim].green + src[index+dim+1].green)/9;
			dst[index].blue = (src[index-dim-1].blue + src[index-dim].blue + src[index-dim+1].blue + src[index-1].blue + src[index].blue + src[index+1].blue +
								src[index+dim-1].blue + src[index+dim].blue + src[index+dim+1].blue)/9;
			
		}
	}
	
}


/********************************************************************* 
 * register_smooth_functions - Register all of your different versions
 *     of the smooth kernel with the driver by calling the
 *     add_smooth_function() for each test function.  When you run the
 *     driver program, it will test and report the performance of each
 *     registered test function.  
 *********************************************************************/

void register_smooth_functions() {
    add_smooth_function(&smooth, smooth_descr);
    add_smooth_function(&naive_smooth, naive_smooth_descr);
    /* ... Register additional test functions here */
}

