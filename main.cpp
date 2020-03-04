#include <iostream>
#include <memory>
#include <stdlib.h>
#include <utility>

#include "sort.hpp"
#include "timer.hpp"

#define NUMBER_OF_ARRAYS 100


void display_array(int *array,int size_of_array)
{
    for (int i=0;i<size_of_array;i++)
    {
        std::cout<<array[i]<<", ";
    }
    std::cout<<std::endl;
}


int main()
{
    Timer timer;
    Timer timer_of_all_sortings;
    std::cout<<"Array Size: ";
    int size;
    std::cin>>size;
    std::cout<<std::endl;



    //MAKES 100 arrays
    int **array_of_arrays = new int *[NUMBER_OF_ARRAYS];
    for (int i=0; i<NUMBER_OF_ARRAYS; i++)
        {
            array_of_arrays[i] = new int[size];

        }

    //FILL EVERY ARRAY WITH RAND
    for (int i=0; i<NUMBER_OF_ARRAYS; i++)
        {
            for (int j=0; j<size; j++)
            {
                array_of_arrays[i][j]=rand() % 100000;
            }
        }


        timer_of_all_sortings.start();  // START TIMER OF 100 SORTS
    for (int i=0; i<NUMBER_OF_ARRAYS; i++)
        {
            std::cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<std::endl;
            std::cout<<"Sort number: "<<i<<std::endl;
            std::cout<<"BEFORE SORT: "<<std::endl;
           // display_array(array_of_arrays[i],size);
            timer.start();
            quick_sort(array_of_arrays[i],0,size-1);
            timer.stop();
            timer.print_time_duration();
            std::cout<<"AFTER SORT: "<<std::endl;
           // display_array(array_of_arrays[i],size);
            std::cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<std::endl;

        }
        timer_of_all_sortings.stop();       // STOP TIMER OF 100 SORTS
        timer_of_all_sortings.print_time_duration();

        //TEST - EACH ARRRAY 1 MILION LONG
        //MERGE 56 SEKUND
        //QUICK 17 SEKUND
        //INTRO 52 SEKUND

        for (int i=0; i<NUMBER_OF_ARRAYS; i++)
        {
           delete [] array_of_arrays[i];
        }
        delete [] array_of_arrays;

    return 0;
}
