/***************
Name:   Alex Hollis, Isaias Delgado
Course: CSCE 3110.002
Assignment: Program 2
Due Date:   February 13, 2015 11:55PM
 ****************/

#include <cstdlib>
#include <iostream>
#include <vector>
#include <time.h>
#include <algorithm>


using namespace std;

/*
 * 
 */

void quicksort(vector<int>& a, int left, int right) {                     // Pass vector by reference
    int i = left, j = right;
    int tmp;
    int pivot = a[(left + right) / 2];                                    // Calculate median as pivot (median of 3 approach)

                                                                            // Begin partitioning the vector:
    while (i <= j) {
        while (a[i] < pivot)                                              // sort lesser values to left of pivot
            i++;
        while (a[j] > pivot)                                             // sort greater values to right of pivot
            j--;
        if (i <= j) {
            swap(a[i], a[j]);                                           // move numbers to sort.
            i++;
            j--;
        }
    };

                                                                            // Recursively call the QuickSort Function:
    if (left < j)
        quicksort(a, left, j);
    if (i < right)
        quicksort(a, i, right);
}

int main(int argc, char** argv) {


    vector<int> a;

    int left = 0;
    int right;

    int buff;

    while (cin >> buff) {                                                   // Reading in numbers from standard input
        a.push_back(buff);                                                  // Pushing numbers into the vector container


    }

    right = a.size() - 1;

    clock_t t;          

    t = clock();                                                                // starting timer.....
    quicksort(a, left, right);                                                  // calling the sort
    t = clock() - t;                                                            // ending the timer.....
    float time = ((float) t / CLOCKS_PER_SEC);                                  // calculating time to run


    cout << "Quicksort: " << (int) t << " clicks (" << time << " seconds)" << endl;







    return 0;
}
