//Evelyn Nguyen, CS302, prog1, 10/8/25
//List header file

#include "Node.h"

class WorkshopLLL 
{
    public:
        WorkshopLLL();
        WorkshopLLL(const WorkshopLLL & source);
        ~WorkshopLLL();

        bool insert(const Workshop & to_add);
        bool remove(const char * to_find);
        int remove_all();
        int display();
	Workshop* find(const string & name) const;

    private:
        workshop::Node * head;

        int copy(workshop::Node *& dest, workshop::Node * src);
        bool insert(workshop::Node *& head, workshop::Node & to_add);
        bool remove(workshop::Node *& head, const char * to_find);
        int remove_all(workshop::Node *& head);
        int display(workshop::Node * head);

        int count(workshop::Node * head) const;
        bool find(workshop::Node * head, const string & to_find) const;
        
};

class ScreeningCLL
{
    public:
        ScreeningCLL();
        ScreeningCLL(const ScreeningCLL & source);
        ~ScreeningCLL();
        
        bool insert(const Screening & to_add);
        bool remove(const char * to_find);
        int remove_all();
        int display();
        Screening* find(const string & name) const;
        
    private:
        screening::Node * rear;
        
        int copy(screening::Node *& dest, screening::Node * current, screening::Node * stop);
        bool insert_recursive(screening::Node *& rear, screening::Node * current, const Screening & to_add);
        int display_recursive(screening::Node * current, screening::Node * stop);
        bool remove_recursive(screening::Node *& rear, screening::Node * current, const char * to_find);
        int remove_all_recursive(screening::Node *& rear, screening::Node * current);
        bool find_recursive(screening::Node * current, screening::Node * stop, const string & to_find) const;
        Screening* find_by_name(screening::Node * current, screening::Node * stop, const string & name) const;
        int count_recursive(screening::Node * current, screening::Node * stop, int cnt) const;
        screening::Node * find_previous(screening::Node * rear, screening::Node * target);
};
