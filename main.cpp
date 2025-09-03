#include <iostream>
#include "LinkedList.hpp"

/*test*/

int main()
{
    LinkedList *lista = new LinkedList();
    Node *x = new Node();
    x -> setValue(5);
    lista -> add(x -> getValue(), 0);
    std::cout<<x->getValue()<<std::endl;
    std::cout<<lista->get(0);

    return 0;
}