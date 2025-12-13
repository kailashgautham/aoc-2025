#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ll ans = 0;
    ifstream input("Day 2/2.in");
    string s, t;
    getline(input, s);
    stringstream ss(s);
    while (getline(ss, t, ',')) {
        stringstream sss(t);
        string start; getline(sss, start, '-');
        string end; getline(sss, end, '-');
        ll start_num = stoll(start);
        ll end_num = stoll(end);
        string start_num_half = "1";
        std::unordered_set<ll> unique;
        while (true) {
            string curr = start_num_half + start_num_half;
            if (stoll(curr) > end_num) break;
            while (stoll(curr) < start_num) curr += start_num_half;
            while (stoll(curr) <= end_num) {
                if (!unique.contains(stoll(curr))) {
                    unique.insert(stoll(curr));
                    ans += stoll(curr);
                }
                curr += start_num_half;
            }
            start_num_half = to_string(stoll(start_num_half) + 1);
        }
    }
    cout << ans << endl;
}