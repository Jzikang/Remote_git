#include <iostream>
#include <cstdio>
#define ll long long
using namespace std;
const int maxn = 2e5+10;

string s;

bool check(int l, int r) {
    if (s[l] == 'o' && s[l+1] == 'p' && s[l+2] == 'p' && s[l+3] == 'o') return true;
    return false;
}

int main() {
    cin >> s;
    int len = s.length();
    ll res = 0;
    for (int i = 0, j = i+3; j < len; i++, j++) {
        if (check(i, j)) {
            res += 1ll*(i+1)*(len-j);
        }  
    }
    cout << res << "\n";
}