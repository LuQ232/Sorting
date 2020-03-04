#include <iostream>



template<typename Var>
void show(Var test)
{
    std::cout<<"TEST, VARIABLE ->>>  "<<test<<std::endl;
}

template<typename Var>
void merge(Var *array,int start_index, int middle_index, int end_index)
{
    int left_array_size, right_array_size;

    left_array_size = middle_index-start_index+1;
    right_array_size = end_index-middle_index;

    int left_array[left_array_size], right_array[right_array_size];

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

}

template<typename Var>
void merge_sort(Var *array,int start_index,int end_index)
{
    int middle_index;
    if( start_index < end_index )
    {
        int middle_index = start_index +( end_index - start_index ) / 2 ; //Calculating middle index
        merge_sort(array,start_index,middle_index);         //MergeSort for left array
        merge_sort(array,middle_index+1,end_index);
        merge(array,start_index,middle_index,end_index);
    }
}


template<typename Var>
void swap(Var &first, Var &second )
{

        Var tmp = first;
        first = second;
        second = tmp;
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














