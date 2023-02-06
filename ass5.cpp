/******************************************************
** Program: linked_list.cpp
** Author: Dachan Yu
** Date: 06/05/2021
** Description: creates a linked list from user inputs,
* sorts it, and check for prime numbers
** Input: integers
** Output: sorted list
******************************************************/

#include "ass5_func.h"

using namespace std;

int main() {
    bool n = true;
    Linked_List list;
    do {
        fist_value(list);
        ask_to_store(list);
        cout << endl << endl;
        list.print();
        cout << endl;
        ask_sort(list);

        cout << "prime number(s) in list: " << list.find_prime() << endl;
        list.print();
        cout << endl << endl;

        if (exit() == true) {
            break;
        }

        list.clear();
    } while (n == true);

    return 0;
}