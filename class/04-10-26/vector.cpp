#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    vector<int> v = {10, 20, 30, 40};
    
    // insertion in vector v
    // v.push_back(100);
    // v.insert(v.begin()+2, 200);

    //deletion in vector v
    v.erase(find(v.begin(), v.end(), 20));
    v.pop_back();

    for(int x: v) {
        cout << x << " ";
    }
    cout << endl;
    // cout << v[2];


    // vector empty check
    if(v.empty()){
        cout << "vector is empty" << endl;
    }
    else {
        cout << "vector is not empty" << endl;
    }


    cout << "size of vector: " << v.size() << endl;
}

