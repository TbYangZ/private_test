#include <bits/stdc++.h>
using namespace std;
vector<int*> vec1;
int main() {
    for (int i = 0; i < 10; ++i) {
        vec1.push_back(new int(i));
    }
    vector<int*> vec2 = vec1;
    for (auto v : vec2) {
        cout << *v << " ";
    }
    cout << endl;
    *vec2[5] = 10;
    for (auto v : vec1) {
        cout << *v << " ";
    }
    cout << endl;
    return 0;
}