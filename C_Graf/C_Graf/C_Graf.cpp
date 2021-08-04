// C_Graf.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
using namespace std;

//c stringet torli az s stringbol
string deleteChar(string c, string s) {
  
    string st = c.substr(0, c.size()-1);
    string result;
    size_t found = s.find(st);
    result = s.erase(found,2);
   
    return result;
     
}
//map formatum olvasasa fajlbol
struct kv_pair : public std::pair<std::string, std::string> {
    friend std::istream& operator>>(std::istream& in, kv_pair& p) {
        return in >> std::get<0>(p) >> std::get<1>(p);
    }
};

int main()
{

    //test.txt bol beolvassuk a grafot
    std::ifstream paramFile{ "test.txt" };

    //a graph-ban van a graf
    std::map<std::string, std::string> graph{ std::istream_iterator<kv_pair>{paramFile},
                                              std::istream_iterator<kv_pair>{} };

    //koszonunk
    std::cout << "Hello World!\n";

    //szabalyok
    std::cout << "Graf megadasi szabalyok: txt fajlban elso oszlopban a task neve, masodik oszlopban milyen taskok kellenek a lefutasahoz. A masodik oszlopban minden task utan vesszot kell tenni. Ha egy taskhoz nem kell masik task, akkor azt jeloljuk 0-val es ezesetben ne hasznaljunk vesszot!";
    std::cout << endl;


    //befejezett taskok
    map<string, bool> finished;    
    map<string, bool> taskList;
    int taskN = 0;

    
    for (map<string, string>::iterator it = graph.begin(); it != graph.end(); it++)
    {
        //ha lehetne ures erteket map value-kent olvasni ez nem kene...
        if (it->second == "0")
            it->second = "";

        //az elejen semmi nincs befejezve
        finished.emplace(it->first, false);
        taskList.emplace(it->first, false);
        taskN++;
    }

   //graf fuggosegek kirajzolasa
    for (const auto& p : graph) {
        std::cout << p.first << " => " << p.second << '\n';
    }


    size_t i = 1;
    while(taskN !=0)
    {        
        std::cout << "Melyseg " << i <<": ";
      
        for (auto const& x : graph)
        {
            //ha egy taskhoz megvan mar minden feltetel / ures a feltetel listaja, akkor lefuthat
            if (x.second == "") {
                std::map<string, bool>::iterator it = finished.find(x.first);
                std::map<string, bool>::iterator it2 = taskList.find(x.first);
                it->second = true;

                if (it2->second == false)
                {
                    std::cout << x.first;
                    it2->second = true;
                    taskN--;
                }              
            }
        }      

        for (const auto& p : graph) {
            
            vector<string> result;
            stringstream ss (p.second);
            
            //a map ertek listajanak szetvalasztasa
            //avagy milyen mas taskok kellenek meg az adott taskhoz
            while (ss.good())
            {
                string substr;
                getline(ss, substr, ',' );
                result.push_back(substr);
            }
                        

            for (size_t i = 0; i < result.size() - 1; i++)
            {
                string v = result[i];
                std::map<string, bool>::iterator it = finished.find(result[i]);
               
                //ha minden szukseges task lefutott akkor keszen all a futasra
                if (it->second == true) {
                    string valami = deleteChar(it->first, p.second);
                    std::map<string, string>::iterator it2 = graph.find(p.first);
                    it2->second = valami;
                }
            }

        }
        std::cout << endl;
        i++;
    }


    std::cout << "end";

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
