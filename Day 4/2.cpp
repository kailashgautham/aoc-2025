#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<pair<int, int>> directions {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

vector<string> v;

queue<pair<int, int>> q;

bool valid(int i, int j, int rows, int cols) {
    return i >= 0 && i < rows && j >= 0 && j < cols;
}

void check_adj(int i, int j) {
    if (v[i][j] == '.') return;
    int adj = 0;
    for (auto [x, y] : directions) {
        if (valid(i + x, j + y, v.size(), v[i].size()) && v[i + x][j + y] == '@') adj++;
    }
    if (adj < 4) q.push({i, j});
}

void find_adj(int i, int j) {
    for (auto [x, y] : directions) {
        if (valid(i + x, j + y, v.size(), v[i].size()) && v[i + x][j + y] == '@') check_adj(i + x, j + y);
    }
}

int main() {
    ll ans = 0;
    ifstream input("Day 4/main.in");
    string s;

    while (std::getline(input, s)) v.push_back(s);
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            check_adj(i, j);
        }
    }

    while (!q.empty()) {
        auto [i, j] = q.front(); q.pop();
        if (v[i][j] == 'x') continue;
        v[i][j] = 'x';
        ans++;
        find_adj(i, j);
    }

    cout << ans << endl;
}

