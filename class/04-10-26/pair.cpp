#include <bits/stdc++.h>
using namespace std;

int main() {

    pair<int, string> p = {2, "CSE"};
    cout << p.first << " " << p.second << endl;

    // re-assign
    p.first = 3;
    p.second = "EEE";
    cout << p.first << " " << p.second << endl;
}