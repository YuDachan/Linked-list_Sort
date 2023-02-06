#ifndef LINK
#define LINK
#include <iostream>
#include <string>
#include <cmath>
#include "node.h"

using namespace std;

class Linked_List {
private:
    Node* head;
    unsigned int length;
    unsigned int num_prime;
public:

    /*********************************************************************
    ** Function:  Linked_List
    ** Description: constructor
    ** Parameters: none
    ** Pre-Conditions: none
    ** Post-Conditions: initializes all variables
    *********************************************************************/
    Linked_List();

    /*********************************************************************
    ** Function:  give_head()
    ** Description: returns head
    ** Parameters: none
    ** Pre-Conditions: none
    ** Post-Conditions: returns head
    *********************************************************************/
    Node* give_head();

   /*********************************************************************
   ** Function: give_length
   ** Description: give head
   ** Parameters: none
   ** Pre-Conditions: none
   ** Post-Conditions: returns head
   *********************************************************************/
    unsigned int give_length();

   /*********************************************************************
   ** Function: give_prime()
   ** Description: gives prime numbers
   ** Parameters: none
   ** Pre-Conditions: none
   ** Post-Conditions: returns prime
   *********************************************************************/
    unsigned int give_prime();

   /*********************************************************************
   ** Function: isprime
   ** Description: determines if number is prime
   ** Parameters: int
   ** Pre-Conditions: none
   ** Post-Conditions: returns true or false
   *********************************************************************/
    bool isprime(int num);

   /*********************************************************************
   ** Function: first_value
   ** Description: inputs data into the head of the linked list
   ** Parameters: num
   ** Pre-Conditions: none
   ** Post-Conditions: a node is created
   *********************************************************************/
    void first_value(int num);

   /*********************************************************************
   ** Function: push_front
   ** Description: creates a node and makes it the new head
   ** Parameters: num
   ** Pre-Conditions: none
   ** Post-Conditions: a new head is in front of linked list
   *********************************************************************/
    unsigned int push_front(int num);

   /*********************************************************************
   ** Function: push_back
   ** Description: creates a node on the end of the list
   ** Parameters: num
   ** Pre-Conditions: none
   ** Post-Conditions: a node is created at end of list
   *********************************************************************/
    unsigned int push_back(int num);

   /*********************************************************************
   ** Function: insert 
   ** Description: creates a node and places node in the middle of nodes
   ** Parameters: int, unsigned 
   ** Pre-Conditions: none
   ** Post-Conditions: a node is placed inside the linked list
   *********************************************************************/
    unsigned int insert(int val, unsigned index);

  /*********************************************************************
   ** Function: print
   ** Description: displays linked list data
   ** Parameters: none
   ** Pre-Conditions: none
   ** Post-Conditions: all numbers in linked list are displayed
   *********************************************************************/
    void print();

   /*********************************************************************
   ** Function: clear()
   ** Description: destroys linked list and all nodes
   ** Parameters: none
   ** Pre-Conditions: none
   ** Post-Conditions: all memory is cleared
   *********************************************************************/
    void clear();

   /*********************************************************************
   ** Function: FrontBackSplit
   ** Description: splits the nodes into two
   ** Parameters: node*, node**, node**
   ** Pre-Conditions: none
   ** Post-Conditions: nodes are split
   *********************************************************************/
    void FrontBackSplit(Node* source, Node** frontRef, Node** backRef);

   /*********************************************************************
   ** Function: sortedmerge
   ** Description: once the linked list is sorted, the list is merged 
   together
   ** Parameters: Node*, Node*
   ** Pre-Conditions: none
   ** Post-Conditions: a new link list is formed
   *********************************************************************/
    Node* SortedMerge(Node* a, Node* b);

   /*********************************************************************
   ** Function: mergesort
   ** Description: recursive merge sort
   ** Parameters: Node**
   ** Pre-Conditions: none
   ** Post-Conditions: linked list is sorted in ascending order
   *********************************************************************/
    void MergeSort(Node** headRef);

   /*********************************************************************
   ** Function: sort_ascending
   ** Description: begins the merge sort process
   ** Parameters: none
   ** Pre-Conditions: none
   ** Post-Conditions: linked list is sorted
   *********************************************************************/
    void sort_acending();

   /*********************************************************************
   ** Function: swapNodes
   ** Description: changes nodes
   ** Parameters: node**, node*, node*, node*
   ** Pre-Conditions: none
   ** Post-Conditions: nodes are swapped
   *********************************************************************/
    void swapNodes(Node** head_ref, Node* currX, Node* currY, Node* prevY);

   /*********************************************************************
   ** Function: SelectionSort
   ** Description: selection sort recursive
   ** Parameters: node*
   ** Pre-Conditions: none
   ** Post-Conditions: linked list is sorted in descending order
   *********************************************************************/
    Node* SelectionSort(Node* hed);

   /*********************************************************************
   ** Function: sort
   ** Description: checks if linked list is empty
   ** Parameters: node**
   ** Pre-Conditions: none
   ** Post-Conditions: if list has items, begins sorting
   *********************************************************************/
    void sort(Node** head_ref);

   /*********************************************************************
   ** Function: sorted_descending
   ** Description: begins selection sort process
   ** Parameters: none
   ** Pre-Conditions: none
   ** Post-Conditions: link list is sorted in descending order
   *********************************************************************/
    void sort_descending();

   /*********************************************************************
   ** Function: find_prime
   ** Description: determines how many prime numbers
   ** Parameters: none
   ** Pre-Conditions: none
   ** Post-Conditions: number of prime numbers are saved
   *********************************************************************/
    int find_prime();

   /*********************************************************************
   ** Function: operator=
   ** Description: assignment operator
   ** Parameters: Linked_List
   ** Pre-Conditions: none
   ** Post-Conditions: all data is copied
   *********************************************************************/
    Linked_List& operator= (Linked_List& list);

   /*********************************************************************
   ** Function: ~Linked_List
   ** Description: frees all memory
   ** Parameters: none
   ** Pre-Conditions: none 
   ** Post-Conditions: memory is freed
   *********************************************************************/
    ~Linked_List();
};

#endif // !LINK
