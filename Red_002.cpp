#include<iostream>
#include<bits/stdc++.h>
using namespace std;
long long res = 0;

void cal(vector<long> &nums, vector<long> &base, long long dis){
    cout << dis << endl;
    // for (int i = 0; i < nums.size(); i++) {
    //     cout << nums[i] << " ";
    // }
    // cout << endl;
    if (dis < 0) return;
    if (nums.size() == 1) {
        if (base[0] + dis != nums[0]) res++;
        return;
    }
    if (dis == 0) {
        res++;
        return;
    } 
    if (dis == 1) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != base[i] + 1) res++;
        }
        return;
    }
    long long rec1 = nums.front(), rec2 = base.front();
    nums.erase(nums.begin());
    base.erase(base.begin());
    for (int i = 0; i <= dis; i++) {
        //cout << "here" << rec1 << " " << rec2 << endl;
        if (i + rec2 != rec1) 
            cal(nums, base, dis - i);
    }
}

int main(){
    int n;
    cin >> n;
    vector<long> nums, base;
    long long num;
    long long sum = 0, cache = 0;
    for (int i = 0; i < n; i++) {
        cin >> num;
        nums.push_back(num);
        sum += num;
        if (num != 1) {
            cache++;
            base.push_back(1);
        }
        else {
            cache += 2;
            base.push_back(2);
        }
    }
    cal(nums, base, sum - cache);
    cout << res % 1000000007 << endl;
}