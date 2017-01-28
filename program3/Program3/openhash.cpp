/***************
Name:   Alex Hollis, Isaias Delgado
Course: CSCE 3110.002
Assignment: Program 3
Due Date:   March 1, 2015 11:55PM
 ****************/

#include <cstdlib>
#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

/*
 * 
 */

//The hash function in this program works by choosing a seed number, which in this case I chose 64, for no particular reason, then a long value called hash is started at 1, and is multiplied by the seed each 
// cycle of the for loop, as it is increased by the ASCII value of the character at each position in the string given to the hash key function. The final key is the remainder of the hash value and the number of buckets. 

int hashKey(string input) {

    int seed = 64;

    unsigned long hash = 1;


    for (int i = 0; i < input.length(); i++) {

        hash = ((hash * seed) + int(input[i])); //multiply hash by seed, and add ASCII value of the input string character at position "I" to the hash value. Keep looping until end of string is reached.
    }


    return hash % 100;
}

int main() {


    vector< vector<string> > hashTable; //initialize hash table, 100 buckets, using vectors to chain strings.
    vector<string> buffer;
    hashTable.resize(100); //There shall be 100 buckets by the orders of Thanos


    string buff;
    int key;
    int collisions = 0;
    int size_sum = 0, avg_size;
    while (cin >> buff) {

        buffer.push_back(buff); //fill buffer vector with names
    }
    int placeholder = 0; //to be used to navigate the buffer vector
    while (placeholder < buffer.size()) {
        key = hashKey(buffer[placeholder]); //retrieve the hash key

        (hashTable[key]).push_back(buffer[placeholder]); //add element to proper bucket in the hash table

        if (hashTable[key].size() > 1) collisions++; //element added to bucket with one or more names already.

        placeholder++;
    }
    
    int S_Bucket = hashTable[0].size(), L_Bucket = hashTable[0].size(); // set default smallest and largest to first bucket.
    
    for(int j=0; j < 100; j++)
    {
        size_sum += hashTable[j].size();
        if(hashTable[j].size() > L_Bucket) L_Bucket = hashTable[j].size(); // make it largest bucket
        if(hashTable[j].size() < S_Bucket) S_Bucket = hashTable[j].size(); // make it smallest bucket
        
    }
    
    avg_size = size_sum / 100;      // calculating the table workload, want to be as close to "#_names / buckets" (~28 per bucket average in this case) to be efficient



    // printing out the table //

    cout << "Collisions: " << collisions << endl;
    cout << "Average Bucket Size: " << avg_size << endl;
    cout << "Smallest Bucket Size: " << S_Bucket << endl;
    cout << "Largest Bucket Size: " << L_Bucket << endl;
    
    for (int bucket = 0; bucket < 100; bucket++) {
        cout << bucket << ": ";

        if (!hashTable[bucket].empty()) //if bucket is not empty, print out the names.
        {
            for (int x = 0; x < hashTable[bucket].size(); x++) {
                cout << hashTable[bucket][x] << " ";

            }
            cout << endl;
        } else cout << "empty" << endl; //if it is empty, print out empty.

    }


    return 0;
}

