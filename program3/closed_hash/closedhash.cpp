/********************************************
Name:   		Isaias Delgado, Alex Hollis
Course: 		CSE 3110.002
Assignment:     Program 3
Due Date:       March 1, 2015 at 11:55PM
********************************************/
 
#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <fstream>
#include <cstdlib>
 
using namespace std;
 
// The hash function in this program works by choosing a seed 
// number, which in this case I chose 64, for no particular 
// reason, then a long value called hash is started at 1, and 
// is multiplied by the seed each cycle of the for loop, as 
// it is increased by the ASCII value of the character at 
// each position in the string given to the hash key function. 
// The final key is the remainder of the hash value and the number of buckets.
 
 
 
//Finds the hash function key for the table
int hashKey(string input)
{
	int seed = 64;
    nsigned long hash = 1;
 
    for (int i = 0; i < input.length(); i++)
	{
        hash = ((hash * seed) + int(input[i])); //multiply hash by seed, and add ASCII value of 
												//the input string character at position "I" to 
												//the hash value. Keep looping until end of string is reached.
    }
    return hash % 100;
}

//Second hash function incase the program runs into any collisions
int rehash(vector<string>& table)
{
    int npos;
 
    for(int i=0; i<100; i++)
    {
		if(table[i].empty())
        {
			npos = i;
            break;
        }
        if(i == 99 && !(table[i].empty()) ) //end of table has been reach, no empty spots left
			npos = 101;		//use this value in main to trash string.
    }
        return npos;
}
 
 ///// Main Function \\\\\\
 
int main()
{
        vector<string> table;
        table.resize(100); // 100 buckets
        int pos = 0; //start of array
        int collisions = 0;
        int key;
       
        string buff;
		
		//runs as long as there is input from the buffer
        while(cin >> buff)
        {
			key = hashKey(buff);
			//checks if the position is empty
            if(table[key].empty() )
                table[key] = buff;
            else
            {
                key = rehash(table);
                collisions++;
                if(key != 101)
                        table[key] = buff;
                else
				{
					collisions++;	//adds on to the collision count
					continue;       // throw out name, no room, table is full
                }
            }       
        }

        //prints out the collisions
        cout << "Collisions: " << collisions << endl;
       
        //prints out the array
        for (pos = 0; pos < 100; pos++)
        {               
                //checks if the positions is not empty in the array
               
			if(!table[pos].empty())
            {
				//prints out the content in that position
                cout << table[pos] << endl;
            }
            else cout << "empty" << endl;
        }       
        return 0;
}