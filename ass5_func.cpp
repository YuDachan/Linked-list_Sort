#include "ass5_func.h"

using namespace std;

bool is_digit(string str) {
    int count = 0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '-' && count == 0) {
            count++;
        }
        else if (isdigit(str[i]) == false) {
            return false;
        }
    }

    return true;
}

bool exit() {
    string str;
    bool n = true;

    while (n == true) {
        cout << "[1]new list [2]exit program" << endl;
        getline(cin, str);
        if (str == "1") {
            cout << endl << endl;
            return false;
        }
        else if (str == "2") {
            return true;
        }

        cout << "poor input" << endl << endl;
    }
}

void other(Linked_List& list, int value) {
    string str;
    int num;
    bool n = true;

    do {
        cout << "after which node would you like to store the integer" << endl;
        getline(cin, str);
        if (is_digit(str) == true) {
            num = stoi(str);
            if (num <= list.give_length()) {
                cout << "the size of your link list is: " << list.insert(value, num) << endl << endl;
                break;
            }
        }
        cout << "poor input" << endl << endl;
    } while (n == true);
}

void storing_mech(Linked_List& list, int value) {
    string str;
    bool n = true;

    do {
        cout << "where would you like to store the node" << endl;
        cout << "[1]front [2]back [3]other" << endl;
        getline(cin, str);
        if (str == "1") {
            cout << "the size of your linked list is: " << list.push_front(value) << endl << endl;
            break;
        }
        else if (str == "2") {
            cout << "the size of your linked list is: " << list.push_back(value) << endl << endl;
            break;
        }
        else if (str == "3") {
            other(list, value);
            break;
        }
        cout << "poor input" << endl;
    } while (n == true);
}

void input(Linked_List& list) {
    int value;
    string inp;
    bool n = true;

    do {
        cout << "enter an integer to store" << endl;
        getline(cin, inp);
        if (is_digit(inp)) {
            value = stoi(inp);
            storing_mech(list, value);
            cout << endl << endl;
            break;
        }
        cout << "poor input, please try again" << endl << endl;
    } while (n == true);

}

void ask_to_store(Linked_List& list) {
    string inp;
    bool n = true;

    do {
        cout << "would you like to store another value?" << endl;
        cout << "[1]yes [2]no" << endl;
        getline(cin, inp);
        if (inp == "1") {
            cout << endl << endl;
            input(list);
        }
        else if (inp == "2") {
            cout << endl << endl;
            break;
        }
        else {
            cout << "poor input" << endl << endl;
        }
    } while (n == true);
}

void fist_value(Linked_List& list) {
    int value;
    string inp;
    bool n = true;

    do {
        cout << "enter an integer to store" << endl;
        getline(cin, inp);
        if (is_digit(inp)) {
            value = stoi(inp);
            list.first_value(value);
            cout << endl << endl;
            break;
        }
        cout << "poor input, please try again" << endl << endl;
    } while (n == true);
}

void ask_sort(Linked_List& list) {
    string str;
    bool n = true;

    do {
        cout << "how would you like to sort the list?" << endl;
        cout << "[1]ascending order [2]decending order [3]quit" << endl;
        getline(cin, str);
        cout << endl;
        if (str == "1") {
            list.sort_acending();
            list.print();
            cout << endl << endl;
        }
        else if (str == "2") {
            list.sort_descending();
            list.print();
            cout << endl << endl;
        }
        else if (str == "3") {
            break;
        }
        else {
            cout << "poor input" << endl;
        }
    } while (n == true);
}