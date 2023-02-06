#include "link.h"

using namespace std;

Linked_List::Linked_List() {
    head = new Node;
    length = 0;
    num_prime = 0;
}

Node* Linked_List::give_head() {
    return head;
}

unsigned int Linked_List::give_length() {
    return length;
}

unsigned int Linked_List::give_prime() {
    return num_prime;
}

bool Linked_List::isprime(int num) {

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

void Linked_List::first_value(int num) {
    length = 1;
    head->data = num;
}

unsigned int Linked_List::push_front(int num) {
    Node* temp;
    temp = new Node;

    temp->data = num;
    temp->next = head;
    head = temp;

    length++;

    return length;
}

unsigned int Linked_List::push_back(int num) {
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

unsigned int Linked_List::insert(int val, unsigned index) {
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

void Linked_List::print() {
    Node* n = NULL;
    n = head;

    cout << "linked list stored numbers: ";

    while (n != NULL) {
        cout << n->data << " ";
        n = n->next;
    }
}

void Linked_List::clear() {
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

void Linked_List::FrontBackSplit(Node* source, Node** frontRef, Node** backRef)
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

Node* Linked_List::SortedMerge(Node* a, Node* b)
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

void Linked_List::MergeSort(Node** headRef)
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

void Linked_List::sort_acending() {

    MergeSort(&head);
}

void Linked_List::swapNodes(Node** head_ref, Node* currX, Node* currY, Node* prevY) {
    *head_ref = currY;

    prevY->next = currX;

    Node* temp = currY->next;
    currY->next = currX->next;
    currX->next = temp;
}

Node* Linked_List::SelectionSort(Node* hed) {
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

    hed->next = SelectionSort(hed->next);

    return hed;
}

void Linked_List::sort(Node** head_ref) {
    if ((*head_ref) == NULL)
        return;

    *head_ref = SelectionSort(*head_ref);
}

void Linked_List::sort_descending() {
    sort(&head);
}

int Linked_List::find_prime() {
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

Linked_List& Linked_List::operator= (Linked_List& list) {
    head = list.give_head();
    length = list.give_length();
    num_prime = list.give_prime();
}

Linked_List::~Linked_List() {
    Node* temp;
    Node* n;

    n = head;

    while (n != NULL) {
        temp = n->next;
        delete n;
        n = temp;
    }
}