#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ll ans = 0;
    ifstream input("Day 4/main.in");
    vector<string> v;
    string s;
    while (std::getline(input, s)) v.push_back(s);
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            if (v[i][j] == '.') continue;
            int adj = 0;
            if (i > 0 && v[i - 1][j] == '@') adj++;
            if (j > 0 && v[i][j - 1] == '@') adj++;
            if (i < v.size() - 1 && v[i + 1][j] == '@') adj++;
            if (j < v[i].size() - 1 && v[i][j + 1] == '@') adj++;
            if (i > 0 && j > 0 && v[i - 1][j - 1] == '@') adj++;
            if (i < v.size() - 1 && j < v[i].size() - 1 && v[i + 1][j + 1] == '@') adj++;
            if (i > 0 && j < v[i].size() - 1 && v[i - 1][j + 1] == '@') adj++;
            if (i < v.size() - 1 && j > 0 && v[i + 1][j - 1] == '@') adj++;
            if (adj < 4) ans++;
        }
    }
    cout << ans << endl;
}