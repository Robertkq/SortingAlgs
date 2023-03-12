#ifndef KQ_SORTING_H
#define KQ_SORTING_H

namespace kq
{
    bool is_sorted(int* first, int* last);

    void selection_sort(int* first, int* last);

    void bubble_sort(int* first, int* last);

    void quick_sort(int* first, int* last);
        int* quick_sort_partition(int* first, int* last);

    void merge_sort(int* first, int* last);
        void merge_sort_partition(int* first, int* mid, int* last);

    void random_sort(int* first, int* last);

}

#endif