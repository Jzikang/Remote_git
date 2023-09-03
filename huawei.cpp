#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n = 10;
    vector<int> need = {40,50,80,10,30,80,90,30,70,150}, cache1, cache2;
    vector<vector<int>> dep, cache;
    unordered_map<int, vector<int>> hash;
    int res = 0;
    dep.push_back({0,0,0,0,0,0,0,0,0,0});
    dep.push_back({1,0,0,0,0,0,0,0,0,0});
    dep.push_back({0,1,0,0,0,0,0,0,0,0});
    dep.push_back({0,1,0,0,0,0,0,0,0,0});
    dep.push_back({0,1,0,0,0,0,0,0,0,0});
    dep.push_back({0,0,1,1,0,0,0,0,0,0});
    dep.push_back({0,0,0,0,1,0,0,0,0,0});
    dep.push_back({0,0,0,0,0,1,1,0,0,0});
    dep.push_back({0,0,0,0,0,1,0,0,0,0});
    dep.push_back({0,0,0,0,0,0,0,1,1,0});
    for (int i = 0; i < n; i++) {
        vector<int> rec;
        for (int j = 0; j < n; j++) {
            if (dep[i][j] == 1) {
                rec.push_back(j);
                //hash[i].push_back(j);
            }            
        }
        if (rec.empty()) cache1.push_back(i);
        else {
            cache2.push_back(i);
            hash.insert({i, rec});
        }
        rec.clear();
    }
    //cout << cache1.size() << endl;
    cache.push_back(cache1);
    cache1.clear();
    
    for (int k = 0; k < cache.size(); k++) {
        for (int i = 0; i < cache[k].size(); i++){
            int len = cache2.size();
            vector<int> cache2_ = cache2;
            for (int j = 0; j < len; j++) {
                auto it = find(hash[cache2_[j]].begin(), hash[cache2_[j]].end(), cache[k][i]);
                if (!hash[cache2_[j]].empty() && it != hash[cache2_[j]].end()) hash[cache2_[j]].erase(it);
                if (hash[cache2_[j]].empty()) {
                    cache1.push_back(cache2_[j]);
                    auto it_ = find(cache2.begin(), cache2.end(), cache2_[j]);
                    cache2.erase(it_);
                }
            }
        }
        if (cache2.empty() || cache1.empty()) break;
        //cout << k << " " << cache1.size() << endl;
        cache.push_back(cache1);
        cache1.clear();
    }
    for (int i = 0; i < cache.size(); i++) {
        int mid_res = 0;
        for (int j = 0; j < cache[i].size(); j++){
            mid_res += need[cache[i][j]];
        }
        res = max(res, mid_res);
    }
    cout << res << endl;

}