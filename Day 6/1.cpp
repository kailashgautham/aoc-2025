#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ll ans = 0;
    ifstream input("Day 6/test.in");
    vector<vector<ll>> all;
    vector<char> ops;
    string s;

    while (std::getline(input, s)) {
        string tmp = "";
        stringstream ss(s);
        vector<ll> v;
        string start;
        while (ss >> start) {
            try {
                v.push_back(stoll(start));
            } catch (exception e) {
                ops.push_back(start[0]);
            }
        }
        if (v.size() > 0)
            all.push_back(v);
    }

    for (int i = 0; i < ops.size(); i++) {
        ll start = ops[i] == '*' ? 1 : 0;
        for (int j = 0; j < all.size(); j++) {
            if (ops[i] == '*') start *= all[j][i];
            else start += all[j][i];
        }
        ans += start;
    }
    cout << ans << endl;
}