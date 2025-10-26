// Evelyn Nguyen, CS302, prog1, 10/8/25
// Data structure.cpp file

#include "List.h"
#include <iostream>
using namespace std;

//WorkshopLLL  
WorkshopLLL::WorkshopLLL() : head(nullptr) {}

WorkshopLLL::WorkshopLLL(const WorkshopLLL & source) : head(nullptr)
{
    copy(head, source.head);
}

WorkshopLLL::~WorkshopLLL()
{
    remove_all();
}

//Wrappers  
bool WorkshopLLL::insert(const Workshop & to_add)
{
    return insert(head, to_add) ;
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
    if (!head)
    {
        cout << "No workshops to display.\n";
        return 0;
    }
    cout << "Displaying all Workshops:\n";
    return display(head);
}

bool WorkshopLLL::find(const string & name) const
{
    return find(head, name);
}

//Recursive Helpers  

// base case: src == nullptr | RECURSIVE: copy current node, recurse on next| STOP: end of source list
int WorkshopLLL::copy(workshop::Node *& dest, workshop::Node * src)
{
    if (!src) return 0;
    dest = new workshop::Node(*src);
    return 1 + copy(dest->get_next(), src->get_next());
}

//base case: head == nullptr | RECURSIVE: recurse on next | STOP: end of list
bool WorkshopLLL::insert(workshop::Node *& head, const Workshop & to_add)
{
    if (!head)
    {
        head = new workshop::Node(to_add);
        return true;
    }
    return insert(head->get_next(), to_add);
}

//base case: head == nullptr| RECURSIVE: display current, recurse on next | STOP: end of list
int WorkshopLLL::display(workshop::Node * head)
{
    if (!head) return 0;
    head->display();
    cout << "---------------------\n";
    return 1 + display(head->get_next());
}

//base: head == nullptr| RECURSIVE: if match delete, else recurse on next | STOP: match found or end of list
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

//base: head == nullptr → return 0 | RECURSIVE: delete current, recurse on next | STOP: all nodes deleted
int WorkshopLLL::remove_all(workshop::Node *& head)
{
    if (!head) return 0;
    workshop::Node * temp = head;
    head = head->get_next();
    delete temp;
    return 1 + remove_all(head);
}

//base: head == nullptr → return false | RECURSIVE: if match display and return true, else recurse on next | STOP: match found or end of list
bool WorkshopLLL::find(workshop::Node * head, const string & to_find) const
{
    if (!head) return false;
    if (head->compare(to_find.c_str()) == 0)
    {
        head->display();
        return true;
    }
    return find(head->get_next(), to_find);
}

//Function for customers-------------------

// Register attendee by workshop name
bool WorkshopLLL::registerAttendee(const string & name, const string & attendee)
{
    return register_recursive(head, name, attendee);
}

//base: current == nullptr | RECURSIVE: if match call node's register, else recurse on next | STOP: match found or end of list
bool WorkshopLLL::register_recursive(workshop::Node * current, const string & name, const string & attendee)
{
    if (!current) return false;
    if (current->compare(name.c_str()) == 0)
        return current->registerAttendee(attendee);
    return register_recursive(current->get_next(), name, attendee);
}

// Cancel registration
bool WorkshopLLL::cancelRegistration(const string & name, const string & attendee)
{
    return cancel_recursive(head, name, attendee);
}

//base: current == nullptr| RECURSIVE: if match call node's cancel, else recurse on next | STOP: match found or end of list
bool WorkshopLLL::cancel_recursive(workshop::Node * current, const string & name, const string & attendee)
{
    if (!current) return false;
    if (current->compare(name.c_str()) == 0)
        return current->cancelRegistration(attendee);
    return cancel_recursive(current->get_next(), name, attendee);
}

// Print certificate
bool WorkshopLLL::printCertificate(const string & name) const
{
    return certificate_recursive(head, name);
}

//base: current == nullptr | RECURSIVE: if match call node's printCertificate, else recurse on next | STOP: match found or end of list
bool WorkshopLLL::certificate_recursive(workshop::Node * current, const string & name) const
{
    if (!current) return false;
    if (current->compare(name.c_str()) == 0)
        return current->printCertificate();
    return certificate_recursive(current->get_next(), name);
}

// Check affordability
bool WorkshopLLL::isAffordable(const string & name, float balance) const
{
    return isAffordable_recursive(head, name, balance);
}

//base: current == nullptr | RECURSIVE: if match call node's isAffordable, else recurse on next | STOP: match found or end of list
bool WorkshopLLL::isAffordable_recursive(workshop::Node * current, const string & name, float balance) const
{
    if (!current) return false;
    if (current->compare(name.c_str()) == 0)
        return current->isAffordable(balance);
    return isAffordable_recursive(current->get_next(), name, balance);
}

// Get discounted price
float WorkshopLLL::getDiscountedPrice(const string & name, float discountRate) const
{
    return getDiscountedPrice_recursive(head, name, discountRate);
}

//base: current == nullptr | RECURSIVE: if match return node's discounted price, else recurse on next | STOP: match found or end of list
float WorkshopLLL::getDiscountedPrice_recursive(workshop::Node * current, const string & name, float discountRate) const
{
    if (!current) return 0.0f;
    if (current->compare(name.c_str()) == 0)
        return current->getDiscountedPrice(discountRate);
    return getDiscountedPrice_recursive(current->get_next(), name, discountRate);
}

// Purchase ticket
bool WorkshopLLL::purchaseTicket(const string & name, float & balance)
{
    return purchase_recursive(head, name, balance);
}

