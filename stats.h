/* AUTHOR : KERELLOS EMAD
 * DATE :20-4-2026
 * DESCRIPTION :   This file contains function declarations for analyzing an array of data. The functions include calculating minimum, maximum, mean, median, sorting the array, and printing results. 
 */
 


#ifndef STATS_H
#define STATS_H

/* Prints statistics of the array
 *  array Pointer to the data array
 *  length Number of elements in the array     */
void print_statistics(unsigned char *array, unsigned int length);

/* Prints the array 
 * This function prints all elements of the array.
 *
 * array Pointer to the data array
 * length Number of elements in the array  */
void print_array(unsigned char *array, unsigned int length);

/* Sorts the array (descending order) \
 * This function rearranges the array from largest to smallest. */
void sort_array(unsigned char *array, unsigned int length);

/* Finds the median  
 * This function returns the median value of the sorted array.   */
unsigned char find_median(unsigned char *array, unsigned int length);

/* Finds the mean (average) 
 * This function returns the average value of the array.  */
unsigned char find_mean(unsigned char *array, unsigned int length);

/*  Finds the maximum 
 *  This function returns the largest number in the array. */
unsigned char find_maximum(unsigned char *array, unsigned int length);

/* Finds the minimum 
 * This function returns the smallest number in the array.*/
unsigned char find_minimum(unsigned char *array, unsigned int length);

#endif
