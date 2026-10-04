#include <bits/stdc++.h>
using namespace std;

int main() {

    vector<pair<int, string>> v = {
        {1, "CSE"},
        {2, "EEE"},
        {3, "Civil"}
    };

    for(auto& i:v){
        cout << i.first << " " << i.second << endl;
    }
}