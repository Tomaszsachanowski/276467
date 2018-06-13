#ifndef AISDI_LINEAR_LINKEDLIST_H
#define AISDI_LINEAR_LINKEDLIST_H

#include <cstddef>
#include <initializer_list>
#include <stdexcept>

namespace aisdi
{

template <typename Type>
class LinkedList
{
public:
  using difference_type = std::ptrdiff_t;
  using size_type = std::size_t;
  using value_type = Type;
  using pointer = Type*;
  using reference = Type&;
  using const_pointer = const Type*;
  using const_reference = const Type&;

  class ConstIterator;
  class Iterator;
  using iterator = Iterator;
  using const_iterator = ConstIterator;

private:

/*--------------------------------------------------------------------------------*/
    class Node //klasa wezel
    {
        public:
            value_type data; //wartosc przechowywana
            Node* prev; //połączene z poprzednim węzłem
            Node* next; //połączenie z następnym węzłem

            Node() {}; // konstrukotor domyslny
            Node(value_type val) : data(val), prev(nullptr), next(nullptr) {};//konstruktor z wartoscia

            bool operator==(const Node& other)//operator przyrównania  aby nie mozna bylo zmieniac wezla dlatego const
            {
              return (data == other.data  &&  prev == other.prev && next == other.next);
            }
    };


    size_type size;// liczba węzłów w kolejce
    Node* head; //wskaznik na glowe
    Node* tail; //wskaznik na koniec
    // UWaga użyłem dwóch strażników head i tail, po miedzy nimi jest wezły z danymi
/*--------------------------------------------------------------------------------*/

public:
/*--------------------------------------------------------------------------------*/

    LinkedList() : size(0)
    {
        head = new Node; //head i tail sa naszymi strażnikami miedzy nimi dopiero sa elementy a one nie sa liczone jako elementy
		tail = new Node;

		head->prev = nullptr;
		tail->next = nullptr;

        head->next = tail;
        tail->prev = head;

    }
/*--------------------------------------------------------------------------------*/


/*--------------------------------------------------------------------------------*/
    LinkedList(std::initializer_list<Type> l) : LinkedList() //użycie konstrukotra domyslnego aby stworzyć głowę i ogon
    {

        for (auto it_pointer = l.begin(); it_pointer != l.end(); ++it_pointer) //auto atomatyczne wyznacza typ
            append(*it_pointer); //wżucamy element na koniec aby były w tej samej kolejności węzły
            //begin zwraca mi wskażnik nastepny za głowa a end zwraca mi wskażnik na głowę
    }
/*--------------------------------------------------------------------------------*/


/*--------------------------------------------------------------------------------*/
    LinkedList(const LinkedList& other) : LinkedList()//użycie konstrukotra domyslnego aby stworzyć głowę i ogon
    {

        for (auto it_pointer = other.begin(); it_pointer != other.end(); ++it_pointer)
            append(*it_pointer);
    }
/*--------------------------------------------------------------------------------*/



/*--------------------------------------------------------------------------------*/


