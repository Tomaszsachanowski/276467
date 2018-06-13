#ifndef AISDI_LINEAR_VECTOR_H
#define AISDI_LINEAR_VECTOR_H

#include <cstddef>
#include <initializer_list>
#include <stdexcept>
#include <cmath>
#include <iostream>


namespace aisdi
{

template <typename Type>
class Vector
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

/*--------------------------------------------------------------------------------*/
private:
  pointer v; // pointer na alokowana pamięć
  size_type size;
  size_type maxSize;
  int ratio;            // wspolczynnik ile mamy alokowac nadmiarem
/*--------------------------------------------------------------------------------*/


public:

/*--------------------------------------------------------------------------------*/
    Vector() : size(0), maxSize(4), ratio(1)
    {
        v = new value_type[maxSize];
    }
/*--------------------------------------------------------------------------------*/


/*--------------------------------------------------------------------------------*/
    Vector(std::initializer_list<Type> l) : Vector()//wywołujemy konstruktor aby
    {//zalokowac pamiec i wzucamy do neigo elementy
        for (auto it = l.begin(); it != l.end(); ++it)
        { //auto aby sa mdostosował typ
          append(*it); //wzucam elelmnt na koniec aby miec w tej samej tablicy
        }
    }
/*--------------------------------------------------------------------------------*/


/*--------------------------------------------------------------------------------*/
    Vector(const Vector& other) : Vector() //konstr kopiujący tak samo jak wyzej
    {
        for (auto it = other.begin(); it != other.end(); ++it)
        {
          append(*it);
        }
    }
/*--------------------------------------------------------------------------------*/



/*--------------------------------------------------------------------------------*/
    Vector(Vector&& other) : v(other.v), size(other.size), maxSize(other.maxSize), ratio(other.ratio) //move
    {
        other.v = nullptr; //poprtosu przemieniam pointeruy na wsakzywana pamiec i zeruje
        other.size = 0;
                other.maxSize=0;
                other.ratio=0;
    }
/*--------------------------------------------------------------------------------*/


/*--------------------------------------------------------------------------------*/
    ~Vector()
    {               if(v!=nullptr)
            delete[] v;
    }
/*--------------------------------------------------------------------------------*/


/*--------------------------------------------------------------------------------*/
    Vector& operator=(const Vector& other) // kostrukotr przypisania
    {
        if (&other != this) //działa podobnie jak w liscie tym ze
        { //usuniecie elelmentu polega na przepisaniau wartosic z następnych
            //elelentów one nie sa kasowane ale zamieniane wartoici i zmniejszany liczbza elelentów
          // while (!isEmpty())
          //  erase(--end());
                    size=0; //wystarczy ze zeruejmy liczbe elementów i
                    // ipotem przez wstawianie na koniec nadpisuje dane
            for (auto it = other.begin(); it != other.end(); ++it)
            {
              append(*it);
            }

        }
        return *this;
    }
/*--------------------------------------------------------------------------------*/


/*--------------------------------------------------------------------------------*/
    Vector& operator=(Vector&& other) //move
    {
        if (&other != this)
        {

        //    while (!isEmpty())
          //    erase(--end());
          //jeden test wymagał aby usunac elelmnety z tabilcy i dopiero wstawic
          // z drugiej  choć zamiast delete wystarczy zrobic to zakomentowane
          // bo nadpisezemy sobie dane  tylko wtedy bedzie błada w teście
          // jest wymagane aby usunac vektor zainicjalizowany i dopiero potem
          // wstaiwc nvoe elelmnety
            delete[] v;

            v = other.v;
            size = other.size;
            maxSize = other.maxSize;
            ratio = other.ratio;

            other.v = nullptr;
            other.size = 0;
        }
        return *this;
    }
/*--------------------------------------------------------------------------------*/


/*--------------------------------------------------------------------------------*/
    bool isEmpty() const
    {
        return !size;
    }
/*--------------------------------------------------------------------------------*/


/*--------------------------------------------------------------------------------*/
    size_type getSize() const
    {
        return size;
    }
/*--------------------------------------------------------------------------------*/


/*--------------------------------------------------------------------------------*/
    void append(const Type& item)
    { //gdy tablica pełn trzeba na nowo alokowac
        if (size == maxSize)
        {
          size_t pom = maxSize;
          maxSize += ceil(maxSize * ratio);//liczba całkowita w góre

          pointer v2 = v;
          v = new value_type[maxSize];

          for (size_t i = 0; i < pom; i++)
             v[i] = v2[i]; //przekopiownaie danych

          delete[] v2;
        }
        v[size++] = item; //dodoanie elelmentu jeszcze
    }
/*--------------------------------------------------------------------------------*/


/*--------------------------------------------------------------------------------*/
    void prepend(const Type& item)
    {
        insert(begin(),item);
    }
/*--------------------------------------------------------------------------------*/


/*--------------------------------------------------------------------------------*/
    void insert(const const_iterator& insertPosition, const Type& item)
    {
    //najtrudniejsza rzecz wstawianie w na podanym miejscu
        if (insertPosition > end())
          throw std::out_of_range("poza zaakresem");

        size_t insPos = 0;

        for (auto it = begin(); it != insertPosition; ++it)
          insPos++; // wyliczenie pozycji elementu wpisywanego

        if (size == maxSize) // sprawdzenie czy starczy nam pamieci
        {
          size_t pom = maxSize;
          maxSize += ceil(maxSize*ratio); //liczba całkowita w góre

          pointer v2 = v; //pomocniczy pointer do załadowania starych wartosic
          v = new value_type[maxSize]; //wskazujemy na nowa pamieć

          for (size_t i = 0; i < insPos; ++i)
            v[i] = v2[i];

          v[insPos] = item;

          for (size_t i = insPos+1; i <= pom; i++)
            v[i] = v2[i-1];

          size++;
          delete[] v2;
        }
        else
        {
          for (size_t i = size; i > insPos; i--)
            v[i] = v[i-1]; //rzesuwamy w tył wartości
                //az do elelmnetu na kt©óy mamy wskazac
          v[insPos] = item;
          size++;
        }
    }
/*--------------------------------------------------------------------------------*/


/*--------------------------------------------------------------------------------*/
    Type popFirst()
    {
        if (isEmpty())
          throw std::logic_error("vector pusty");

        Type temp = *v;
        for (size_t i = 0; i < (size-1); i++)
          v[i] = v[i+1];
        size--;

        return temp;
    }
/*--------------------------------------------------------------------------------*/


/*--------------------------------------------------------------------------------*/
    Type popLast()
    {
        if (isEmpty())
          throw std::logic_error("vector pusty");

        Type temp = v[size-1];
        size--;

        return temp;
    }
/*--------------------------------------------------------------------------------*/


/*--------------------------------------------------------------------------------*/
    void erase(const const_iterator& position)
    {
        erase(position,position+1);
    }
/*--------------------------------------------------------------------------------*/


/*--------------------------------------------------------------------------------*/

