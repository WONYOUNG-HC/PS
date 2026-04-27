#include <iostream>
#include <vector>
#include <map>

using namespace std;

int n;
vector<string> directory;

struct Trie {
    map<string, Trie *> children;

    void add(vector<string> words, int idx = 0) {
        if (words.size() == idx) {
            return;
        }

        auto child = children.find(words[idx]);

        if (child == children.end()) {
            child = children.insert({ words[idx], new Trie() }).first;
        }

        (*child).second->add(words, idx + 1);
    }

    void print(int depth = 0) {
        for (auto pr : children) {
            for (int i = 0; i < depth; i++) {
                cout << " ";
            }

            cout << pr.first << '\n';

            pr.second->print(depth + 1);
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    directory.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> directory[i];
    }

    Trie *trie = new Trie();

    for (int i = 0; i < n; i++) {
        vector<string> words;

        string word = "";
        for (int j = 0; j <= directory[i].size(); j++) {
            if (directory[i][j] == '\\' || j == directory[i].size()) {
                words.push_back(word);
                word = "";
            } else {
                word += directory[i][j];
            }
        }

        trie->add(words);
    }

    trie->print();
}