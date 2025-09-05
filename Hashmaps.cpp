#include<iostream>
#include<map>
#include<unordered_map>

using namespace std;

int main() {
    //creation
    unordered_map<string, int> m;

    //insertion
    pair<string, int> p = make_pair("babbar", 3);
    m.insert(p);

    pair<string, int> pair2("love", 2);
    m.insert(pair2);

    m["mera"] = 1;

    m["mera"] = 2;

    // search

    cout << m["mera"] << endl;
    cout << m["babbar"] << endl;

    return 0;

}