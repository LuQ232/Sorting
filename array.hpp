#include <iostream>
#include <math.h>
#include <algorithm>

template<typename Var>
 Var *merge_arrays(Var *left_array,Var *right_array, int left_array_size,int right_array_size)
{

 Var *merged_array = new Var[left_array_size+right_array_size];

    int i=0,j=0,k=0;
    while(i<left_array_size)
    {
        merged_array[k] = left_array[i];
        i++;
        k++;
    }

    while(j<right_array_size)
    {
        merged_array[k] = right_array[j];
        j++;
        k++;
    }
return merged_array;

}
