#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
struct Node {
    string name;
    Node* child;
    Node* bro;
};
long unsigned int cal(string str) {
    long unsigned int count = 0;
    for(long unsigned int i = 0; i < str.size(); i++) {
        if (str[i] == '-') {
            count++;
        } else {
            break;
        }
    }
    return count;
}
Node* build(vector<string> contents) {
    if (contents.size() == 0) return NULL;
    long unsigned int level = cal(contents[0]);
    string con;
    for (int i = 0; i < contents[0].size(); i++) {
        if (contents[0][i] == '-') {
            continue;
        }
        con.push_back(contents[0][i]);
    }
    Node* root = new Node();
    root->name = con;
    root->bro = NULL;
    root->child = NULL;
    Node* res = root;
    if (contents.size() == 1) return root;
    vector<string> content;
    long unsigned int i = 1;
    for (; i < contents.size(); i++) {
        if (cal(contents[i]) != level){
            content.push_back(contents[i]);
        } else {
            root->child = build(content);
            content.clear();
            break;
        }
        if (i == contents.size() - 1){
            root->child = build(content);
            content.clear();
        }  
    }
    for (long unsigned int j = i; j < contents.size(); ) {
        content.push_back(contents[j]);
        j++;
        if (contents[j-1][contents[j-1].size()-1] == '/') {
            while(j < contents.size() && cal(contents[j]) != level){
                content.push_back(contents[j]);
                j++;
            }
        }
        root->bro = build(content);
        root = root->bro;
        content.clear();
    }
    return res;
}
bool cmp(string s, string t) {
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == t[0]) {
        int j = i;
        for (; j < i + t.size(); j++) {
            if (s[j] != t[j-i]) break;
        }
        if (j == i + t.size()) {
            return true;
        }
        }
    }
    return false;
}
vector<string> search(Node* root, string key, string str) {
    vector<string> res;
    if (!root) return res;
    string str_ = str;
    if (cmp(root->name, key)) {
        str_ += root->name;
        res.push_back(str_);
    }
    vector<string> bro = search(root->bro, key, str);
    for (int i = 0; i < bro.size(); i++) {
        res.push_back(bro[i]);
    }
    vector<string> child = search(root->child, key, str+root->name);
    for (int i = 0; i < child.size(); i++) {
        res.push_back(child[i]);
    }
    return res;
}


int main() {
    string keyword, str = "/";
    cin >> keyword; // 读取关键字
    long unsigned int count = 0;
    cin >> count;
    vector<std::string> contents; // 每行的数据
    for(long unsigned int i = 0;i<count;++i){
        string tmp;
        cin >> tmp;
        contents.push_back(tmp);
    }
    Node* root = new Node();
    root->name = contents[0];
    root->bro = NULL;
    contents.erase(contents.begin());
    root->child = build(contents);
    vector<string> res = search(root, keyword, str);
    if (res.size() == 0) {
        cout << "NO such file!" << endl;
    }
    for (int i = 0; i < res.size(); i++) {
      cout << res[i] << endl;
    }
    return 0;
}
