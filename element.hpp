class element
{
    element *next_one;
   
    // Zwykly Konstruktor
    element(element& next_one, int index, int the_number);
    // Konstruktor do zrobienia pierwszego elementu
    element(int the_number);
    // Konstruktor nie ustalajacy nastepnego elementu (przydaje sie do kopiowania listy)
    element(int the_number, int index);
    
    // Wyswietla zawartosc elementu
    void print();
    
    friend class list_of_stuff;

public:
    int index, the_number;
    // Do zrobienia elem_null
    element();
};
