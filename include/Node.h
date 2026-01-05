//Evelyn Nguyen, CS302, prog1, 10/8/25
//Node header file

#include "FilmFest.h"

//node for workshop (LLL)
namespace workshop
{
    //Node for Workshops
    class Node : public Workshop
    {
        public:
            Node(const Workshop & source);

            void set_next(Node *& next);
            Node*& get_next();

        private:
            Node * next;
    };
}

//node for screenings (CLL)
namespace screening
{
	class Node: public Screening
	{
		public:
			Node(const Screening & source);
			void set_next(Node *& next);
			Node*& get_next();

		private:
			Node * next;
	};
}
