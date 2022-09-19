class Node {
 public:
    std::array<Node*, 26> links;
    bool end;
    void insert(char ch, Node* node) {
        links[ch - 'a'] = node;
    }
    Node* get(char ch) {
        return links[ch - 'a'];
    }
    bool contains(char ch) {
        return links[ch - 'a'] != nullptr;
    }
    void setEnd() {
        end = true;
    }
    bool isEnd() {
        return end;
    }
};
class WordDictionary {
private:
    Node* root;
public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* node = root;
        for (char ch : word) {
            if(!node->contains(ch)) {
                node->insert(ch, new Node());
            }
            node = node->get(ch);
        }
        node->setEnd();
    }
    bool dfs(string& word, Node* node, int index, int count) {
        if (count > 3)
            return false;
        if (index == word.length())
            return node->isEnd();
        int ret {};
        if (!isalpha(word[index])) {
            for (int i = 0; i < 26; i++) {
                if (node->links[i] != nullptr &&
                    dfs(word, node->links[i], index + 1, count + 1)) {
                    return true;
                }
            }
        } else {
            return node->contains(word[index]) && dfs(word, node->get(word[index]), index+1, count);
        }
        return ret;
    }
    bool search(string word) {
        return dfs(word, root, 0, 0);
    }
};