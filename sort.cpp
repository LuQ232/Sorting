#include <iostream>
#include "sort.h"



class Sort
    {

        public:
            template<typename Var>
            static void show(Var test);

            template<typename Var>
            static void merge_sort(Var test);

            template<typename Var>
            static void quick_sort(Var test);

            template<typename Var>
            static void intro_sort(Var test);

    };


template<typename Var>
void Sort::show(Var test)
{
    std::cout<<"TEST, VARIABLE ->>>  "<<test<<std::endl;
}

template<typename Var>
void Sort::merge_sort(Var test)
{
    std::cout<<"Merge Sort, VARIABLE ->>>  "<<test<<std::endl;
}

template<typename Var>
void Sort::quick_sort(Var test)
{
    std::cout<<"Quick Sort, VARIABLE ->>>  "<<test<<std::endl;
}

template<typename Var>
void Sort::intro_sort(Var test)
{
    std::cout<<"Intro Sort, VARIABLE ->>>  "<<test<<std::endl;
}
