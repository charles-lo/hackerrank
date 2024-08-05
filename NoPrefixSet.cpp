#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

// create the Trie data Structure 
struct trie {
    map<char, trie*> children;
};

// implement a boolean function to check if prefix is present
bool isPreInsert(trie* t, string& str) {
    trie* cur = t;
    string prefix = "";
    
    for (int i = 0; i < str.size(); ++i) {
        prefix += str[i];
        if (cur->children['$']) {
            return false;
        }
        if (!cur->children[str[i]]) {
            cur->children[str[i]] = new trie;
        }
        cur = cur->children[str[i]];
    }
    if (cur->children.size() > 0) {
        return false;
    }
    
    cur->children['$'] = new trie;
    return true;
}

/*
 * Complete the 'noPrefix' function below.
 *
 * The function accepts STRING_ARRAY words as parameter.
 */

void noPrefix(vector<string> words) {
    trie* dictionary = new trie;
    
    for (int i = 0; i < words.size(); ++i) {
        if (!isPreInsert(dictionary, words[i])) {
            cout << "BAD SET" << endl << words[i];
            return;
        }
    }
    
    cout << "GOOD SET";
    return;
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<string> words(n);

    for (int i = 0; i < n; i++) {
        string words_item;
        getline(cin, words_item);

        words[i] = words_item;
    }

    noPrefix(words);

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
