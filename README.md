# SortingAlgs

---

This is a project for my university

---

## Setup

clone the repo and do `make run`

---

## How the tests are ran

There are 4 different vectors of int with different sizes:   
    1. 100 elements, unsorted (id 0)   
    2. 1000 elements, unsorted (id 1)   
    3. 5000 elements, reverse sorted (id 2)   
    4. 10000 elements, unsorted (id 3)   
    
They are generated with random values using rand() and  srand(time(0))

---

## Results

What is this format ?   

id_vector: elapsed_time microseconds 1/0 (if the sort was successfull)

```
Selection sort
0: 30 us 1
1: 1417 us 1
2: 17254 us 1
3: 140072 us 1
Bubble sort
0: 26 us 1
1: 757 us 1
2: 13602 us 1
3: 105980 us 1
Quick sort
0: 3 us 1
1: 77 us 1
2: 6696 us 1
3: 647 us 1
Merge sort
0: 37 us 1
1: 278 us 1
2: 1127 us 1
3: 2145 us 1
Random Sort
$:41019 us 1
```

Note: The Random Sort algorithm was supplied with a vector containing 10 random elements.


A quick overview over the results, we can see that quicksort is the fastest in most cases, but is slower in worst cases on reverse sorted vectors compared to mergesort

---