#include <iostream>
#include <memory>
#include <stdlib.h>
#include <utility>

#include "sort.hpp"
#include "timer.hpp"
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
    Timer timer;
    std::cout<<"Array Size: ";
    int size;
    std::cin>>size;
    std::cout<<std::endl;

    int *array_for_quick_sort = new int[size];                           // Dynmic memory allocation for array
    int *array_for_merge_sort = new int[size];
    int *array_for_intro_sort = new int[size];

        for (int i=0; i<size; i++)
        {
            array_for_quick_sort[i]=rand() % 100000;
            array_for_merge_sort[i] = array_for_quick_sort[i];
            array_for_intro_sort[i] = array_for_quick_sort[i];
        }
        std::cout<<std::endl;

    std::cout<<"AFTER MERGE SORT VVVV"<<std::endl;
    timer.start();
    merge_sort(array_for_merge_sort,0,size-1);
    timer.stop();
    timer.print_time_duration();
    std::cout<<std::endl;

    std::cout<<"AFTER QUICK SORT VVVV"<<std::endl;
    timer.start();
    quick_sort(array_for_quick_sort,0,size-1);
    timer.stop();
    timer.print_time_duration();

    std::cout<<std::endl;

    std::cout<<"AFTER INTRO SORT!!"<<std::endl;
    timer.start();
    intro_sort(array_for_intro_sort,size);
    timer.stop();
    timer.print_time_duration();
    std::cout<<std::endl;



    delete [] array_for_quick_sort;                                     // Remember to deallocate memory for array
    delete [] array_for_merge_sort;
    delete [] array_for_intro_sort;
    return 0;
}
