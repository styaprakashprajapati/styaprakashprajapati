
class Solution {
public:

    struct TrieNode {
        TrieNode* child[26];
        string word;

        TrieNode() {
            for(int i = 0; i < 26; i++) {
                child[i] = nullptr;
            }

            word = "";
        }
    };

    TrieNode* root = new TrieNode();

    // Insert words into Trie
    void insert(string& word) {

        TrieNode* node = root;

        for(char ch : word) {

            int idx = ch - 'a';

            if(node->child[idx] == nullptr) {
                node->child[idx] = new TrieNode();
            }

            node = node->child[idx];
        }

        node->word = word;
    }

    int rows, cols;

    vector<string> ans;

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    // DFS + Backtracking
    void dfs(vector<vector<char>>& board,
             int x, int y, TrieNode* node) {

        char ch = board[x][y];

        int idx = ch - 'a';

        if(node->child[idx] == nullptr) {
            return;
        }

        TrieNode* next = node->child[idx];

        // Word found
        if(next->word != "") {

            ans.push_back(next->word);

            next->word = "";
        }

        // Mark visited
        board[x][y] = '#';

        // Explore 4 directions
        for(int i = 0; i < 4; i++) {

            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx >= 0 && nx < rows &&
               ny >= 0 && ny < cols &&
               board[nx][ny] != '#') {

                dfs(board, nx, ny, next);
            }
        }

        // Backtracking: Restore original character
        board[x][y] = ch;
    }

    vector<string> findWords(
        vector<vector<char>>& board,
        vector<string>& words) {

        rows = board.size();
        cols = board[0].size();

        // Build Trie
        for(string& word : words) {
            insert(word);
        }

        // Start DFS from every cell
        for(int i = 0; i < rows; i++) {

            for(int j = 0; j < cols; j++) {

                dfs(board, i, j, root);
            }
        }

        return ans;
    }
};
