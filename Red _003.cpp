#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    if (n==1) return 1;
    unordered_map<string, int> hash;
    set<string> record;
    string s;
    int res = 0;
    for (int i = 0; i < n; i++) {
        cin >> s;
        if (i == 0) {
            record.insert(s);
            res++;
            continue;
        }
        if (record.find(s) == record.end())
            hash[s]++;
        else continue;
        if (hash[s] == res + 1) {
            record.insert(s);
            res++;
        }
    }
    cout << res << endl;
    return res;
}