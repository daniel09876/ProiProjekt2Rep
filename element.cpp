#include <iostream>
#include "element.hpp"

using namespace std;

element::element(element& next_one, int index, int the_number) : next_one(&next_one), index(index), the_number(the_number) {}
    // Konstruktor do zrobienia pierwszego elementu
element::element(int the_number) : the_number(the_number), index(0), next_one(this) {}
    // Konstruktor nie ustalajacy nastepnego elementu (przydaje sie do kopiowania listy)
element::element(int the_number, int index) : the_number(the_number), index(index) {}
   
   // Wyswietla zawartosc elementu
void element::print(){
    cout<<"Element "<<index<<" containing number "<<the_number<<endl;
}


    // Do zrobienia elem_null
element::element() : the_number(42) {}
