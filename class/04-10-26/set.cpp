#include <bits/stdc++.h>
using namespace std;

int main() {

    set<int> s1 = {1, 2, 3, 1, 3, 4};
    for(auto& x: s1) {
        // auto is an iterator, detects data type automatically
        // prints unique values in s1 in order asc
        cout<< x << endl;
    }

    cout << "size of set: " << s1.size() << endl;

    //insert
    s1.insert(-100);

    // check if 4 exists in the set
    cout << s1.count(5) << endl;


        
        
}