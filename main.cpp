#include <iostream>
#include <chrono>
#include <fstream>
#include <vector>
#include <list>
#include <set>
using namespace std;
using namespace std::chrono;

int main() {
    ifstream fin("codes.txt");
    vector<string> vec;
    list<string> list;
    set<string> set;
    string temp;


    auto start = high_resolution_clock::now();
    while (fin >> temp) {
        vec.push_back(temp);
    }
    auto end = high_resolution_clock::now();

    auto vRead = duration_cast<milliseconds>(end - start);

    fin.close();

    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/