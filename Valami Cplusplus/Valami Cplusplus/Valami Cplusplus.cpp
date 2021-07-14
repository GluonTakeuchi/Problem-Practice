// Valami Cplusplus.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <list>
#include <iterator>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int Randomizer(int range) {

    int result;
    
    result = rand() % range;

    return result;
}
int main()
{

    int range;
    /*Range valasztas, most legyen fixen 9
    std::cin >> range;
    */
    range = 9;

    std::list<int> list = { };
    int r;
    bool doit = false;
    bool endlist = false;
    bool mistake = false;
    std::list<int> mysoulution = { };
    int answer;
    std::list<int>::iterator list_it;
    std::list<int>::iterator mys_it;
    
    srand(time(NULL));
      //jatek ciklus
        while (!mistake) {           
            //random elem a listaba
            r = Randomizer(range);
            list.push_back(r);
            std::cout << "New element: " ;
            std::cout << r << std::endl;         
            std::cout << "Give me the sequence: " << std::endl;
                for (int i = 0; i < list.size(); i++)
                {
                    
                    std::cin >> answer;                    
                    mysoulution.push_back(answer);
                    
                }                
                std::cout << std::endl;

                for (list_it = list.begin(); list_it != list.end();)
                {
                    mys_it = mysoulution.begin();
                    if (*list_it == *mys_it) {

                        ++list_it;
                        mysoulution.pop_front();
                    }
                    else {
                        mistake = true;
                        break;
                    }                        
                }                
         }            

    int your_score = (list.size() - 1);

    std::cout << "GAME OVER!\n";
    std::cout << "Your Score:" << your_score;
    std::cout << std::endl;

    int high_score;

    string line;
    ifstream myfile("example.txt");
    if (myfile.is_open())
    {
        getline(myfile, line);        
        myfile.close();
        high_score = std::stoi(line);

        if (your_score > high_score)
        {
            high_score = your_score;
            ofstream myfile("example.txt");
            if (myfile.is_open())
            {
                myfile << your_score;
                
                myfile.close();
            }
            else cout << "Unable to open file";
        }
       
        myfile.close();
    }

    else cout << "Unable to open file";
    std::cout << "High Score:" << high_score << std::endl;    
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
