/***************
Name:   Alex Hollis
Course: CSCE 3110.002
Assignment: Program 1
Due Date:   January 30, 2015 11:55PM
 ****************/

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

/*
 * 
 */

void input(int **pointer) {

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> pointer[i][j];
        }
    }

}

void output(int **pointer) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << setw(3) <<  pointer[i][j];
            cout << ' ';
        }
        cout << endl;
    }


}

int main(int argc, char** argv) {

    int **array;

    array = new int* [10];
    
    for(int i=0; i<10; i++)
    {
        array[i] = new int[10];
    }
    
    input(array);
    output(array);





    return 0;
}

