#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << endl; cout << "\n";

int main() {
    ll ans = 0;
    ifstream input("Day 6/main.in");
    vector<string> all;
    vector<char> ops;
    string s;

    ll max_line_size = 0;

    while (std::getline(input, s)) {
        if (s.front() == '*') break;
        max_line_size = max(max_line_size, (ll)s.size());
        all.push_back(s);
    }

    for (int i = 0; i < s.size(); i++) {
        bool is_multiplier = s[i] == '*';
        ll start = is_multiplier;
        do {
            string num = "";
            for (string j : all)
                if (i < j.size() && j[i] != ' ') num += j[i];
            if (num.empty()) break;
            if (is_multiplier) start *= stoll(num);
            else start += stoll(num);
            i++;
        } while (i < max_line_size && (i >= s.size() || s[i] == ' '));
        ans += start;
    }
    cout << ans << endl;
}