    LinkedList(LinkedList&& other) //:  head(other.head), tail(other.tail), size(other.size) //mozna użyć tez listy inicjalizacyjnej
    {

            head = other.head; //zamieniamy tylko głowy i ogony a takze liczbe elemetów
            tail = other.tail;
            size = other.size;
                                //a stare głowy wskazuja na nic
        other.head = nullptr;
        other.tail = nullptr;
        other.size = 0;
    }
/*--------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------*/
    ~LinkedList()
    {   //usuówam elementy od głowy
        while(!isEmpty())
            erase(begin());
        //na samym końcu pozostanie mi usunóac glowe i ogon bo jak wspomniąłem one sa tylko straznikami
        delete head;
        delete tail;

    }
/*--------------------------------------------------------------------------------*/


/*--------------------------------------------------------------------------------*/
    LinkedList& operator=(const LinkedList& other) //konstruktor kopjujący
    {
        if (&other != this) // czy nie przypisujemy a=a
        {
            while(!isEmpty())   //czyscimy jedna kolejke aby mołŋa zawierac tylko druga
                erase(begin()); // odbywa sie to an takiej samej zasadzie jak w destrukotrze

            for (auto it_pointer = other.begin(); it_pointer != other.end(); ++it_pointer) //jkao ze may pusta liste wrzzucamy do niej elementy drugiej listy
              append(*it_pointer);
        }
        return *this;
    }
/*--------------------------------------------------------------------------------*/


/*--------------------------------------------------------------------------------*/
    LinkedList& operator=(LinkedList&& other) //opercja move
    {
        if (&other != this)
        {

            while(!isEmpty()) //czyszczę kolejke
                    erase(begin());

            head = other.head; //potem wystarczy ze przepisze tylko głowy
            tail = other.tail;
            size = other.size;

            other.head = nullptr; //stre głwy maja wskazywac teraz na nic
            other.tail = nullptr;
            other.size = 0;

        }
        return *this;
    }
/*--------------------------------------------------------------------------------*/


/*--------------------------------------------------------------------------------*/
    bool isEmpty() const
    {
        return !size;   //zwraca mi czy sa jakies elemetny
    }
/*--------------------------------------------------------------------------------*/


/*--------------------------------------------------------------------------------*/
    size_type getSize() const
    {
        return size;    //zwraca mi tylko rozmiar
    }
/*--------------------------------------------------------------------------------*/


/*--------------------------------------------------------------------------------*/
    void append(const Type& item)
    {
        Node* nowy = new Node(item);    //stwazramy nowy węzeł
        nowy->next = tail; //wzucamy go na koniec
        nowy->prev = tail->prev;
        tail->prev = nowy;
        nowy->prev->next = nowy;
        size++;
    }
/*--------------------------------------------------------------------------------*/


/*--------------------------------------------------------------------------------*/
    void prepend(const Type& item)
    {
        Node* nowy = new Node(item); //analogicznie co wyzej ale ty raem an poczatek
        nowy->prev = head;
        nowy->next = head->next;
        head->next = nowy;
        nowy->next->prev = nowy;
        size++;
    }
/*--------------------------------------------------------------------------------*/


/*--------------------------------------------------------------------------------*/
    void insert(const const_iterator& insertPosition, const Type& item) //stworzenie węzła na danej pozycji
    {
        //if(insertPosition == begin()) //sytuacje szczególne ze albo na poczatku albo na koncu
         //       prepend(item);        //choć iterator juz tak dobrze dziłą dzieki dwum stranikom
                                        //nie trzeba badać tych sytuacji
       // else if (insertPosition == end())
           //     append(item);
      //  else
      //  {
                Node* nowy = new Node(item);
                nowy->prev = insertPosition.it->prev;
                nowy->next = insertPosition.it;
                insertPosition.it->prev->next = nowy;
                insertPosition.it->prev = nowy;
                size++;
      //  }
    }
/*--------------------------------------------------------------------------------*/


/*--------------------------------------------------------------------------------*/
    Type popFirst()
    {
        value_type temp = (begin()).it->data; //wywołujemy funkcje któ©a zwraca
        erase(begin()); // iterator tuz za głowa usuwam elemnet z poczatku
        return temp;
    }
/*--------------------------------------------------------------------------------*/


/*--------------------------------------------------------------------------------*/
    Type popLast()
    {
        value_type temp = (--end()).it->data; //dlaczego minus minus bo bo ostatni elemneto to ogon
        erase(--end());  //a jet on tylko straznikiem czyli musimy sie cofnać o jeden
        return temp;
    }
/*--------------------------------------------------------------------------------*/


/*--------------------------------------------------------------------------------*/
    void erase(const const_iterator& possition)
    {
        if(possition == end()) // bo nie moge usunac ogona on jest tylko straznikiem a nie wezelem z dana nasza
            throw std::out_of_range("Poza zakresem");
        possition.it->prev->next = possition.it->next;
        possition.it->next->prev = possition.it->prev;
        delete possition.it;
        size--;
    }
/*--------------------------------------------------------------------------------*/


/*--------------------------------------------------------------------------------*/
    void erase(const const_iterator& firstIncluded, const const_iterator& lastExcluded)
    {
        auto it_pointer = firstIncluded; //automatycznie dobieramy typ
        while (it_pointer != lastExcluded)
            erase(it_pointer++);
    }
/*--------------------------------------------------------------------------------*/


/*--------------------------------------------------------------------------------*/
    iterator begin()
    {
        Iterator it_pointer = Iterator(head->next); //bo ustaliłem ze begin wsakzuje na pierwszy
        return it_pointer; //element za głowa bo goła nie wskazuje na nic
    }
/*--------------------------------------------------------------------------------*/


/*--------------------------------------------------------------------------------*/
    iterator end()
    {
        Iterator it_pointer =  Iterator(tail);// iterator na koniec wskazuej na weżeł dlatego w niekturych metodach
        return it_pointer;  //trzeba cofnąć ssie o jeden ab miec naiterator któ©y wkzuje na ostatni element
    }
/*--------------------------------------------------------------------------------*/


/*--------------------------------------------------------------------------------*/
    const_iterator cbegin() const
    {
        ConstIterator it_pointer = ConstIterator(head->next);
        return it_pointer;
    }
/*--------------------------------------------------------------------------------*/


/*--------------------------------------------------------------------------------*/
    const_iterator cend() const
    {
        ConstIterator it_pointer = ConstIterator(tail);
        return it_pointer;
    }
/*--------------------------------------------------------------------------------*/


/*--------------------------------------------------------------------------------*/
    const_iterator begin() const
    {
        return cbegin();
    }
/*--------------------------------------------------------------------------------*/


/*--------------------------------------------------------------------------------*/
    const_iterator end() const
    {
        return cend();
    }
/*--------------------------------------------------------------------------------*/
};

template <typename Type>
class LinkedList<Type>::ConstIterator
{
public:
  using iterator_category = std::bidirectional_iterator_tag;
  using value_type = typename LinkedList::value_type;
  using difference_type = typename LinkedList::difference_type;
  using pointer = typename LinkedList::const_pointer;
  using reference = typename LinkedList::const_reference;

/*--------------------------------------------------------------------------------*/
    Node* it;
/*--------------------------------------------------------------------------------*/


/*--------------------------------------------------------------------------------*/
    explicit ConstIterator(Node* iter) : it(iter)
    {}
/*--------------------------------------------------------------------------------*/


/*--------------------------------------------------------------------------------*/
    reference operator*() const
    {
        if (it->next == nullptr)
            throw std::out_of_range("out of range");
        return it->data;
    }
/*--------------------------------------------------------------------------------*/


/*--------------------------------------------------------------------------------*/
    ConstIterator& operator=(const ConstIterator& other)
    {
        it = other.it;
        return *this;
    }
/*--------------------------------------------------------------------------------*/


/*--------------------------------------------------------------------------------*/
    ConstIterator& operator++()
    {
        if (it->next == nullptr)
            throw std::out_of_range("out of range");
        it = it->next;
        return *this;
    }
/*--------------------------------------------------------------------------------*/


/*--------------------------------------------------------------------------------*/
    ConstIterator operator++(int)
    {
        ConstIterator res = *this;
        operator++();
        return res;
    }
/*--------------------------------------------------------------------------------*/


/*--------------------------------------------------------------------------------*/
    ConstIterator& operator--()
    {
        if (it->prev->prev == nullptr)
          throw std::out_of_range("out of range");
        it = it->prev;
        return *this;
    }
/*--------------------------------------------------------------------------------*/


/*--------------------------------------------------------------------------------*/
    ConstIterator operator--(int)
    {
        ConstIterator res = *this;
        operator--();
        return res;
    }
/*--------------------------------------------------------------------------------*/


/*--------------------------------------------------------------------------------*/
    ConstIterator operator+(difference_type d) const
    {
        auto res = *this;
        for (difference_type i = 0; i < d; i++)
                res++;
        for (difference_type i = 0; i > d; i--)
                res--;
        return res;
    }
/*--------------------------------------------------------------------------------*/


/*--------------------------------------------------------------------------------*/
    ConstIterator operator-(difference_type d) const
    {
        auto res = *this;
        for (difference_type i = 0; i < d; i++)
                res--;
        for (difference_type i = 0; i > d; i--)
                res++;
        return res;
    }
/*--------------------------------------------------------------------------------*/


/*--------------------------------------------------------------------------------*/
    bool operator==(const ConstIterator& other) const
    {
        return (it == other.it);
    }
/*--------------------------------------------------------------------------------*/


/*--------------------------------------------------------------------------------*/
    bool operator!=(const ConstIterator& other) const
    {
        return (it != other.it);
    }
/*--------------------------------------------------------------------------------*/
};

template <typename Type>
class LinkedList<Type>::Iterator : public LinkedList<Type>::ConstIterator
{
public:
  using pointer = typename LinkedList::pointer;
  using reference = typename LinkedList::reference;

  explicit Iterator(Node* iter) : ConstIterator(iter)
  {}

  Iterator(const ConstIterator& other) : ConstIterator(other)
  {}

  Iterator& operator++()
  {
    ConstIterator::operator++();
    return *this;
  }

  Iterator operator++(int)
  {
    auto result = *this;
    ConstIterator::operator++();
    return result;
  }

  Iterator& operator--()
  {
    ConstIterator::operator--();
    return *this;
  }

  Iterator operator--(int)
  {
    auto result = *this;
    ConstIterator::operator--();
    return result;
  }

  Iterator operator+(difference_type d) const
  {
    return ConstIterator::operator+(d);
  }

  Iterator operator-(difference_type d) const
  {
    return ConstIterator::operator-(d);
  }

  reference operator*() const
  {
    // ugly cast, yet reduces code duplication.
    return const_cast<reference>(ConstIterator::operator*());
  }
};

}

#endif // AISDI_LINEAR_LINKEDLIST_H
