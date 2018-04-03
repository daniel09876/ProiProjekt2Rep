#include <iostream>
#include "list_of_stuff.hpp"

using namespace std;

// Sztuczny element bez zadnej listy. Zrobiony, aby elementy wskazujace na nic mialy na co wskazywac.
element *elem_null = new element();

    // Funkcja Tworzaca nowy element.
element* list_of_stuff::creating_el(element& next_one, int index, int the_number) {
    return new element(next_one, index, the_number);
}

    // Wszystkie indeksy poczynajac od danego zwiekszone o "x", domyslnie (0, 1)
void list_of_stuff::increase_index(int starting, int x) { 
    element *current_el = first_one;
    do {
        if (current_el->index >= starting) current_el->index += x;
        current_el = current_el->next_one;
    } while (current_el != first_one);
}
    
    // Znajdzie najblizszy element wskazujacy na element z dana liczba lub dojdzie do konca listy
element* list_of_stuff::look_for_el_pointing_value(int value, element* starting) {
    element *current_el = starting;
    while (current_el->next_one->the_number != value) {
        current_el = current_el->next_one;
        if (current_el == first_one) {return elem_null;}
    }
    return current_el;
}
    
    // Znajdzie element wskazujacy na element z wartoscia w przedziale (zaklada value1 <= value2) lub dojdzie do konca listy
element* list_of_stuff::look_for_el_pointing_range(int value1, int value2, element* starting) {
    element *current_el = starting;
    while (current_el->next_one->the_number < value1 || current_el->next_one->the_number > value2) {
        current_el = current_el->next_one;
        if (current_el == first_one) {return elem_null;}
    }
    return current_el;
}
    
    // Usuwa wszystkie elementy listy
void list_of_stuff::remove_everything() {
    if (first_one == elem_null) return;
    find_last_el()->next_one = elem_null;
    element *current_el1 = first_one;
    element *current_el2;
    while (current_el1->next_one != elem_null) {
        current_el2 = current_el1->next_one;
        delete current_el1;
        current_el1 = current_el2;
    }
    delete current_el1;
    
    first_one = elem_null;
}

    
//------------------------------------------Publiczne:
    
    
    // Tworzenie pustej listy
list_of_stuff::list_of_stuff() : first_one(elem_null) {}
    
    // Tworzenie listy z jedna pojedyncza wartoscia
list_of_stuff::list_of_stuff(int first_value){
    first_one = new element(first_value);
}
    
    // Do kopiowania listy
list_of_stuff::list_of_stuff(list_of_stuff& copied_lst){
    element *current_el1 = copied_lst.first_one;
    // Tylko tymczasowo
    element *current_el2 = elem_null;
    element *current_el3;
    int i = 0;
    // Petla obserwuje zmienna "current_el1", ktora przesuwa sie po pierwotnej liscie i petla kopiuje kazdy element z osobna do "current_el3".
    // "current_el2" przechowuje poprzedni element, aby w odpowiednim momencie przypisac mu na co faktycznie wskazuje
    do {
        current_el3 = new element(current_el1->the_number, i);
        current_el2->next_one = current_el3;
        current_el2 = current_el3;
        current_el1 = current_el1->next_one;
        i++;
    } while (current_el1 != copied_lst.first_one);
    // Jedynie "elem_null" zna polozenie w pamieci pierwszego elementu listy
    first_one = elem_null->next_one;
    // Aby ostatni elemnet wskazywal na pierwszy
    current_el2->next_one = first_one;
}
    
    // Destruktor. Usuwa najpierw wszystkie elementy, a dopiero potem jest usunieta lista sama w sobie.
list_of_stuff::~list_of_stuff() {
    if (first_one == elem_null) return;
    remove_everything();
}

    // Znajduje ostatni element
element* list_of_stuff::find_last_el() {
    element *current_el = first_one;
    while (current_el->next_one != first_one) {current_el = current_el->next_one;}
    return current_el;
}
    
    // Znajdzie element z danym indeksem lub zwroci elem_null.
