#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ll ans = 0;
    ifstream input("Day 5/main.in");
    vector<pair<ll, ll>> v;
    vector<pair<ll, ll>> fin;
    string s;

    while (std::getline(input, s) && s.size() != 0) {
        stringstream ss(s);
        string start; getline(ss, start, '-');
        string end; getline(ss, end, '-');
        v.push_back({stoll(start), stoll(end)});
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < v.size() - 1; i++) {
        if (v[i].second < v[i + 1].first) fin.push_back(v[i]);
        else v[i + 1] = {v[i].first, max(v[i].second, v[i + 1].second)};
    }

    fin.push_back(v.back());

    for (auto [x, y] : fin) {
        ans += (y - x + 1);
    }

    cout << ans << endl;
}