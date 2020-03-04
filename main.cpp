#include <iostream>
#include <memory>
#include <stdlib.h>
#include <utility>

#include "sort.hpp"

void display_array(int *array,int last_index)
{
    for (int i=0;i<last_index;i++)
    {
        std::cout<<array[i]<<", ";
    }
    std::cout<<std::endl;
}


int main()
{
    std::cout<<"Array Size: ";
    int size;
    std::cin>>size;
    std::cout<<std::endl;

    int *array = new int[size];                 // Dynmic memory allocation for array

        for (int i=0; i<size; i++)
        {
            array[i]=rand() % 100000;
        }
        std::cout<<std::endl;
    //display_array(array,size-1);
    quick_sort(array,0,size-1);
    std::cout<<"AFTTER QUICK SORT!!"<<std::endl;
    display_array(array,size-1);

 //  std::cout<<"AFTTER MERGE SORT VVVVVVVVVVVVVV!!"<<std::endl;

 //   display_array(array,size-1);

    delete [] array;                        // Remember to deallocate memory for array

    return 0;
}
