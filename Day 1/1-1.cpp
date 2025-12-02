#include <bits/stdc++.h>

using namespace std;

int main()
{
    int ans = 0;
    int curr = 50;
    std::ifstream input("1.in");
    string s;
    while (std::getline(input, s))
    {
        int dir = s[0] == 'L' ? -1 : 1;
        int rotations = stoi(s.substr(1));
        rotations = (rotations % 100) * dir;
        if (rotations != 0)
        {
            curr += rotations;
            if (curr < 0)
                curr = 100 + curr;
            curr %= 100;
            if (curr == 0) ans++;
        }
    }
    cout << ans << endl;
}