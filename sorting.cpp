#include "sorting.h"
#include <iostream>

namespace kq
{
    bool is_sorted(int* first, int* last)
    {
        for(; first != last - 1; ++first)
        {
            if(*first > *(first+1))
                return false;
        }
        return true;
    }

    void selection_sort(int* first, int* last)
    {
        for(;first < last - 1; ++first)
        {
            for(int* select = first + 1; select != last; ++select)
            {
                if(*first > *select)
                {
                    int aux = *first;
                    *first = *select;
                    *select = aux;
                }
            }
        }
    }

    void bubble_sort(int* first, int* last)
    {
        bool keep_sorting = true;
        while(keep_sorting == true)
        {
            keep_sorting = false;
            for(int* select = first; select != last - 1; ++select)
            {
                if(*(select) > *(select + 1))
                {
                    keep_sorting = true;
                    int aux = *select;
                    *select = *(select+1);
                    *(select+1) = aux;
                }
            }
        }
    }

    void quick_sort(int* first, int* last)
    {
        if(first == last)
        {
            return;
        }
        else
        {
            int* p = quick_sort_partition(first, last);
            quick_sort(first, p);
            quick_sort(++p, last);
        }
    }
    
    int* quick_sort_partition(int* first, int* last)
    {
        int* pivot = last - 1;
        int* smaller = first;
        for(; first != last; ++first)
        {
            if(*first < *pivot)
            {
                int aux = *first;
                *first = *smaller;
                *smaller = aux;
                ++smaller;
            }
        }
        int aux = *pivot;
        *pivot = *smaller;
        *smaller = aux;
        return smaller;
    }

    void merge_sort(int* first, int* last)
    {
        if(first == last - 1)
        {
            return;
        }
        else
        {
            int* mid = first + (last - first) / 2;
            merge_sort(first, mid);
            merge_sort(mid, last);
            merge_sort_partition(first, mid, last);
        }
    }

    void merge_sort_partition(int* first, int* mid, int* last)
    {
        int leftSize = mid - first;
        int rightSize = last - mid;

        int* leftArray = new int[leftSize];
        int* rightArray = new int[rightSize];

        for(int i = 0; i < leftSize; ++i)
        {
            leftArray[i] = first[i];
        }
        for(int i = 0; i < rightSize; ++i)
        {
            rightArray[i] = mid[i];
        }

        int leftIndex = 0;
        int rightIndex = 0;
        int mergeIndex = 0;
        while(leftIndex < leftSize && rightIndex < rightSize)
        {
            if(leftArray[leftIndex] < rightArray[rightIndex])
            {
                first[mergeIndex++] = leftArray[leftIndex++];
            }
            else
            {
                first[mergeIndex++] = rightArray[rightIndex++];
            }
        }
        while(leftIndex < leftSize)
        {
            first[mergeIndex++] = leftArray[leftIndex++];
        }
        while(rightIndex < rightSize)
        {
            first[mergeIndex++] = rightArray[rightIndex++];
        }

        delete[] leftArray;
        delete[] rightArray;
    }

    void random_sort(int* first, int* last)
    {
        int N = last - first;
        while(!is_sorted(first, last))
        {
            for(int i = 0; i < N; ++i)
            {
                int j = rand() % N;
                int aux = first[i];
                first[i] = first[j];
                first[j] = aux;
            }
        }
    }

} // n