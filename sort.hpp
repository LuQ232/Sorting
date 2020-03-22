#pragma once
#ifndef SORT_HPP
#define SORT_HPP


#include <iostream>
#include <math.h>


#include "tests.hpp"
#include "array.hpp"

////////////FUNCION TO MERGE TWO ARRAYS INTO ONE //////////////////////
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
    ///////////REWRITE LAST left_index INDEXES ////////
    while(i<left_array_size)
    {
        array[k] = left_array[i];
        i++;
        k++;
    }
    ///////////REWRITE LAST  right_index INDEXES ////////
    while(j<right_array_size)
    {
        array[k] = right_array[j];
        j++;
        k++;
    }

    delete [] left_array;
    delete [] right_array;
}


/////////////////////FUNCTION TO MERGE SORT ARRAY////////////
template<typename Var>
void merge_sort(Var *array,int start_index,int end_index)
{
    if( start_index < end_index )                   // do while we get 1 part of array
    {
        long int middle_index = start_index +( end_index - start_index ) / 2 ; //Calculating middle index
        merge_sort(array,start_index,middle_index);         //MergeSort for left_index side of array
        merge_sort(array,middle_index+1,end_index);         //MergeSort for right_index side of array
        merge(array,start_index,middle_index,end_index);    //When sorten then merge them into one array
    }
}

/////////////////////FUNCTION TO QUICK SORT ARRAY//////////////
template<typename Var>
void quick_sort(Var *array,int start_index,int end_index)
{

    int i = start_index;
    int j = end_index;
    int pivot = array[( start_index + end_index ) / 2 ];    //Pivot is middle index element

    do
    {
        while( array[ i ] < pivot ) // All elements smaller on left_index side of pivot stays on left_index side
             i++;

        while( array[ j ] > pivot ) // All elements bigger on right_index side of pivot stays on right_index side
             j--;

        if( i <= j )    // if elements are not on propper side of pivot we swap them
        {
            swap( array[ i ], array[ j ] );
            i++; j--;
        }

    }while( i <= j );

    if( start_index < j )
        quick_sort( array, start_index, j );  //dividing to smaller problems

    if( end_index > i )
        quick_sort( array, i, end_index );    //dividing to smaller problems

}



// A utility function to swap the values pointed by
// the two pointers
template<typename Var>
void value_swap(Var *a, Var *b)
{
    Var *temp = a;
    a = b;
    b = temp;
}

template<typename Var>
void InsertionSort(Var array[], int *begin, int *end)
{
    int left_index = begin - array;
    int right_index = end - array;

    for (int i = left_index+1; i <= right_index; i++)
    {
        int key = array[i];
        int j = i-1;

        while (j >= left_index && array[j] > key)
        {
            array[j+1] = array[j];
            j = j-1;
        }
        array[j+1] = key;
   }

}

// Function for partition sort small arrays
// Returns next to last element
template<typename Var>
Var* Partition(Var array[], int first, int last)
{
    Var pivot = array[last];
    int i = (first - 1);  // Index of smaller element

    for (int j = first; j <= last- 1; j++)
    {
        // if element is < or ==
        // equal to pivot then swap
        if (array[j] <= pivot)
        {
            i++;
            swap(array[i], array[j]);
        }
    }
    swap(array[i + 1], array[last]);
    return (array + i + 1);
}


// Function finds Median of three
// Return pointer for that value
template<typename Var>
Var *MedianOfThree(Var * a, Var * b, Var * c)
{
    if (*a < *b && *b < *c)
        return b;
    if (*c <= *b && *b <= *a)
        return b;
    if (*a < *c && *c <= *b)
        return c;
    if (*b < *c && *c <= *a)
        return c;
    if (*c <= *a && *a < *b)
        return a;
    if (*b <= *a && *a < *c)
        return a;
}

// A Utility function to perform intro sort
template<typename Var>
void IntrosortUtil(Var array[], int * begin,
                  int * end, int depthLimit)
{
    // Counting size of sent data
    int size = end - begin;

      // Last small parties of data sort by insertionsort
    if (size < 16)
        InsertionSort(array, begin, end);

    // Using heapsort if depthlimit is zero
    if (depthLimit == 0)
    {
        std::make_heap(begin, end+1);
        std::sort_heap(begin, end+1);
    }

    //Finding pivot by a Median of first,middle and last index
    int * pivot = MedianOfThree(begin, begin+size/2, end);

    value_swap(pivot, end);

   // QuickSort for halfs of arrays
    int * partitionPoint = Partition(array, begin-array, end-array);
    IntrosortUtil(array, begin, partitionPoint-1, depthLimit - 1);
    IntrosortUtil(array, partitionPoint + 1, end, depthLimit - 1);
}

//Intro_sort function to calculate depthLimit
// and start sorting
template<typename Var>
void intro_sort(Var array[], int *begin, int *end)
{
    int depthLimit = 2 * log(end-begin);
    IntrosortUtil(array, begin, end, depthLimit);
}





#endif // SORT_HPP













