#ifndef FUNCTION
#define FUNCTION
#include <iostream>
#include <string>
#include <cmath>
#include "link.h"

using namespace std;

/*********************************************************************
** Function: is_digit
** Description: check if string only contains digits and one dash
** Parameters:  string
** Pre-Conditions: none
** Post-Conditions: returns true if string is digit else false
*********************************************************************/
bool is_digit(string str);

/*********************************************************************
** Function: exit
** Description: ask user if they want tto exit program
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: returns true or false
*********************************************************************/
bool exit();

/*********************************************************************
** Function: other
** Description: the other option for how to input node into list
** Parameters: Linked_List, int
** Pre-Conditions: none
** Post-Conditions: an int is added into a node onto the list
*********************************************************************/
void other(Linked_List& list, int value);

/*********************************************************************
** Function: storing_mech
** Description: asks user how where to stor the node
** Parameters: link_list, int
** Pre-Conditions: none
** Post-Conditions: calue is stor in list
*********************************************************************/
void storing_mech(Linked_List& list, int value);

/*********************************************************************
** Function: input
** Description: ask for an integer to store
** Parameters: link_list, int
** Pre-Conditions: none
** Post-Conditions: an integer is taken from the user
*********************************************************************/
void input(Linked_List& list);

/*********************************************************************
** Function: ask_to_store
** Description: ask user if they want to store another integer
** Parameters: link_list
** Pre-Conditions: none
** Post-Conditions: integer is stored
*********************************************************************/
void ask_to_store(Linked_List& list);

/*********************************************************************
** Function: first_value
** Description: ask user for teh first integer
** Parameters: link_list
** Pre-Conditions: none
** Post-Conditions: first integer is stored
*********************************************************************/
void fist_value(Linked_List& list);

/*********************************************************************
** Function: ask_sort
** Description: ask user how to sort the list
** Parameters: Link_list
** Pre-Conditions: none
** Post-Conditions: list is sorted
*********************************************************************/
void ask_sort(Linked_List& list);

#endif // !FUNCTION