element* list_of_stuff::find_el_wth_index(int idx) {
    element *current_el = first_one;
    while (current_el->index != idx) {
        current_el = current_el->next_one;
        if (current_el->index == 0) return elem_null;
    }
    return current_el;
}
    
    // Znajdzie najblizszy element z dana wartoscia lub zwroci "elem_null"
element* list_of_stuff::look_for_value(int value, element* starting) {
    element *current_el = starting;
    while (current_el->the_number != value) {
        current_el = current_el->next_one;
        if (current_el == first_one) {return elem_null;}
    }
    return current_el;
}
    
    // Znajduje pierszy element o danej wartosci lub zwroci "elem_null"
element* list_of_stuff::look_for_value(int value) {
    element *current_el = first_one;
    while (current_el->the_number != value) {
        current_el = current_el->next_one;
        if (current_el == first_one) {return elem_null;}
    }
    return current_el;
}
    
    // Znajduje element przed podanym jako parametr
element* list_of_stuff::find_el_before(element *before_this) {
    element *current_el = first_one;
    while (current_el->next_one != before_this) {current_el = current_el->next_one;}
    return current_el;
    
}
    
    
    // Dodaje element na indeks
void list_of_stuff::add(int what, int where) {
    if (where + 1 > check_for_length()) {
        add_at_the_end(what);
        return;
    }
    element *el_before;
    if (where == 0) el_before = find_last_el();
    else el_before = find_el_wth_index(where-1);
    increase_index(where);
    element *new_el = creating_el(*el_before->next_one, where, what);
    el_before->next_one = new_el;
    if (where == 0) first_one = new_el;
}
    
    // Dodaje na poczatek listy "size" nowych elementow, jest to rozmiar tablicy nowych wartosci podanej jako parametr
void list_of_stuff::add_more(int size, int what[]) {
    element *last_el = find_last_el();
    increase_index(0, size);
    element *current_el = first_one;
    for (int i = 0; i<size; i++) {
        current_el = creating_el(*current_el, size-i-1, what[size-i-1]);
    }
    last_el->next_one = current_el;
    first_one = current_el;
}
    
    // Dodaje pojedynczy element zaraz za elementem, ktorego wskaznik podany jako parametr funkcji
void list_of_stuff::add(int what, element *after_this) {
    increase_index(after_this->index + 1);
    element *new_el = creating_el(*after_this->next_one, after_this->index + 1, what);
    after_this->next_one = new_el;
}

    // Dodaje pojedynczy element na koniec listy
void list_of_stuff::add_at_the_end(int what) {
    element *last_el = find_last_el();
    element *new_el = creating_el(*first_one, last_el->index + 1, what);
    new_el->next_one = first_one;
}
    
    
    // Usuwa z listy element
void list_of_stuff::kill_el(element *trash_el) {
    // W tym celu znajduje element poprzedni bo jest potrzebny
    kill_el_knowing_one_before(find_el_before(trash_el));
}
    
    // Usuwa z listy element nastepny do podawanego funkcji
void list_of_stuff::kill_el_knowing_one_before(element *el_before) {
    // Usuniecie ostatniego elementu listy
    if (el_before->next_one == el_before) {
        cout<<"Gratz, you have just removed the last item of the list"<<endl;
        this->~list_of_stuff();
        return;
    }
    //Znaczy zmniejszenie indeksow elementow od usuwanego w gore
    increase_index(el_before->index + 1, -1);
    element *el_next = el_before->next_one->next_one;
    delete el_before->next_one;
    el_before->next_one = el_next;
}
    
    // Usuwa element na podstawie podanego indeksu (przekazuje usuwanie kolejnym funkcjom)
void list_of_stuff::remove_el_index(int idx) {
    element *el_before;
    if (idx == 0) el_before = find_last_el();
    else el_before = find_el_wth_index(idx - 1);
    kill_el_knowing_one_before(el_before);
}

    // Usuwa wszystkie elementy z dana wartoscia (przekazuje usuwanie kolejnym funkcjom)
