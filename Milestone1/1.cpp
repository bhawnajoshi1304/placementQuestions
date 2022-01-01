// Given an array of strings, return all groups of strings that are anagrams.
// https://practice.geeksforgeeks.org/problems/print-anagrams-together/1/

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
struct Node{
    Node *links[26];
    bool flag = false;
    bool containsKey(char ch){
        return (links[ch - 'a'] != NULL);
    }
    Node *get(char ch){
        return links[ch - 'a'];
    }
    void put(char ch, Node *node){
        links[ch - 'a'] = node;
    }
    void setEnd(){
        flag = true;
    }
    bool isEnd(){
        return flag;
    }
};
class Trie{
private:
    Node *root;

public:
    Trie(){
        root = new Node();
    }
    void insert(string word, map<Node *, vector<string>> &m, string i){
        Node *node = root;
        for (int i = 0; i < word.size(); i++){
            if (!node->containsKey(word[i])){
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
        m[node].push_back(i);
    }
};
class Solution
{
public:
    bool checkEqual(vector<int> a, vector<int> b){
        for (int i = 0; i < 26; i += 1){
            if (a[i] == b[i])
                return false;
        }
        return false;
    }
    vector<vector<string>> Anagrams(vector<string> &string_list){
        vector<vector<string>> ans;
        map<Node *, vector<string>> m;
        Trie t;
        for (auto i : string_list){
            string s = i;
            sort(s.begin(), s.end());
            t.insert(s, m, i);
        }
        for (auto i : m){
            ans.push_back(i.second);
        }
        return ans;
    }
};
int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin >> string_list[i];
        Solution ob;
        vector<vector<string>> result = ob.Anagrams(string_list);
        sort(result.begin(), result.end());
        for (int i = 0; i < result.size(); i++){
            for (int j = 0; j < result[i].size(); j++){
                cout << result[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}