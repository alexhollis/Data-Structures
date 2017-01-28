/********************************************
Name:   		Isaias Delgado, Alex Hollis
Course: 		CSCE 3110.002
Assignment:     Program 5, DFS
Due Date:       April 18, 2015 at 11:55PM
 ********************************************/


#include<stdio.h>

void DFS();

int Table[25][25], // 2-D array of values
visited[25], // array of visited values
n; // number of vertices

void main() {
    int i, j, k; // counters for the iteration of the table positions

    n = 25; // number of nodes in the table

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &Table[i][j]); // reads the values of the 2-D array

        }
        
    }
    for (i = 0; i < n; i++) {
        visited[i] = 0; 
    }
    printf("DFS: ");
    DFS(0); // calls on the DFS function
    printf("\n");
}

/*
 ** DFS FUNCTION **
receives the position of the visited value
and iterates through the table until it finds 
a value less than 1
 */

void DFS(int i) {
    int j;


    printf("%d ", i); // prints the parent node provided to DFS for analysis.
    visited[i] = 1;  //  mark parent node as visited.



    for (j = 0; j < 25; j++) {
        if (visited[j] == 0 && Table[i][j] >= 1) {          // if node hasn't been visited, and is an edge to the parent, call DFS on the node.
            DFS(j);                                         //recursive node
        }

    }



}