    void erase(const const_iterator& firstIncluded, const const_iterator& lastExcluded)
    {   //uwaga usuniecie ellemntu nie polega na trwałym uuswanieu ale na nadpisywaniu pozycji do usniecia pozycjami za
        // za obszarem do usnuniecia
        if (firstIncluded >= lastExcluded) //czy dobry przedział
          return;

        if (lastExcluded > end())
          throw std::out_of_range("poza zakresem");

        size_t count = 0; // Pozycja last Exculded
        size_t firstIn = 0; // Pozycja first Included

        for (auto it = begin(); it != lastExcluded; ++it)
        {
          if (it == firstIncluded)  // znalezienie pozycji firstincluded
            firstIn = count;
          count++;                  // znaleznenie pozycji lastexcluded
        }

        for (size_t i = count; i < size; i++)

          v[i - count + firstIn] = v[i];    // nadpisannie od first included
    //to działa tak V[fistr+1,2,3,4]+V[lastexecuted+1,2,3,4 itd]
        size -= (count-firstIn); //zmaina liczby eelmnetów
    }// elelnety za size nadal sa potem zostgana nadpisane jak cos dodamy do wektora

/*--------------------------------------------------------------------------------*/
 /*void erase(const const_iterator& firstIncluded, const const_iterator& lastExcluded)
    {
        if (firstIncluded >= lastExcluded)
          return;

        if (lastExcluded > end())
          throw std::out_of_range("out of range");

        size_t count = 0; // Pozycja last Exculded
        size_t firstIn = 0; // Pozycja first Included

        for (auto it = begin(); it != lastExcluded; ++it)
        {
          if (it == firstIncluded)  // znalezienie pozycji firstincluded
            firstIn = count;
          count++;                  // znaleznenie pozycji lastexcluded
        }

        pointer new_v=new value_type[ size - (count-firstIn)];
        for (size_t i = 0; i <firstIn; i++)
            new_v[i]=v[i];
        for (size_t i = count; i < size; i++)

          new_v[i - count + firstIn] = v[i];    // nadpisannie od first included
        delete[] v;

        v=new_v;
        size -= (count-firstIn);
    }
*/
/*--------------------------------------------------------------------------------*/
    iterator begin()
    {
        Iterator i = Iterator(this,0);
        return i;
    }
/*--------------------------------------------------------------------------------*/


/*--------------------------------------------------------------------------------*/
    iterator end()
    {
        Iterator i = Iterator(this,size);
        return i;
    }
/*--------------------------------------------------------------------------------*/


/*--------------------------------------------------------------------------------*/
    const_iterator cbegin() const
    {
        return ConstIterator(this,0);
    }
/*--------------------------------------------------------------------------------*/


/*--------------------------------------------------------------------------------*/
    const_iterator cend() const
    {
        return ConstIterator(this,size);
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
class Vector<Type>::ConstIterator
{
public:
  using iterator_category = std::bidirectional_iterator_tag;
  using value_type = typename Vector::value_type;
  using difference_type = typename Vector::difference_type;
  using pointer = typename Vector::const_pointer;
  using reference = typename Vector::const_reference;

private:
/*--------------------------------------------------------------------------------*/
    const Vector<value_type>* vec;
    size_t nr;
/*--------------------------------------------------------------------------------*/

public:
/*--------------------------------------------------------------------------------*/
    explicit ConstIterator(const Vector<value_type>* v = nullptr, size_t n = 0) : vec(v), nr(n)
    {}
/*--------------------------------------------------------------------------------*/


/*--------------------------------------------------------------------------------*/
    reference operator*() const
    {
        if (nr >= vec->size)
          throw std::out_of_range("range_check");
        return vec->v[nr];
    }
/*--------------------------------------------------------------------------------*/


/*--------------------------------------------------------------------------------*/
    ConstIterator& operator++()
    {
        if (nr >= vec->size)
          throw std::out_of_range("range_check");
        else
          nr++;
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
        if (nr <= 0)
          throw std::out_of_range("range_check");
        else
          nr--;
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
        ConstIterator res = *this;
        if (d >= 0 && res.nr + d > vec->size)
          throw std::out_of_range("range_check");
        else
          res.nr += d;
        return res;
    }
/*--------------------------------------------------------------------------------*/


/*--------------------------------------------------------------------------------*/
    ConstIterator operator-(difference_type d) const
    {
        ConstIterator res = *this;
        if (d >= 0 && res.nr - d < 0)
          throw std::out_of_range("range_check");
        else
          res.nr -= d;
        return res;
    }
/*--------------------------------------------------------------------------------*/


/*--------------------------------------------------------------------------------*/
    bool operator==(const ConstIterator& other) const
    {
        return vec == other.vec && nr == other.nr;
    }
/*--------------------------------------------------------------------------------*/


/*--------------------------------------------------------------------------------*/
    bool operator!=(const ConstIterator& other) const
    {
        return vec != other.vec || nr != other.nr;
    }
/*--------------------------------------------------------------------------------*/



// Potrzebne do erase/insert
/*--------------------------------------------------------------------------------*/
    bool operator>(const ConstIterator& other) const
    {
        return nr > other.nr;
    }

    bool operator>=(const ConstIterator& other) const
    {
        return nr >= other.nr;
    }
/*--------------------------------------------------------------------------------*/
};

template <typename Type>
class Vector<Type>::Iterator : public Vector<Type>::ConstIterator
{
public:
  using pointer = typename Vector::pointer;
  using reference = typename Vector::reference;

  explicit Iterator(const Vector<value_type>* v=nullptr, size_t n=0) : ConstIterator(v,n)
  {}

  Iterator(const ConstIterator& other)
    : ConstIterator(other)
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

#endif // AISDI_LINEAR_VECTOR_H
