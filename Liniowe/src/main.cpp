#include <cstddef>
#include <cstdlib>
#include <string>
#include <chrono>
#include <fstream>

#include "Vector.h"
#include "LinkedList.h"

using namespace std;

namespace
{
template <typename T>
using Vector = aisdi::Vector<T>;

template <typename T>
using Linkedlist = aisdi::LinkedList<T>;


void TestPopFirst(ofstream& file)
{
/*--------------------------------------------------------------------------------*/
  Vector<std::string> vector;
  Linkedlist<std::string> list;
/*--------------------------------------------------------------------------------*/
  for (int i = 0; i < 100; i++)
  vector.append("wejscie");

  for (int i = 0; i < 100; i++)
  list.append("wejscie");
/*--------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------*/
  auto clock_start = std::chrono::high_resolution_clock::now(); //mierzymy czas od tego mmonetu

  for (int i = 0; i < 100; i++)
  vector.popFirst();

  auto clock_end = std::chrono::high_resolution_clock::now();//mierzymy czas konca

  file << std::chrono::duration_cast<std::chrono::nanoseconds>(clock_end-clock_start).count() << " ";
/*--------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------*/
//analogicznie do listy
  clock_start = std::chrono::high_resolution_clock::now();

  for (int i = 0; i < 100; i++)
  list.popFirst();

  clock_end = std::chrono::high_resolution_clock::now();

  file << std::chrono::duration_cast<std::chrono::nanoseconds>(clock_end-clock_start).count() << "\n";
/*--------------------------------------------------------------------------------*/
}

void TestPopLast(ofstream& file)
{
/*--------------------------------------------------------------------------------*/
  Vector<std::string> vector;
  Linkedlist<std::string> list;
/*--------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------*/
  for (int i = 0; i < 100; i++)
  vector.append("input");

  for (int i = 0; i < 100; i++)
  list.append("input");
/*--------------------------------------------------------------------------------*/
  auto clock_start = std::chrono::high_resolution_clock::now();

  for (int i = 0; i < 100; i++)
  vector.popLast();

  auto clock_end = std::chrono::high_resolution_clock::now();

  file << std::chrono::duration_cast<std::chrono::nanoseconds>(clock_end-clock_start).count() << " ";
/*--------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------*/
  clock_start = std::chrono::high_resolution_clock::now();

  for (int i = 0; i < 100; i++)
  list.popLast();

  clock_end = std::chrono::high_resolution_clock::now();

  file << std::chrono::duration_cast<std::chrono::nanoseconds>(clock_end-clock_start).count() << "\n";
/*--------------------------------------------------------------------------------*/
}

void TestAppend(ofstream& file)
{
/*--------------------------------------------------------------------------------*/
  Vector<std::string> vector;
  Linkedlist<std::string> list;
/*--------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------*/
  auto clock_start = std::chrono::high_resolution_clock::now();

  for (int i = 0; i < 100; i++)
  vector.append("input");

  auto clock_end = std::chrono::high_resolution_clock::now();

  file << std::chrono::duration_cast<std::chrono::nanoseconds>(clock_end-clock_start).count() << " ";
/*--------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------*/
  clock_start = std::chrono::high_resolution_clock::now();

  for (int i = 0; i < 100; i++)
  list.append("input");

  clock_end = std::chrono::high_resolution_clock::now();

  file << chrono::duration_cast<std::chrono::nanoseconds>(clock_end-clock_start).count() << "\n";
/*--------------------------------------------------------------------------------*/
}


void TestPrepend(ofstream& file)
{
/*--------------------------------------------------------------------------------*/
  Vector<std::string> vector;
  Linkedlist<std::string> list;
/*--------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------*/
  auto clock_start = std::chrono::high_resolution_clock::now();

  for (int i = 0; i < 100; i++)
  vector.prepend("input");

  auto clock_end = std::chrono::high_resolution_clock::now();

  file << std::chrono::duration_cast<std::chrono::nanoseconds>(clock_end-clock_start).count() << " ";
/*--------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------*/
  clock_start = std::chrono::high_resolution_clock::now();

  for (int i = 0; i < 100; i++)
  list.prepend("input");

  clock_end = std::chrono::high_resolution_clock::now();

  file << chrono::duration_cast<std::chrono::nanoseconds>(clock_end-clock_start).count() << "\n";
/*--------------------------------------------------------------------------------*/
}

} // namespace



int main(int argc, char** argv)
{

  ofstream file;
 /*--------------------------------------------------------------------------------*/
  file.open("Res_append.txt");
 // file << "RESULTS OF APPEND\nVECTOR LIST\n";

  (void)argc;
  (void)argv;
  const std::size_t repeatCount = 100;

  for (std::size_t i = 0; i < repeatCount; ++i){
    file<< i <<" ";
    TestAppend(file);
    }
  file.close();
/*--------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------*/
  file.open("Res_popFirst.txt");
 // file << "RESULTS OF POPFIRST\nVECTOR LIST\n";

  for (std::size_t i = 0; i < repeatCount; ++i){
    file<< i <<" ";
    TestPopFirst(file);
    }

  file.close();
/*--------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------*/
  file.open("Res_popLast.txt");
//  file << "RESULTS OF POPLAST\nVECTOR LIST\n";

  for (std::size_t i = 0; i < repeatCount; ++i){
    file<< i <<" ";
    TestPopLast(file);
    }
  file.close();
/*--------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------*/
  file.open("Res_prepend.txt");
//  file << "RESULTS OF POPLAST\nVECTOR LIST\n";

  for (std::size_t i = 0; i < repeatCount; ++i){
    file<< i <<" ";
    TestPrepend(file);
    }
  file.close();
/*--------------------------------------------------------------------------------*/
}
