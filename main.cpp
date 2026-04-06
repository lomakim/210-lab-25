#include <iostream>
#include <chrono>
#include <fstream>
#include <vector>
#include <list>
#include <set>
#include <algorithm>
using namespace std;
using namespace std::chrono;

int main() {
    ifstream fin("codes.txt");
    vector<string> vec;
    list<string> list;
    set<string> set;
    string temp;

    //READING FILE
    auto start = high_resolution_clock::now();
    while (fin >> temp) {
        vec.push_back(temp);
    }
    auto end = high_resolution_clock::now();
    auto vRead = duration_cast<milliseconds>(end - start);

    start = high_resolution_clock::now();
    while (fin >> temp) {
        list.push_back(temp);
    }
    end = high_resolution_clock::now();
    auto lRead = duration_cast<milliseconds>(end - start);
    
    start = high_resolution_clock::now();
    while (fin >> temp) {
        set.insert(temp);
    }
    end = high_resolution_clock::now();
    auto sRead = duration_cast<milliseconds>(end - start);

    fin.close();

    //SORTING FILE
    start = high_resolution_clock::now();
    sort(vec.begin(), vec.end());
    end = high_resolution_clock::now();
    auto vSort = duration_cast<milliseconds>(end - start);

    start = high_resolution_clock::now();
    list.sort();
    end = high_resolution_clock::now();
    auto lSort = duration_cast<milliseconds>(end - start);

    auto sSort = -1;


    //INSERTING
    string t = "TESTCODE";

    start = high_resolution_clock::now();
    vec.insert(vec.begin() + (vec.size() / 2), t);
    end = high_resolution_clock::now();
    auto vIns = duration_cast<milliseconds>(end - start);
    
    start = high_resolution_clock::now();
    auto it = list.begin();
    advance(it, (list.size() / 2));
    list.insert(it, t);
    end = high_resolution_clock::now();
    auto lIns = duration_cast<milliseconds>(end - start);

    start = high_resolution_clock::now();
    set.insert(t);
    end = high_resolution_clock::now();
    auto sIns = duration_cast<milliseconds>(end - start);

    //DELETING
    start = high_resolution_clock::now();
    vec.erase(vec.begin() + (vec.size() / 2));
    end = high_resolution_clock::now();
    auto vDel = duration_cast<milliseconds>(end - start);


    start = high_resolution_clock::now();
    
    end = high_resolution_clock::now();
    duration_cast<milliseconds>(end - start);

    start = high_resolution_clock::now();
    
    end = high_resolution_clock::now();
    duration_cast<milliseconds>(end - start);




    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/