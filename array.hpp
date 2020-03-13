#pragma once
#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <math.h>
#include <algorithm>

#include "tests.hpp"


////////////////////DECLARATION QUICK INCLUDED IN SORT.HPP/////////////
/////////because  array.hpp is included faster??? idk /////////////////
template<typename Var>
void quick_sort(Var *array,int start_index,int end_index);
///////////////////////////////////////////////////////////////////////






template<typename Var>
void display_array(Var *array,int size_of_array)
{
    for (int i=0;i<size_of_array;i++)
    {
        std::cout<<array[i]<<", ";
    }
    std::cout<<std::endl;
}



template<typename Var>
void swap(Var &first, Var &second )
{
    Var temp = first;
    first = second;
    second = temp;
}



template<typename Var>
void reverse_array( Var *array, int size)
{
    for ( int i = 0; i < size / 2; i++ )
    {
        int tmp = array[i];
        array[i] = array[size - i - 1];
        array[size - i - 1] = tmp;
    }
}

//FUNCTION TO MERGE 2 ARRAYS INTO ONE//
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
delete [] merged_array;
}


template<typename Var>
void percentage_sort(Var *array, int first_index, int last_index)
{
    /* UNCOMMENT FOR TESTS
    std::cout<<"Original array:"<<std::endl;
    display_array(array,last_index+1);
    */

    std::cout<<"Sort percentage: ";

    double percentage=0.0;
    std::cin >> percentage;
    std::cout<<std::endl;

    while(percentage<0 || percentage>100|| std::cin.fail())
    {
        std::cout<<"Percentage is too low! One more time:"<<std::endl;

		std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::cin >> percentage;
    }

    int split_index=(last_index+1) * percentage/100;


 Var *array_to_sort= new Var[split_index];                    // left array - to sort
 Var *array_not_to_sort = new Var[last_index - split_index + 1];  // right array - tmp

 int i=0,j=0;
    while(i<split_index)
    {
        array_to_sort[i]=array[i];
        i++;
    }

    while(i<=last_index)
    {
        array_not_to_sort[j]=array[i];
        i++;
        j++;
    }

/*          UNCOMMENT FOR TESTS
     std::cout<<"Array to sort:"<<std::endl;
     display_array(array_to_sort,split_index);

     std::cout<<"Array not to sort:"<<std::endl;
     display_array(array_not_to_sort,last_index-split_index+1);

     quick_sort(array_to_sort,0,split_index-1);

     std::cout<<"Array after sort:"<<std::endl;
     display_array(array_to_sort,split_index);
*/

 array = merge_arrays(array_to_sort,array_not_to_sort,split_index,last_index-split_index+1);

//     std::cout<<"MERGED PERCENTAGE SORTED ARRAY: "<<std::endl;
//   display_array(array,last_index+1);

}




#endif // ARRAY_HPP