//base: current == nullptr  | RECURSIVE: if match call node's purchaseTicket, else recurse on next | STOP: match found or end of list
bool WorkshopLLL::purchase_recursive(workshop::Node * current, const string & name, float & balance)
{
    if (!current) return false;
    if (current->compare(name.c_str()) == 0)
        return current->purchaseTicket(balance);
    return purchase_recursive(current->get_next(), name, balance);
}

//ScreeningCLL Implementation 

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

// Wrappers 

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
    return remove_recursive(rear, rear, rear->get_next(), to_find);
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

bool ScreeningCLL::find(const string & name) const
{
    if (!rear) return false;
    return find_recursive(rear->get_next(), rear, name);
}

//  Recursive Helpers --------------------

//base: current == stop | RECURSIVE: copy current node, recurse on next | STOP: circled back to stop node
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

// BASE: current == rear → insert at end, update rear | RECURSIVE: recurse on next | STOP: reached rear (insert position)
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

// BASE: current->next == stop → return 1 | RECURSIVE: display current, recurse on next | STOP: circled back to stop node
int ScreeningCLL::display_recursive(screening::Node * current, screening::Node * stop)
{
    current->display();
    cout << "-----------------------------\n";
    if (current->get_next() == stop)
        return 1;
    return 1 + display_recursive(current->get_next(), stop);
}

// BASE: current == nullptr or match found → delete node | RECURSIVE: check match, recurse on next | STOP: match found or circled back to start
bool ScreeningCLL::remove_recursive(screening::Node *& rear, screening::Node * prev, screening::Node * current, const char * to_find)
{
    if (!current || !rear) return false;
    if (current->compare(to_find) == 0)
    {
        if (current == rear && current->get_next() == rear)
        {
            delete rear;
            rear = nullptr;
            return true;
        }
        if (current == rear)
            rear = prev;
        prev->set_next(current->get_next());
        delete current;
        return true;
    }
    if (current->get_next() == rear->get_next())
        return false;
    return remove_recursive(rear, current, current->get_next(), to_find);
}

// BASE: current == rear → delete last node, set rear to nullptr | RECURSIVE: delete current, recurse on next | STOP: all nodes deleted
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

// BASE: current == nullptr or current->next == stop → return false | RECURSIVE: if match display, else recurse on next | STOP: match found or circled back to stop
bool ScreeningCLL::find_recursive(screening::Node * current, screening::Node * stop, const string & to_find) const
{
    if (!current) return false;
    if (current->compare(to_find.c_str()) == 0)
    {
        current->display();
        return true;
    }
    if (current->get_next() == stop)
        return false;
    return find_recursive(current->get_next(), stop, to_find);
}

// Customer-Specific ---------------------

bool ScreeningCLL::rateFilm(const string & title, int rating)
{
    if (!rear) return false;
    return rate_recursive(rear->get_next(), rear->get_next(), title, rating);
}

// BASE: current == nullptr or current->next == stop → return false | RECURSIVE: if match call node's rateFilm, else recurse on next | STOP: match found or circled back to stop
bool ScreeningCLL::rate_recursive(screening::Node * current, screening::Node * stop, const string & title, int rating)
{
    if (!current) return false;
    if (current->compare(title.c_str()) == 0)
        return current->rateFilm(rating);
    if (current->get_next() == stop)
        return false;
    return rate_recursive(current->get_next(), stop, title, rating);
}

bool ScreeningCLL::purchaseTicket(const string & title, float & balance)
{
    if (!rear) return false;
    return purchase_recursive(rear->get_next(), rear->get_next(), title, balance);
}

// BASE: current == nullptr or current->next == stop → return false | RECURSIVE: if match call node's purchaseTicket, else recurse on next | STOP: match found or circled back to stop
bool ScreeningCLL::purchase_recursive(screening::Node * current, screening::Node * stop, const string & title, float & balance)
{
    if (!current) return false;
    if (current->compare(title.c_str()) == 0)
        return current->purchaseTicket(balance);
    if (current->get_next() == stop)
        return false;
    return purchase_recursive(current->get_next(), stop, title, balance);
}

// Check affordability
bool ScreeningCLL::isAffordable(const string & title, float balance) const
{
    if (!rear) return false;
    return isAffordable_recursive(rear->get_next(), rear->get_next(), title, balance);
}

// BASE: current == nullptr or current->next == stop → return false | RECURSIVE: if match call node's isAffordable, else recurse on next | STOP: match found or circled back to stop
bool ScreeningCLL::isAffordable_recursive(screening::Node * current, screening::Node * stop, const string & title, float balance) const
{
    if (!current) return false;
    if (current->compare(title.c_str()) == 0)
        return current->isAffordable(balance);
    if (current->get_next() == stop)
        return false;
    return isAffordable_recursive(current->get_next(), stop, title, balance);
}

// Get discounted price
float ScreeningCLL::getDiscountedPrice(const string & title, float discountRate) const
{
    if (!rear) return 0.0f;
    return getDiscountedPrice_recursive(rear->get_next(), rear->get_next(), title, discountRate);
}

// BASE: current == nullptr or current->next == stop → return 0.0f | RECURSIVE: if match return node's discounted price, else recurse on next | STOP: match found or circled back to stop
float ScreeningCLL::getDiscountedPrice_recursive(screening::Node * current, screening::Node * stop, const string & title, float discountRate) const
{
    if (!current) return 0.0f;
    if (current->compare(title.c_str()) == 0)
        return current->getDiscountedPrice(discountRate);
    if (current->get_next() == stop)
        return 0.0f;
    return getDiscountedPrice_recursive(current->get_next(), stop, title, discountRate);
}
