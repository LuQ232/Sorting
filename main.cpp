#include <iostream>
#include <memory>
#include <stdlib.h>
#include <utility>

#include "sort.hpp"
#include "timer.hpp"
#include "array.hpp"

#define NUMBER_OF_ARRAYS 2


void display_array(int *array,int size_of_array)
{
    for (int i=0;i<size_of_array;i++)
    {
        std::cout<<array[i]<<", ";
    }
    std::cout<<std::endl;
}


void reverse(int arr[], int first_index, int last_index)
{
	if (first_index < last_index)
	{
		swap(arr[first_index], arr[last_index]);
		reverse(arr, first_index + 1, last_index - 1);
	}
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
        // TO NIE MOZE BYC TAK PROSTO JEDNAK :))))

    std::cout<<"1st array: "<<std::endl;
    display_array(array_of_arrays[0],size);
    std::cout<<"2nd array: "<<std::endl;
    display_array(array_of_arrays[1],size);

    int *merged= new int [size*2];
    merged = merge_arrays(array_of_arrays[0],array_of_arrays[1],size,size);
       std::cout<<"MERGED "<<std::endl;
    display_array(merged,size*2);
   /*

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
*/
        for (int i=0; i<NUMBER_OF_ARRAYS; i++)
        {
           delete [] array_of_arrays[i];
        }

        delete [] array_of_arrays;

    return 0;
}
