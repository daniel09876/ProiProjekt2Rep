#include <iostream>
#include "list_of_stuff.hpp"

using namespace std;

int main()
{
    
    // Jakies losowe przyklady dzialania metod. Pewnie wymagaja wyjasnienia,
    list_of_stuff lst(10);
    int agrs[] = {1, 1, 2, 1, 4, 6, 7, 8, 9};
    lst.add_more(9, agrs);
    lst.remove_all_repetitions();
    list_of_stuff lst2(8);
    int args2[] ={3, 6, 6, 50};
    lst2.add_more(4, args2);
    list_of_stuff lst3 = lst - lst2;
    list_of_stuff *lst4 = new list_of_stuff();
    *lst4 = lst2;
    *lst4 = lst3;
    cout<<"  lst2, element 3 number: "<<(lst2<3)->the_number<<endl;
    cout<<"  lst2, length: "<<(lst2.check_for_length())<<endl;
    cout<<"  are lst4==lst3 ? Answer: "<<(*lst4==lst3)<<endl;
    
    delete lst4;
    
    return 0;
}
