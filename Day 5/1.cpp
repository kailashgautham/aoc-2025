#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ll ans = 0;
    ifstream input("Day 5/main.in");
    vector<pair<ll, ll>> v;
    string s;

    while (std::getline(input, s) && s.size() != 0) {
        stringstream ss(s);
        string start; getline(ss, start, '-');
        string end; getline(ss, end, '-');
        v.push_back({stoll(start), stoll(end)});
    }

    while (std::getline(input, s)) {
        bool fresh = false;
        for (auto [start, end] : v) {
            if (stoll(s) >= start && stoll(s) <= end) {
                fresh = true;
                ans++;
                break;
            }
        }
    }
    cout << ans << endl;
}