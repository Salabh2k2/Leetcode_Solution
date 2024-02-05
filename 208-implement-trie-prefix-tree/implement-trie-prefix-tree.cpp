#include <string>
using namespace std;

struct Node {
    Node* links[26];
    bool flag = false;
    
    bool containskey(char c) {
        return (links[c - 'a'] != NULL);
    }
    
    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }
    
    Node* get(char ch) {
        return links[ch - 'a'];
    }
    
    void setend() {
        flag = true;
    }
    
    bool isend() {
        return flag;
    }
};

class Trie {
private:
    Node* root;
    
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        for(int i = 0; i < word.size(); i++) {
            char ch = word[i];
            if(!(node->containskey(ch))) {
                node->put(ch, new Node());
            }
            node = node->get(ch); // Move to the next node
        }
        node->setend(); // Set the end flag for the last node
    }
    
    bool search(string word) {
        Node* node = root;
        for(int i = 0; i < word.size(); i++) {
            char ch = word[i];
            if(!(node->containskey(ch))) {
                return false;
            }
            node = node->get(ch);
        }
        return node->isend();
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        for(int i = 0; i < prefix.size(); i++) {
            char ch = prefix[i];
            if(!(node->containskey(ch))) {
                return false;
            }
            node = node->get(ch);
        }
        return true;
    }
};
