/*
 * Name: Alex Hollis, Isaias Delgado
 * Course: CSE 3110.002
 * Assignment: Program 2
 * Due Date: February 13, 2015 11:55pm
 */

#include <iostream>
#include <time.h>	// clock()

using namespace std;

void merge(int*, int*, int,int,int);

/*	MERGESORT FUNCTION	*/

void mergesort(int *row, int*col, int bottom, int top)
{
    int middle;		// will act as the pivot point
    if(bottom < top)	// shifts the values in order
    {
        middle = (bottom + top) /2;
        mergesort(row, col, bottom, middle);
        mergesort(row, col, middle+1, top);
        merge(row, col, bottom, middle, top);
    }
}

/*	MERGE FUNCTION		*/

void merge(int *row, int *col, int bottom, int middle, int top)
{
    int a, b, c, d;	// place holders for shifting the values
    a = bottom;
    b = bottom;
    c = middle+1;

/*	Checks, pivots, and increments the position of the values	*/
    while((a <= middle) && (c <= top))
    {
        if(row[a] <= row[c])
        {
            col[b] = row[a];
            a++;
        }
        else
        {
            col[b] = row[c];
            c++;
        }
        b++;
    }
    if(a > middle)
    {
        for(d = c; d <= top; d++)
        {
            col[b] = row[d];
            b++;
        }
    }
    else
    {
        for(d = a; d <= middle; d++)
        {
            col[b] = row[d];
            b++;
        }
    }
    for(d = bottom; d <= top; d++)
    {
        row[d] = col[d];
    }
}

/*	MAIN FUNCTION		*/

int main()
{
    int i, num, row[500000];

    num = sizeof(row) / sizeof(int);
    int col[num];

    for(i = 1; i <= num; i++)
    {
        cin >> row[i];	// reads the data from the input files
    }

    clock_t t;

    t = clock();		// starts the clock
    mergesort(row,col,0,num-1);	// runs the sort function
    t = clock()-t;		// stops the clock

    double time = ((float)t/CLOCKS_PER_SEC);	// stores the elapsed time

/*	prints out the elapsed time for the sorting	*/

    cout << endl;
    cout << "Mergesort: " << (int)t << "  clicks ("
         << time << " seconds)";
    cout << endl << endl;

return 0;
}
