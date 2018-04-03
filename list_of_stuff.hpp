#include "element.hpp"


class list_of_stuff
{
    // Wskaznik na pierwszy element listy
    element *first_one;
    
    // Funkcja Tworzaca nowy element.
    element* creating_el(element& next_one, int index, int the_number);
    
    // Wszystkie indeksy poczynajac od danego zwiekszone o "x", domyslnie (0, 1)
    void increase_index(int starting = 0, int x = 1);
    
    // Znajdzie najblizszy element wskazujacy na element z dana liczba lub dojdzie do konca listy
    element* look_for_el_pointing_value(int value, element* starting);
    
    // Znajdzie element wskazujacy na element z wartoscia w przedziale (zaklada value1 <= value2) lub dojdzie do konca listy
    element* look_for_el_pointing_range(int value1, int value2, element* starting);
    
    
    void remove_everything();
    
    public:
    // Tworzenie pustej listy
    list_of_stuff();
    // Tworzenie listy z jedna pojedyncza wartoscia
    list_of_stuff(int first_value);
    // Do kopiowania listy
    list_of_stuff(list_of_stuff& copied_lst);
    // Destruktor. Usuwa najpierw wszystkie elementy, a dopiero potem jest usunieta lista sama w sobie.
    ~list_of_stuff();
    
    // Znajduje ostatni element
    element* find_last_el();
    // Znajdzie element z danym indeksem lub zwroci elem_null.
    element* find_el_wth_index(int idx);
    // Znajdzie najblizszy element z dana wartoscia lub zwroci "elem_null"
    element* look_for_value(int value, element* starting);
    // Znajduje pierszy element o danej wartosci lub zwroci "elem_null"
    element* look_for_value(int value);
    // Znajduje element przed podanym jako parametr
    element* find_el_before(element *before_this);
    
    // Dodaje element na indeks
    void add(int what, int where = 0);
    // Dodaje na poczatek listy "size" nowych elementow, jest to rozmiar tablicy nowych wartosci podanej jako parametr
    void add_more(int size, int what[]);
    // Dodaje pojedynczy element zaraz za elementem, ktorego wskaznik podany jako parametr funkcji
    void add(int what, element *after_this);
    // Dodaje pojedynczy element na koniec listy
    void add_at_the_end(int what);
    
    // Usuwa z listy element
    void kill_el(element *trash_el);
    // Usuwa z listy element nastepny do podawanego funkcji
    void kill_el_knowing_one_before(element *el_before);
    // Usuwa element na podstawie podanego indeksu (przekazuje usuwanie kolejnym funkcjom)
    void remove_el_index(int idx);
    // Usuwa wszystkie elementy z dana wartoscia (przekazuje usuwanie kolejnym funkcjom)
    void remove_el_value(int value);
    // Usuwa wszystkie elementy z wartoscia w danym przedziale (przekazuje usuwanie kolejnym funkcjom)
    // Dziala analogicznie do metody powyzej
    void remove_el_value(int value1, int value2);
    
    // Usuwa powtorzenia
    void remove_all_repetitions();
    
    // Sprawdza dlugosc listy
    int check_for_length();
    
    // Porownywanie list
    bool operator==(list_of_stuff& other);
    // Dostep do elementu
    element* operator<(int index);
    // Dodawanie dwoch list. Nowa lista zawiera najpierw elementy listy po lewej, a nastepnie elementy listy po prawej.
    list_of_stuff& operator+(list_of_stuff& other_lst);
    // Usuwanie wszystkich elementow w liscie po lewej, ktore wystepuja tez w liscie po prawej i zwracanie nowej listy (jak odejmowanie zbiorow).
    list_of_stuff& operator-(list_of_stuff& other_lst);
    // Operator = sluzy teraz do skopiowania listy po prawej
    list_of_stuff& operator=(list_of_stuff& other_lst);
    
    // Wypisuje wszystkie wartosci elementow
    void print_everything();
};
