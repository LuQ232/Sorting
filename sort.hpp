#pragma once
#ifndef SORT_HPP
#define SORT_HPP



#include<bits/stdc++.h>
#include <iostream>
#include <math.h>
#include <algorithm>


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
    ///////////REWRITE LAST LEFT INDEXES ////////
    while(i<left_array_size)
    {
        array[k] = left_array[i];
        i++;
        k++;
    }
    ///////////REWRITE LAST  RIGHT INDEXES ////////
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
        merge_sort(array,start_index,middle_index);         //MergeSort for left side of array
        merge_sort(array,middle_index+1,end_index);         //MergeSort for right side of array
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
        while( array[ i ] < pivot ) // All elements smaller on left side of pivot stays on left side
             i++;

        while( array[ j ] > pivot ) // All elements bigger on right side of pivot stays on right side
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



int parentId( int n ) {
    return (n -1) / 2;
}

int lChildId( int n ) {
    return 2*n + 1;
}
template <typename var>
array_elements_swap( var array[], int id1, int id2 ) {
    var tmp = array[id1];
    array[id1] = array[id2];
    array[id2] = tmp;
}

template <typename var>
void siftDown( var array[], int rootIndex, int last_index ) {
    int root = rootIndex;
    while ( lChildId( root ) <= last_index ) {
        int child = lChildId( root );
        int swap = root;
        if ( array[swap] < array[child] )
            swap = child;
        if ( child+1 <= last_index )
            if ( array[swap] < array[child+1] )
                swap = child + 1;
        if ( swap == root )
            return;
        else {
            array_elements_swap( array, root, swap );
            root = swap;
        }
    }
}

template <typename var>
void heapify( var *array, int first_index, int last_index ) {
    int start = parentId( last_index );
    while ( start >= first_index ) {
        siftDown( array, start, last_index );
        start -= 1;
    }
}



template <typename var>
int quick_sort_and_split( var *array, int first, int last, bool reversed ) {
    int refIndex = first + rand()%(last - first);
    var refValue = array[refIndex];
    array_elements_swap( array, refIndex, last );

    int position = first;
    for ( int i = first; i <= last-1; i++ )
        if( (reversed ? (array[i] > refValue):(array[i] < refValue)) ) {
            array_elements_swap( array, i, position );
            position++;
        }
    array_elements_swap( array, position, last );
    return position;
}


template <typename var>
void heap_sort( var *array, int first_index, int last_index ) {
    int last = last_index;
    heapify( array, first_index, last_index );
    while ( last > first_index + 1 ) {
        array_elements_swap( array, first_index, last );
        last--;
        heapify( array, first_index, last );
    }
}

template <typename var>
void intro_sort( var *array, int first_index, int last_index, int maxDepth ) {
    if ( first_index < last_index ) {
        if ( !maxDepth ) {
            heap_sort( array, first_index, last_index );
            return;
        }
        int n = quick_sort_and_split( array, first_index, last_index, false ); //QUICK)SORT USE
        intro_sort( array, first_index, n-1, maxDepth-1 );
        intro_sort( array, n+1, last_index, maxDepth-1 );
    }
}





#endif // SORT_HPP













