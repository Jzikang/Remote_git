#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool is_huiwen(string s) {
    if (s.size() == 1) return true;
    int i = 0, j = s.size() - 1;
    while(i <= j) {
        if (s[i] != s[j]) return false;
        i++;
        j--;
    }
    return true;
}

bool Success = false;

void resort(string s, int k) {
    if (is_huiwen(s)) {
        Success = true;
        //cout << s << endl;
    }
    for (int i = k; i < s.size(); i++) {
        if (Success) return;
        string cache, cache1;
        resort(s, k + 1);
        if (s[k] == 'm') {
            for (int j = 0; j < s.size(); j++) {
                if (j == k) {
                    cache.push_back('n');
                    cache.push_back('n');
                } else {
                    cache.push_back(s[j]);
                }
            }
            resort(cache, k);
        } else if (s[k] == 'w') {
            for (int j = 0; j < s.size(); j++) {
                if (j == k) {
                    cache.push_back('v');
                    cache.push_back('v');
                } else {
                    cache.push_back(s[j]);
                }
            }
            resort(cache, k + 2);
        } else if (s[k] == 'b') {
            for (int j = 0; j < s.size(); j++) {
                if (j == k) {
                    cache.push_back('d');
                    cache1.push_back('q');
                } else {
                    cache.push_back(s[j]);
                    cache1.push_back(s[j]);
                }
            }
            resort(cache, k + 1);
            resort(cache1, k + 1);
        } else if (s[k] == 'p') {
            for (int j = 0; j < s.size(); j++) {
                if (j == k) {
                    cache.push_back('q');
                    cache1.push_back('d');
                } else {
                    cache.push_back(s[j]);
                    cache1.push_back(s[j]);
                }
            }
            resort(cache, k + 1);
            resort(cache1, k + 1);
        } else if (s[k] == 'd') {
            for (int j = 0; j < s.size(); j++) {
                if (j == k) {
                    cache.push_back('p');
                    cache1.push_back('b');
                } else {
                    cache.push_back(s[j]);
                    cache1.push_back(s[j]);
                }
            }
            resort(cache, k + 1);
            resort(cache1, k + 1);
        } else if (s[k] == 'n') {
            for (int j = 0; j < s.size(); j++) {
                if (j == k) {
                    cache.push_back('u');
                } else {
                    cache.push_back(s[j]);
                }
            }
            resort(cache, k + 1);
        } else if (s[k] == 'u') {
            for (int j = 0; j < s.size(); j++) {
                if (j == k) {
                    cache.push_back('n');
                } else {
                    cache.push_back(s[j]);
                }
            }
            resort(cache, k + 1);
        }
        if (Success) return;
    }
}


int main(){
    int n; 
    cin >> n;
    vector<string> strs;
    string str;
    for (int i = 0; i < n; i++) {
        cin >> str;
        strs.push_back(str);
    }
    for (int i = 0; i < n; i++) {
        if (strs[i].empty()) {
            cout << "NO" << endl;
        }
        if (is_huiwen(strs[i])) {
            cout << "YES" << endl;
            continue;
        }
        resort(strs[i], 0);
        if(Success) {
            cout << "YES" << endl;
            Success = false;
        }
        else cout << "NO" << endl;
    }
}