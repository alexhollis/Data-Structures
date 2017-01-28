/********************************************
Name:   		Isaias Delgado, Alex Hollis
Course: 		CSE 3110.002
Assignment:     Program 4
Due Date:       March 27, 2015 at 11:55PM
********************************************/

#ifndef AVL_H
#define	AVL_H

#include <cstdlib>

using namespace std;

extern int rcalls;

class node {
    private:

        int sector;
        string name;
        node* left;
        node* right;
        int ht;

    public:

        node* newNode(int, string);              // creates a new node, returns pointer to the node.
        int height(node*);                       // calculates the height of node.
        node* insert(int, string, node*);        // adds a node to the tree.
        void inorder(node*);                     // displays the AVL Tree in-order.
        node* rotateRight(node*);                // right rotation
        node* rotateLeft(node*);                 // left rotation
        int balanceFactor(node*);                // determines height difference to determine if rotation needed.
        int max(int, int);                       // finds the maximum of two values
};

typedef node* nptr;                             // shorthand for a " node* " makes it easier to read

#endif	/* AVL_H */
