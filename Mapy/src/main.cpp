#include <cstddef>
#include <cstdlib>
#include <string>
#include <chrono>
#include <fstream>
#include <ctime>
#include <math.h>
#include "HashMap.h"
#include "TreeMap.h"

using namespace std;
namespace
{

template <typename K, typename V>
using Hash = aisdi::HashMap<K, V>;

template <typename K, typename V>
using Tree = aisdi::TreeMap<K, V>;


void perfomTestAppend(std::ofstream& file)
{
		Hash<int,std::string> hashTab;
		Tree<int,std::string> treeTab;

		for (size_t i = 0; i < 100; ++i)
		{
            auto suma=std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now()-std::chrono::high_resolution_clock::now());
           suma=suma-suma;
            for( int srednia=0;srednia<100;srednia++){
			auto clock_start1 = std::chrono::high_resolution_clock::now();

			for (unsigned int k = 0; k < 10*i ;k++)
				hashTab[rand()%1000] = "TDD is love";

			auto clock_end1 = std::chrono::high_resolution_clock::now();
			suma+= std::chrono::duration_cast<std::chrono::nanoseconds>(clock_end1-clock_start1);
            }
            suma=suma/100;
			file << i << " " << suma.count() << " ";

        suma=suma-suma;
        for( int srednia=0;srednia<100;srednia++){
			auto clock_start2 = std::chrono::high_resolution_clock::now();

			for (unsigned int k = 0; k <10*i; k++)
				treeTab[rand()%1000] = "TDD is love";

			auto clock_end2 = std::chrono::high_resolution_clock::now();
            suma+= std::chrono::duration_cast<std::chrono::nanoseconds>(clock_end2-clock_start2);
            }
            suma=suma/100;
			file << suma.count() << std::endl;
		}
}

void perfomTestDelete(std::ofstream& file)
{

		Hash<int,std::string> hashTab;
		Tree<int,std::string> treeTab;

		for (int i = 0; i < 80000; ++i)
		{
			hashTab[rand()%10000] = "TDD is love";
			treeTab[rand()%10000] = "TDD is love";
		}

		for (size_t i = 0; i < 40; ++i)
		{
		auto suma=std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now()-std::chrono::high_resolution_clock::now());
        suma=suma-suma;

            for( int srednia=0;srednia<10;srednia++){
			auto clock_start1 = std::chrono::high_resolution_clock::now();

			for (unsigned int k = 0; k < i; k++)
				hashTab.remove(hashTab.begin());

			auto clock_end1 = std::chrono::high_resolution_clock::now();
             suma+= std::chrono::duration_cast<std::chrono::nanoseconds>(clock_end1-clock_start1);
           }
            suma=suma/10;
            file << i << " " <<suma.count() << " ";


            suma=suma-suma;
            for( int srednia=0;srednia<10;srednia++){

			auto clock_start2 = std::chrono::high_resolution_clock::now();

			for (unsigned int k = 0; k <i; k++)
				treeTab.remove(treeTab.begin());

			auto clock_end2 = std::chrono::high_resolution_clock::now();
            suma+= std::chrono::duration_cast<std::chrono::nanoseconds>(clock_end2-clock_start2);

            }
            suma/10;
			file << suma.count() << std::endl;
		}
}
} // namespace

int main()
{
    srand(time(NULL));
    std::ofstream file;




    file.open("testDeleting.txt");
    //file << "Test of Deleting\nlp\tHash\tTree\n";
	perfomTestDelete(file);
    file.close();

    file.open("testAppend.txt");
   // file << "Test of Appending\nlp\tHash\tTree\n";
    perfomTestAppend(file);
    file.close();


  return 0;
}
