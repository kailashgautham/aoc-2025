#include <bits/stdc++.h>
#define ll long long
#define ld long double

using namespace std;

struct coord {
    ll x, y, z;
};

vector<coord> coords;

struct union_find {
    union_find(vector<coord> coords) : coords_(coords), parent_(coords.size()), size_(coords.size(), 1), connected_(coords.size()) {
        for (ll i = 0; i < coords.size(); i++) parent_[i] = i;
    }

    ll find(ll i) {
        if (parent_[i] == i) return i;
        parent_[i] = find(parent_[i]);
        return parent_[i];
    }

    void join(ll x, ll y) {
        ll root_x = find(x);
        ll root_y = find(y);
        if (root_x == root_y) return;
        connected_--;
        if (size_[root_x] < size_[root_y]) {
            parent_[root_x] = root_y;
            size_[root_y] += size_[root_x];
        } else {
            parent_[root_y] = root_x;
            size_[root_x] += size_[root_y];
        }
    }

    ll return_product() {
        for (int i = 0; i < coords_.size(); i++) {
            if (parent_[i] == i) size_queue_.push(size_[i]);
        }
        ll ans = 1;
        for (int i = 0; i < 3; i++) {
            ans *= size_queue_.top();
            size_queue_.pop();
        }
        return ans;
    }

    vector<coord> coords_;
    vector<ll> parent_;
    vector<ll> size_;
    priority_queue<ll, vector<ll>> size_queue_;
    ll connected_;
};

int main() {
    ifstream input("Day 8/main.in");
    vector<string> all;
    string s;

    while (std::getline(input, s)) {
        stringstream ss(s);
        coord c;
        string t;
        getline(ss, t, ','); c.x = stoll(t); getline(ss, t, ','); c.y = stoll(t); getline(ss, t, ','); c.z = stoll(t);
        coords.push_back(c);
    }

    union_find uf(coords);

    vector<pair<ld, pair<ll, ll>>> distances;

    for (ll i = 0; i < coords.size(); i++) {
        for (ll j = i + 1; j < coords.size(); j++) {
            ld distance = sqrt(pow(coords[i].x - coords[j].x, 2) + pow(coords[i].y - coords[j].y, 2) + pow(coords[i].z - coords[j].z, 2));
            distances.push_back({distance, {i, j}});
        }
    }

    sort(distances.begin(), distances.end());

    for (ll i = 0; i < distances.size(); ++i) {
        auto [distance, idxes] = distances[i];
        auto [x, y] = idxes;
        uf.join(x, y);
        if (uf.connected_ == 1) {
            cout << coords[x].x * coords[y].x << endl;
            break;
        }
    }

}