void list_of_stuff::remove_el_value(int value) {
    element *before_trash_el = first_one;
    while(true) {
        // Znajduje nastepny element wskazujacy na element z dana wartoscia
        before_trash_el = look_for_el_pointing_value(value, before_trash_el);
        // Jezeli nie znalazl zadnego wychodzi z petli
        if (before_trash_el == elem_null) break;
        // Usuwa z listy element nastepny do podawanego funkcji
        kill_el_knowing_one_before(before_trash_el);
    }
}
    
    // Usuwa wszystkie elementy z wartoscia w danym przedziale (przekazuje usuwanie kolejnym funkcjom)
    // Dziala analogicznie do metody powyzej
void list_of_stuff::remove_el_value(int value1, int value2) {
    if (value1 > value2) {
        int value_temp = value1;
        value1 = value2;
        value2 = value_temp;
    }
    element *before_trash_el = first_one;
    while(true) {
        before_trash_el = look_for_el_pointing_range(value1, value2, before_trash_el);
        if (before_trash_el == elem_null) break;
        kill_el_knowing_one_before(before_trash_el);
    }
}


    
    
    // Usuwa powtorzenia
void list_of_stuff::remove_all_repetitions() {
    element *current_el = first_one;
    // Pierwsza petla wybiera po kolei kazdy element listy, a druga usuwa wszystkie powtorzenia
    do {
        element *before_trash_el = current_el;
        while(true) {
            before_trash_el = look_for_el_pointing_value(current_el->the_number, before_trash_el);
            if (before_trash_el == elem_null || before_trash_el->next_one == first_one) break;
            kill_el_knowing_one_before(before_trash_el);
        }
        current_el = current_el->next_one;
    } while (current_el != first_one);
}
    
    
    // Sprawdza dlugosc listy
int list_of_stuff::check_for_length() {
    return (find_last_el()->index + 1);
}
    

    // Porownywanie list
bool list_of_stuff::operator==(list_of_stuff& other) {
    element *current_el1 = first_one;
    element *current_el2 = other.first_one;
    do {
        if (current_el1->the_number != current_el2->the_number) return false;
        current_el1 = current_el1->next_one;
        current_el2 = current_el2->next_one;
    } while (current_el1 != first_one && current_el2 != other.first_one);
    return true;
}
    
    // Dostep do elementu
element* list_of_stuff::operator<(int index) {
    return find_el_wth_index(index);
}
    
    // Dodawanie dwoch list. Nowa lista zawiera najpierw elementy listy po lewej, a nastepnie elementy listy po prawej.
list_of_stuff& list_of_stuff::operator+(list_of_stuff& other_lst) {
    list_of_stuff *new_list1 = new list_of_stuff(*this);
    list_of_stuff *new_list2 = new list_of_stuff(other_lst);
    int length = new_list1->check_for_length();
    new_list2->increase_index(0, length);
    new_list1->find_last_el()->next_one = new_list2->first_one;
    new_list2->find_last_el()->next_one = new_list1->first_one;
    new_list2->first_one = elem_null;
    delete new_list2;
    return *new_list1;
}
    
    // Usuwanie wszystkich elementow w liscie po lewej, ktore wystepuja tez w liscie po prawej i zwracanie nowej listy (jak odejmowanie zbiorow).
list_of_stuff& list_of_stuff::operator-(list_of_stuff& other_lst) {
    list_of_stuff *new_list = new list_of_stuff(*this);
    element *current_el = other_lst.first_one;
    do {
        new_list->remove_el_value(current_el->the_number);
        current_el = current_el->next_one;
    } while (current_el != other_lst.first_one);
    return *new_list;
}
    
    // Operator = sluzy teraz do skopiowania listy po prawej
list_of_stuff& list_of_stuff::operator=(list_of_stuff& other_lst) {
    list_of_stuff *new_list = new list_of_stuff(other_lst);
    remove_everything();
    first_one = new_list->first_one;
    new_list->find_last_el()->next_one = first_one;
    new_list->first_one = elem_null;
    delete new_list;
    return *this;
}
    
    // Wypisuje wszystkie wartosci elementow
void list_of_stuff::print_everything() {
    element *current_el = first_one;
    do {current_el->print();current_el = current_el->next_one;} while (current_el != first_one);
    cout<<endl;
}
