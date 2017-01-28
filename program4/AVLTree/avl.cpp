/********************************************
Name: Isaias Delgado, Alex Hollis
Course: CSE 3110.002
Assignment: Program 4
Due Date:   March 27, 2015 at 11:55PM
********************************************/

#include <cstdlib>
#include <iostream>

#include "avl.h"

using namespace std;

int rcalls = 0;         // Global Variable for the recursive calls needed in main

// creates the default values for the tree
nptr node::newNode(int sector, string name) {
    nptr N = new node;
    N->sector = sector;
    N->name = name;
    N->ht = 1;
    N->left = NULL;
    N->right = NULL;

    return N;
}

// finds the maximum between two values
int node::max(int x, int y) {
    if (x > y) return x;
    else return y;
}

// gets the height of the desired node
int node::height(nptr N) {
    if (N == NULL)
        return 0;
    else return N->ht;
}

// rotates the value to the left
nptr node::rotateLeft(nptr N) {
    nptr N1, N2;
    N1 = N->right;
    N2 = N1->left;
    N1->left = N;
    N->right = N2;
    N->ht = max(height(N->left), height(N->right)) + 1;
    N1->ht = max(height(N1->left), height(N1->right)) + 1;

    return N1; //new root
}

// rotates the value to the right
nptr node::rotateRight(nptr N) {
    nptr T1 = N->left;
    nptr T2 = T1->right;
    T1->right = N;
    N->left = T2;
    N->ht = max(height(N->left), height(N->right)) + 1;
    T1->ht = max(height(T1->left), height(T1->right)) + 1;

    return T1; //new root
}

// balances the tree 
int node::balanceFactor(nptr N) {
    if (N == NULL)
        return 0;
    else return height(N->left) - height(N->right);
}

// inserts the desired value & name into the tree
nptr node::insert(int sector, string name, nptr N) {
    // setup as BST Tree first
    if (N == NULL)
        return (newNode(sector, name));

    if (sector < N->sector)
    {
        rcalls++;       //recursive call
        N->left = insert(sector, name, N->left);
    }
    else
    {
        rcalls++;
        N->right = insert(sector, name, N->right);
    }

    // height
    N->ht = max(height(N->left), height(N->right)) + 1;

    // balance
    int balance = balanceFactor(N);

    // Left then Left
    if (balance > 1 && sector < N->left->sector)
        return rotateRight(N);

    // Right then Right
    if (balance < -1 && sector > N->right->sector)
        return rotateLeft(N);

    // Left then Right
    if (balance > 1 && sector > N->left->sector) {
        N->left = rotateLeft(N->left);
        return rotateRight(N);
    }

    // Right then Left
    if (balance < -1 && sector < N->right->sector) {
        N->right = rotateRight(N->right);
        return rotateLeft(N);
    }

    // default
    return N;
}

// prints out the tree in order
void node::inorder(nptr N) {
    if(N == NULL)
        return;
    else {
        inorder(N->left);       // print out the left first
        cout << N->sector << " " << N->name << endl;    // data output
        inorder(N->right);      // then print the right side of the tree.
    }
}

//--------------------------------------- [ main function]----------------------------------------------------//

int main() {
    nptr root = NULL;
    string name_buffer;
    int sector_buffer;
    bool keep_running = true;
    int avg_calls = 0;
    int nodes = 0;
    
    while(keep_running)     // continues to run as long as "keep_running" is true
    {
        if(cin >> name_buffer >> sector_buffer)     //holds true as long as there is input (!= EOF)
        {
          nodes++;          //keeping track of number of nodes in tree for average calls.
          root = root->insert(sector_buffer, name_buffer, root);   //push new node on tree.
        }
        else keep_running = false;      //input is done, stop inserting.
    }
    
    avg_calls = (rcalls / nodes);       // calculate average number of recursive calls
    
    cout << "Average Recursive Calls: " << avg_calls << endl;   //print out average calls    
    root->inorder(root);    // display the AVL Tree.

    return 0;
}
