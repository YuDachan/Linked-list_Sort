#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node& operator= (Node*& node) {
        data = node->data;
        next = node->next;
    }

};

class Linked_List {
private:
    Node* head;
    unsigned int length;
    unsigned int num_prime;
public:

    Linked_List() {
        head = new Node;
        length = 0;
        num_prime = 0;
    }

    Node* give_head() {
        return head;
    }

    unsigned int give_length() {
        return length;
    }

    unsigned int give_prime() {
        return num_prime;
    }

    bool isprime(int num) {

        for (int i = 2; i <= (num / 2); i++) {
            if (num % i == 0) {
                return false;
            }
        }

        if (num <= 0 || num == 1) {
            return false;
        }
        
        return true;
    }

    void first_value(int num) {
        length = 1;
        head->data = num;
    }

    unsigned int push_front(int num) {
        Node* temp;
        temp = new Node;

        temp->data = num;
        temp->next = head;
        head = temp;

        length++;

        return length;
    }

    unsigned int push_back(int num) {
        Node* n;
        n = head;
        length++;

        while (n != NULL) {

            if (n->next == NULL) {
                n->next = new Node;
                n = n->next;
                n->data = num;
                n->next = NULL;
            }

            n = n->next;
        }
        return length;
    }

    unsigned int insert(int val, unsigned index) {
        Node* n;
        Node* temp;
        n = head;
        length++;

        for (int i = 1; i < index; i++) {
            n = n->next;
        }
        temp = n->next;
        n->next = new Node;
        n = n->next;
        n->data = val;
        n->next = temp;

        return length;
    }

    void print() {
        Node* n = NULL;
        n = head;

        cout << "linked list stored numbers: ";

        while (n != NULL) {
            cout << n->data << " ";
            n = n->next;
        }
    }

    void clear() {
        Node* temp;
        Node* n;

        n = head;

        while (n != NULL) {
            temp = n->next;
            delete n;
            n = temp;
        }

        length = 0;
        num_prime = 0;

        head = new Node;
    }

    void FrontBackSplit(Node* source, Node** frontRef, Node** backRef)
    {
        Node* fast;
        Node* slow;
        slow = source;
        fast = source->next;

        while (fast != NULL) {
            fast = fast->next;
            if (fast != NULL) {
                slow = slow->next;
                fast = fast->next;
            }
        }


        *frontRef = source;
        *backRef = slow->next;
        slow->next = NULL;
    }

    Node* SortedMerge(Node* a, Node* b)
    {
        Node* result = NULL;

        if (a == NULL)
            return (b);
        else if (b == NULL)
            return (a);

        if (a->data <= b->data) {
            result = a;
            result->next = SortedMerge(a->next, b);
        }
        else {
            result = b;
            result->next = SortedMerge(a, b->next);
        }
        return (result);
    }

    void MergeSort(Node** headRef)
    {
        head = *headRef;
        Node* a;
        Node* b;

        if ((head == NULL) || (head->next == NULL)) {
            return;
        }

        FrontBackSplit(head, &a, &b);

  
        MergeSort(&a);
        MergeSort(&b);

    
        *headRef = SortedMerge(a, b);
    }

    void sort_acending() {

        MergeSort(&head);
    }

    void swapNodes(Node** head_ref, Node* currX, Node* currY, Node* prevY){
        *head_ref = currY;

        prevY->next = currX;

        Node* temp = currY->next;
        currY->next = currX->next;
        currX->next = temp;
    }

    Node* recurSelectionSort(Node* hed){
        if (hed->next == NULL)
            return hed;

        Node* min = hed;
        Node* beforeMin = NULL;
        Node* ptr;
        
        for (ptr = hed; ptr->next != NULL; ptr = ptr->next) {

            if (ptr->next->data > min->data) {
                min = ptr->next;
                beforeMin = ptr;
            }
        }
        
        if (min != hed)
            swapNodes(&hed, hed, min, beforeMin);

        hed->next = recurSelectionSort(hed->next);

        return hed;
    }

    void sort(Node** head_ref) {
        if ((*head_ref) == NULL)
            return;

        *head_ref = recurSelectionSort(*head_ref);
    }

    void sort_descending() {
        sort(&head);
    }

    int find_prime() {
        Node* n;
        n = head;
        while (n != NULL) {
            if (isprime(n->data) == true) {
                num_prime++;
            }
            n = n->next;
        }

        return num_prime;
    }

    Linked_List& operator= (Linked_List& list) {
        head = list.give_head();
        length = list.give_length();
        num_prime = list.give_prime();
    }

    ~Linked_List() {
        Node* temp;
        Node* n;

        n = head;

        while (n != NULL) {
            temp = n->next;
            delete n;
            n = temp;
        }
    }
};

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

int main(){
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