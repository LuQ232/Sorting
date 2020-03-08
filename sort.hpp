#pragma once
#ifndef SORT_HPP
#define SORT_HPP




#include <iostream>
#include <math.h>
#include <algorithm>


#include "tests.hpp"
#include "array.hpp"

template<typename Var>
void merge(Var *array,int start_index, int middle_index, int end_index)
{
    Var left_array_size, right_array_size;

    left_array_size = middle_index-start_index+1;
    right_array_size = end_index-middle_index;

    Var *left_array = new Var[left_array_size];
    Var *right_array = new Var[right_array_size];


    //////////////////FILLING BOTH ARRAYS/////////////////////////

    for(int i=0;i<left_array_size;i++)
        {
            left_array[i]=array[start_index+i];
        }

    for(int j=0;j<right_array_size;j++)
        {
            right_array[j]=array[middle_index+1+j];
        }
    /////////////////MERGING BOTH ARRAYS TO MAIN ARRAY/////////////
    int i=0,j=0,k=start_index;
    while(i<left_array_size && j<right_array_size)
    {
        if(left_array[i]<=right_array[j])
        {
            array[k] = left_array[i];
            i++;
        }else{
            array[k] = right_array[j];
            j++;
        }
        k++;
    }

    while(i<left_array_size)
    {
        array[k] = left_array[i];
        i++;
        k++;
    }

    while(j<right_array_size)
    {
        array[k] = right_array[j];
        j++;
        k++;
    }

    delete [] left_array;
    delete [] right_array;
}

template<typename Var>
void merge_sort(Var *array,int start_index,int end_index)
{
    if( start_index < end_index )                   // do while we get 1 part of array
    {
        long int middle_index = start_index +( end_index - start_index ) / 2 ; //Calculating middle index
        merge_sort(array,start_index,middle_index);         //MergeSort for left side of array
        merge_sort(array,middle_index+1,end_index);         //MergeSort for right side of array
        merge(array,start_index,middle_index,end_index);    //When sorten then merge them into one array
    }
}


template<typename Var>
void quick_sort(Var *array,int start_index,int end_index)
{

    int i = start_index;
    int j = end_index;
    int pivot = array[( start_index + end_index ) / 2 ];
    do
    {
        while( array[ i ] < pivot )
             i++;

        while( array[ j ] > pivot )
             j--;

        if( i <= j )
        {
            swap( array[ i ], array[ j ] );
            i++; j--;
        }
    }while( i <= j );

    if( start_index < j )
        quick_sort( array, start_index, j );

    if( end_index > i )
        quick_sort( array, i, end_index );

}


template<typename Var>
int Partition(Var *array, int left, int right) {
	int pivot = array[right];               // last index is PIVOT
	int i = left;

	//Elements lower than pivot will be pushed to the left side  of i ( INDEX)
	//Elements higher than pivot will be pushed to the right side  of i ( INDEX)

	// The most important is to move the pivot (i++) after swap
	// because we want the element to be placed before PIVOT
	for (int j = left; j < right; ++j)
	{
		if (array[j] <= pivot)
		{
		    swap(array[i],array[j]);
			i++;
		}
	}

	array[right] = array[i];
	array[i] = pivot;

	return i;           // returning index of PIVOT element
}


template<typename Var>
void max_heapify(Var* array, int heapSize, int index) {
	int left = (index + 1) * 2 - 1;
	int right = (index + 1) * 2;
	int largest = 0;

	if (left < heapSize && array[left] > array[index])
		largest = left;
	else
		largest = index;

	if (right < heapSize && array[right] > array[largest])
		largest = right;

	if (largest != index)
	{
	    swap(array[index],array[largest]);
		max_heapify(array, heapSize, largest);
	}
}

template<typename Var>
void heap_sort(Var* array, int size) {
	int heapSize = size;

	for(int p = (heapSize - 1) / 2; p >= 0; --p)
		max_heapify(array, heapSize, p);

	for(int i = size - 1; i > 0; --i)
	{
	    swap(array[i],array[0]);
		--heapSize;
		max_heapify(array, heapSize, 0);
	}
}


template<typename Var>
void insertion_sort(Var* array, int size) {
	for (int i = 1; i < size; ++i)
	{
		int j = i;

		while ((j > 0))
		{
			if (array[j - 1] > array[j])
			{
                swap(array[j-1],array[j]);
				--j;
			}
			else
			{
				break;
			}
		}
	}
}


///////////////INTRO SORT////////////////////
//  It is a merge of quick_sort, heap_sort //
//  and my change is a insertion_sort when //
//  array is really small ( less than 20)  //
/////////////////////////////////////////////
template<typename Var>
void intro_sort(Var* array, int size) {
	int partition_size = Partition(array, 0, size - 1);

	if (partition_size < 20)             // if PIVOT INDEX is lover then 16 insertSort
	{
		insertion_sort(array, size);
	}
	else if (partition_size >(2 * log(size))) // if PIVOT INDEX is bigger than ___ then heap_sort is the most effective (GOOGLE KNOWLEDGE)
	{
		heap_sort(array, size);
	}
	else
	{
		quick_sort(array, 0, size - 1); // medium-size array then go quick_sort
	}
}





#endif // SORT_HPP













