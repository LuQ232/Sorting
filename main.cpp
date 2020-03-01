#include <iostream>
#include <memory>
//#include "sort.h"
#include "sort.cpp"


int main()
{

    Sort test; //SORT OBJECT

    int a=0;
    double b=0.5;
    int c=5;
    float d=0.01;
    test.show(a); // SORT FUNCTION
    test.merge_sort(b);
    test.quick_sort(c);
    test.intro_sort(d);


    std::cout<<"Array Size: ";
    int size;
    std::cin>>size;
    std::cout<<std::endl;


    auto array = std::make_unique<int[]>(size);  // Dynmic memory allocation for array
                                                 // smart pointer DONT need DELETE
        for (int i=0; i<size; i++)
        {
            array[i]=i;
            std::cout<<array[i]<<std::endl;
        }
    return 0;
}
