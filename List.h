//Evelyn Nguyen, CS302, prog1, 10/8/25
//List header file

#include "Node.h"

class List
{
    public:
        List();
        List(const List & source);
        ~List();

        bool insert(const Workshop & to_add);
        bool remove(const char * to_find);
        int remove_all();
        int display();

    private:
        workshop::Node * head;
        workshop::Node * tail;

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

	private:
		screening::Node * rear;

		int copy(screening::Node *& dest, screening::Node * src);
		bool insert(screening::Node *& rear, const Screening & to_add);
		bool remove(screening::Node *& rear, const char * to_find);
		int remove_all(screening::Node *& rear);
		int display(screening:: Node * rear);

		int count(screening::Node * rear) const;
		bool find(screening::Node * rear, const string & to_find) const;
};
