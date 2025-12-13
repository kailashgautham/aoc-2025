#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ll ans = 0;
    ifstream input("Day 3/3.in");
    string s;
    while (std::getline(input, s)) {
        ll curr_ans = 0;
        int start = 0;
        for (int i = 0; i < 12; i++) {
            int largest = 0, new_start = 0;
            for (int j = start; j < s.size() - (12 - i) + 1; j++) {
                if (s[j] - '0' > largest) {
                    largest = s[j] - '0';
                    new_start = j;
                }
            }
            curr_ans += (largest * pow(10, 12 - i - 1));
            start = new_start + 1;
        }
        ans += curr_ans;
    }
    cout << ans << endl;
}