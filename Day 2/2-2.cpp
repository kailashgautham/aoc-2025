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
        ll end_num = stoll(end);
        string start_num_half;
        if (start.size() % 2 == 1) start_num_half = to_string((ll)(pow(10, start.size() / 2)));
        else if (stoll(start.substr(start.size() / 2)) > stoll(start.substr(0, start.size() / 2)))
            start_num_half = to_string(stoll(start.substr(0, start.size() / 2)) + 1);
        else start_num_half = start.substr(0, start.size() / 2);
        while (true) {
            ll next_num = stoll(start_num_half + start_num_half);
            if (next_num > end_num) break;
            cout << "Adding num: " << next_num << endl;
            ans += next_num;
            start_num_half = to_string(stoll(start_num_half) + 1);
        }
        cout << endl;
    }
    cout << ans << endl;
}