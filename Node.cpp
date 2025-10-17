//Evelyn Nguyen, CS302, prog1, 10/8/25
//Node cpp file

#include "Node.h"
using namespace std;

//Workshop Node 
namespace workshop
{
    Node::Node(const Workshop & source) : Workshop(source), next(nullptr) {}

    void Node::set_next(Node *& next_node) 
    {
        next = next_node;
    }

    Node*& Node::get_next()
    {
        return next;
    }
}

// Screening Node 
namespace screening
{
    Node::Node(const Screening & source): Screening(source), next(nullptr) {}

    void Node::set_next(Node *& next_node)
    {
        next = next_node;
    }

    Node*& Node::get_next()
    {
        return next;
    }
}

