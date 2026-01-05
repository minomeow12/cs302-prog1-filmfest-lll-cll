// Evelyn Nguyen, CS302, prog1, 10/8/25
// List header file

#include "Node.h"

//  WorkshopLLL 

class WorkshopLLL 
{
public:
    WorkshopLLL();
    WorkshopLLL(const WorkshopLLL & source);
    ~WorkshopLLL();

    // Public wrappers
    bool insert(const Workshop & to_add);
    bool remove(const char * to_find);
    int remove_all();
    int display();
    bool find(const string & name) const;

    // Customer functions
    bool registerAttendee(const string & name, const string & attendee);
    bool cancelRegistration(const string & name, const string & attendee);	
    bool printCertificate(const string & name) const;
    bool isAffordable(const string & name, float balance) const;
    float getDiscountedPrice(const string & name, float discountRate) const;
    bool purchaseTicket(const string & name, float & balance);

private:
    workshop::Node * head;

    // Recursive helpers
    int copy(workshop::Node *& dest, workshop::Node * src);
    bool insert(workshop::Node *& head, const Workshop & to_add);
    bool remove(workshop::Node *& head, const char * to_find);
    int remove_all(workshop::Node *& head);
    int display(workshop::Node * head);

    int count(workshop::Node * head) const;
    bool find(workshop::Node * head, const string & to_find) const;
    bool register_recursive(workshop::Node * current, const string & name, const string & attendee);
    bool cancel_recursive(workshop::Node * current, const string & name, const string & attendee);
    bool certificate_recursive(workshop::Node * current, const string & name) const;
    bool isAffordable_recursive(workshop::Node * current, const string & name, float balance) const;
    float getDiscountedPrice_recursive(workshop::Node * current, const string & name, float discountRate) const;
    bool purchase_recursive(workshop::Node * current, const string & name, float & balance);

};

// --- ScreeningCLL ---

class ScreeningCLL
{
public:
    ScreeningCLL();
    ScreeningCLL(const ScreeningCLL & source);
    ~ScreeningCLL();

    // Public wrappers
    bool insert(const Screening & to_add);
    bool remove(const char * to_find);
    int remove_all();
    int display();
    bool find(const string & name) const;
    bool rateFilm(const string & title, int rating);
    bool purchaseTicket(const string & title, float & balance);
    bool isAffordable(const string & title, float balance) const;
    float getDiscountedPrice(const string & title, float discountRate) const;

private:
    screening::Node * rear;

    // Recursive helpers
    int copy(screening::Node *& dest, screening::Node * current, screening::Node * stop);
    bool insert_recursive(screening::Node *& rear, screening::Node * current, const Screening & to_add);
    int display_recursive(screening::Node * current, screening::Node * stop);
    bool remove_recursive(screening::Node *& rear, screening::Node * prev, screening::Node * current, const char * to_find);
    int remove_all_recursive(screening::Node *& rear, screening::Node * current);
    bool find_recursive(screening::Node * current, screening::Node * stop, const string & to_find) const;
    int count_recursive(screening::Node * current, screening::Node * stop, int cnt) const;
    bool rate_recursive(screening::Node * current, screening::Node * stop, const string & title, int rating);
    bool purchase_recursive(screening::Node * current, screening::Node * stop, const string & title, float & balance);
   bool isAffordable_recursive(screening::Node * current, screening::Node * stop, const string & title, float balance) const;
    float getDiscountedPrice_recursive(screening::Node * current, screening::Node * stop, const string & title, float discountRate) const;

};

