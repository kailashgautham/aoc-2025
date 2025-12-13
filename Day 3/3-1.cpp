#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ll ans = 0;
    ifstream input("Day 3/3.in");
    string s;
    while (std::getline(input, s)) {
        int largest = max(s[0] - '0', s[1] - '0'), second = min(s[0] - '0', s[1] - '0');
        bool can_use_largest = (s[0] - '0') == largest ? true : false;
        for (int i = 2; i < s.length(); i++) {
            if (s[i] - '0' > largest) {
                second = largest;
                largest = (s[i] - '0');
                if (i < s.size() - 1) {second = s[i + 1] - '0'; can_use_largest = true;}
                else can_use_largest = false;
            } else if (s[i] - '0' >= second) {second = s[i] - '0'; can_use_largest = true;}
        }
        int curr;
        if (can_use_largest) curr = (largest * 10 + second);
        else curr = (second * 10 + largest);
        ans += curr;
    }
    cout << ans << endl;
}