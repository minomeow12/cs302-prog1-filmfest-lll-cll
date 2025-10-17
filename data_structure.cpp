// Evelyn Nguyen, CS302, prog1, 10/8/25
// Data structure.cpp file

#include "List.h"
#include <iostream>
using namespace std;

//--- WorkshopLLL ---

WorkshopLLL::WorkshopLLL() : head(nullptr) {}

WorkshopLLL::WorkshopLLL(const WorkshopLLL & source) : head(nullptr)
{
    copy(head, source.head);
}

WorkshopLLL::~WorkshopLLL()
{
    remove_all();
}

// --- Wrappers ---
bool WorkshopLLL::insert(const Workshop & to_add)
{
    return insert(head, *(new workshop::Node(to_add)));
}

bool WorkshopLLL::remove(const char * to_find)
{
    return remove(head, to_find);
}

int WorkshopLLL::remove_all()
{
    return remove_all(head);
}

int WorkshopLLL::display()
{
    cout << "Displaying all Workshops:\n";
    return display(head);
}

// --- Helpers ---
int WorkshopLLL::copy(workshop::Node *& dest, workshop::Node * src)
{
    if (!src) return 0;
    dest = new workshop::Node(*src);
    return 1 + copy(dest->get_next(), src->get_next());
}

bool WorkshopLLL::insert(workshop::Node *& head, workshop::Node & to_add)
{
    if (!head)
    {
        head = &to_add;
        return true;
    }
    return insert(head->get_next(), to_add);
}

int WorkshopLLL::display(workshop::Node * head)
{
    if (!head) return 0;
    head->display();
    cout << "---------------------\n";
    return 1 + display(head->get_next());
}

bool WorkshopLLL::remove(workshop::Node *& head, const char * to_find)
{
    if (!head) return false;
    if (head->compare(to_find) == 0)
    {
        workshop::Node * temp = head;
        head = head->get_next();
        delete temp;
        return true;
    }
    return remove(head->get_next(), to_find);
}

int WorkshopLLL::remove_all(workshop::Node *& head)
{
    if (!head) return 0;
    workshop::Node * temp = head;
    head = head->get_next();
    delete temp;
    return 1 + remove_all(head);
}

int WorkshopLLL::count(workshop::Node * head) const
{
    if (!head) return 0;
    return 1 + count(head->get_next());
}

bool WorkshopLLL::find(workshop::Node * head, const string & to_find) const
{
    if (!head) return false;
    if (head->match(to_find))
        return true;
    return find(head->get_next(), to_find);
}

Workshop* WorkshopLLL::find(const string & name) const
{
    workshop::Node * current = head;
    while (current) {
        if (current->compare(name.c_str()) == 0)
            return current; 
        current = current->get_next();
    }
    return nullptr; //if not found, return null
}

//--- ScreeningCLL ---
ScreeningCLL::ScreeningCLL() : rear(nullptr) {}

ScreeningCLL::ScreeningCLL(const ScreeningCLL & source) : rear(nullptr)
{
    if (source.rear)
        copy(rear, source.rear->get_next(), source.rear);
}

ScreeningCLL::~ScreeningCLL()
{
    remove_all();
}

//--- Wrappers ---
bool ScreeningCLL::insert(const Screening & to_add)
{
    if (!rear)
    {
        rear = new screening::Node(to_add);
        rear->set_next(rear);
        return true;
    }
    return insert_recursive(rear, rear->get_next(), to_add);
}

bool ScreeningCLL::remove(const char * to_find)
{
    if (!rear) return false;
    return remove_recursive(rear, rear->get_next(), to_find);
}

int ScreeningCLL::remove_all()
{
    if (!rear) return 0;
    return remove_all_recursive(rear, rear->get_next());
}

int ScreeningCLL::display()
{
    if (!rear)
    {
        cout << "No screenings to display.\n";
        return 0;
    }
    cout << "Displaying all Screenings:\n";
    return display_recursive(rear->get_next(), rear->get_next());
}

//Helpers ---
int ScreeningCLL::copy(screening::Node *& dest, screening::Node * current, screening::Node * stop)
{
    screening::Node * new_node = new screening::Node(*current);
    dest = new_node;

    if (current->get_next() == stop)
    {
        dest->set_next(dest);  
        return 1;
    }
    screening::Node * next_dest = new_node;
    int count = 1 + copy(next_dest->get_next(), current->get_next(), stop);
    dest->set_next(next_dest->get_next());
    return count;
}

bool ScreeningCLL::insert_recursive(screening::Node *& rear, screening::Node * current, const Screening & to_add)
{
    if (current == rear)
    {
        screening::Node * new_node = new screening::Node(to_add);
        new_node->set_next(rear->get_next());
        rear->set_next(new_node);
        rear = new_node;
        return true;
    }
    return insert_recursive(rear, current->get_next(), to_add);
}

int ScreeningCLL::display_recursive(screening::Node * current, screening::Node * stop)
{
    current->display();
    cout << "-----------------------------\n";
    if (current->get_next() == stop)
        return 1;
    return 1 + display_recursive(current->get_next(), stop);
}

bool ScreeningCLL::remove_recursive(screening::Node *& rear, screening::Node * current, const char * to_find)
{
    if (current->compare(to_find) == 0)
    {
        //only one node in list
        if (current == rear && current->get_next() == rear)
        {
            delete rear;
            rear = nullptr;
            return true;
        }

        //link previous to next if multiple nodes
        if (current == rear)
            rear = find_previous(rear, current);
        screening::Node * prev = find_previous(rear, current);
        prev->set_next(current->get_next());
        delete current;
        return true;
    }

    // Check if the circlle is completed
    if (current->get_next() == rear->get_next())
        return false;
    return remove_recursive(rear, current->get_next(), to_find);
}

int ScreeningCLL::remove_all_recursive(screening::Node *& rear, screening::Node * current)
{
    if (current == rear)
    {
        delete rear;
        rear = nullptr;
        return 1;
    }

    screening::Node * next = current->get_next();
    delete current;
    return 1 + remove_all_recursive(rear, next);
}

bool ScreeningCLL::find_recursive(screening::Node * current, screening::Node * stop, const string & to_find) const
{
    if (current->match(to_find))
        return true;
    if (current->get_next() == stop)
        return false;
    return find_recursive(current->get_next(), stop, to_find);
}

screening::Node * ScreeningCLL::find_previous(screening::Node * rear, screening::Node * target)
{
    screening::Node * current = rear;
    while (current->get_next() != target)
        current = current->get_next();
    return current;
}
int ScreeningCLL::count_recursive(screening::Node * current, screening::Node * stop, int cnt) const
{
    if (current == stop && cnt > 0)
        return cnt;
    return count_recursive(current->get_next(), stop, cnt + 1);
}

Screening* ScreeningCLL::find(const string & name) const
{
    if (!rear) return nullptr;
    return find_by_name(rear->get_next(), rear->get_next(), name);
}

Screening* ScreeningCLL::find_by_name(screening::Node * current, screening::Node * stop, const string & name) const
{
    if (current->compare(name.c_str()) == 0)
        return current;
    if (current->get_next() == stop)
        return nullptr;
    return find_by_name(current->get_next(), stop, name);
}
