### Question:

Write a program that generates a list of N random integers in the range [1, 1000], where N
is provided by the user at run time. Then, perform the following tasks:
(a) Ask the user to choose a sorting algorithm from the following:
• Bubble Sort
• Selection Sort
• Insertion Sort
• Merge Sort
(b) Sort the randomly generated numbers using the chosen algorithm.
(c) Print the numbers before and after sorting.
(d) Display the total number of comparisons and swaps (if applicable) performed by the chosen algorithm.


### Solution:

## (a) Explanation of Data Structures

The array of integers is stored in a standard C array arr[].

Two global counters are used:

comparisons to count the number of comparisons performed.

swaps to count the number of swaps or moves performed during sorting.

## (b) Description of Functions

swap(int *a, int *b)
Swaps two integers and increments the swap counter.

bubbleSort(int arr[], int n)
Implements Bubble Sort on the array. Increments comparisons and swaps appropriately.

selectionSort(int arr[], int n)
Implements Selection Sort. Counts comparisons and swaps.

insertionSort(int arr[], int n)
Implements Insertion Sort. Counts comparisons and movements of elements.

merge(int arr[], int l, int m, int r)
Helper function for Merge Sort. Merges two subarrays and counts comparisons and movements.

mergeSort(int arr[], int l, int r)
Implements Merge Sort recursively using the merge function.

printArray(int arr[], int n)
Prints the elements of the array.

## (c) Overview of main()

Asks the user to input the number of random integers, N.

Generates N random integers in the range [1,1000] using rand().

Displays the original unsorted array.

Prompts the user to choose a sorting algorithm from:

Bubble Sort

Selection Sort

Insertion Sort

Merge Sort

Calls the selected sorting function.

Displays the sorted array.

Prints the total number of comparisons and swaps/moves.

## (d) Sample output:

Enter the number of random integers: 10

Original Array:
523 12 785 234 98 431 672 11 90 305

Choose Sorting Algorithm:
1. Bubble Sort
2. Selection Sort
3. Insertion Sort
4. Merge Sort
2

Sorted Array:
11 12 90 98 234 305 431 523 672 785

Total comparisons: 45
Total swaps/moves: 9