// Implementation of Hashmaps

#include<iostream>
#include<map>
#include<unordered_map>

using namespace std;

int main() {
    //creation
    unordered_map<string, int> m;

    //insertion
    pair<string, int> p = make_pair("Hello", 3);
    m.insert(p);

    pair<string, int> pair2("CodingWorld", 2);
    m.insert(pair2);

    m["Code"] = 1;
    m["Code"] = 2;

    // search
    cout << m["Code"] << endl;
    cout << m["Hello"] << endl;
    return 0;
}
