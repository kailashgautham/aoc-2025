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

    unordered_set<int> beam_cols;
    for (int i = 0; i < all[0].size(); ++i) {
        if (all[0][i] == 'S') {
            beam_cols.insert(i);
            break;
        }
    }

    for (int i = 1; i < all.size(); ++i) {
        unordered_set<int> beam_cols_new;
        for (int j : beam_cols) {
            if (all[i][j] == '^') {
                ans++;
                if (j > 0) beam_cols_new.insert(j - 1);
                if (j < all.size() - 1) beam_cols_new.insert(j + 1);
            } else beam_cols_new.insert(j);
        }
        swap(beam_cols_new, beam_cols);
    }
    cout << ans << endl;
}