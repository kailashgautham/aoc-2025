#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ll ans = 0;
    ifstream input("Day 7/main.in");
    vector<string> all;
    string s;

    while (std::getline(input, s)) {
        all.push_back(s);
    }

    unordered_map<ll, ll> beam_cols;
    for (ll i = 0; i < all[0].size(); ++i) {
        if (all[0][i] == 'S') {
            beam_cols.emplace(i, 1);
            break;
        }
    }

    for (ll i = 1; i < all.size(); ++i) {
        unordered_map<ll, ll> beam_cols_new;
        for (auto [j, c] : beam_cols) {
            if (all[i][j] == '^') {
                if (j > 0) beam_cols_new[j - 1] += beam_cols[j];
                if (j < all.size() - 1) beam_cols_new[j + 1] += beam_cols[j];
            } else beam_cols_new[j] += c;
        }
        swap(beam_cols_new, beam_cols);
    }

    for (auto [_, c] : beam_cols) ans += c;

    cout << ans << endl;
}