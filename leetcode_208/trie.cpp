#include <iostream>
#include <vector>

using std::string;
using std::vector;

struct node {
    bool is_leaf;
    vector<node*> *tab;
    node(bool is = false): is_leaf(is) {
        tab = new vector<node*>(26, nullptr);
    }
    ~node() {
        for (auto x: *tab) {
            if (nullptr != x) delete x;
        }
        delete tab;
    }
};

class Trie {
public:
    node *root;
    /** Initialize your data structure here. */
    Trie(): root(nullptr) {}

    node* insertAux(string& word, int idx, node *cur) {
        if (idx > word.length()) return nullptr;
        if (nullptr == cur) cur = new node();

        if (idx == word.length()) cur->is_leaf = true;
        else { (*(cur->tab))[int(word[idx] - 'a')] = insertAux(word, idx + 1, (*(cur->tab))[int(word[idx] - 'a')]); }

        return cur;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        root = insertAux(word, 0, root);
    }
    
    node *searchAux(string word, int idx, node *cur) {
        if (nullptr == cur) return nullptr;
        if (idx > word.length()) return nullptr;
        if (idx == word.length()) return cur;
        if (nullptr == (*(cur->tab))[int(word[idx] - 'a')]) return nullptr;
        return searchAux(word, idx + 1, (*(cur->tab))[int(word[idx] - 'a')]);
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        auto x = searchAux(word, 0, root);
        if (nullptr == x) return false;
        return x->is_leaf;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        auto x = searchAux(prefix, 0, root);
        return x != nullptr;

    }

    /** Destroy trie. */
    ~Trie() {
        if (nullptr != root) delete root;
    }
};

int main(int argc, char **argv) {
    Trie t;
    std::cout << "insert<<<<<<<<<<<<<<<<<<<<<<<<<<<" << std::endl;
    std::cout << "apple bear app" << std::endl;
    t.insert("apple");
    t.insert("bear");
    t.insert("app");

    std::cout << "search<<<<<<<<<<<<<<<<<<<<<<<<<<<" << std::endl;
    std::cout << "apple: " << t.search("apple") << std::endl;
    std::cout << "bear: " << t.search("bear") << std::endl;
    std::cout << "app: " << t.search("app") << std::endl;
    std::cout << "apps: " << t.search("apps") << std::endl;
    std::cout << "appl: " << t.search("appl") << std::endl;

    std::cout << "startWith<<<<<<<<<<<<<<<<<<<<<<<<" << std::endl;
    std::cout << "apq: " << t.startsWith("apq") << std::endl;
    std::cout << "appl: " << t.startsWith("appl") << std::endl;
    std::cout << "apple: " << t.startsWith("apple") << std::endl;
    std::cout << "bea: " << t.startsWith("bea") << std::endl;
    std::cout << "cat: " << t.startsWith("cat") << std::endl;
    return 0;
}