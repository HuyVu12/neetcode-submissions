class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int ok[10] = {0};
        int cnt = 0;
        for(int i = 0; i < 9; ++i) {
            cnt += 1;
            for(int j = 0; j < 9; ++j) {
                if(board[i][j] == '.') continue;
                if(ok[board[i][j] - '0'] == cnt) return false;
                ok[board[i][j] - '0'] = cnt;
            }
        }
        for(int j = 0; j < 9; ++j) {
            cnt += 1;
            for(int i = 0; i < 9; ++i) {
                if(board[i][j] == '.') continue;
                if(ok[board[i][j] - '0'] == cnt) return false;
                ok[board[i][j] - '0'] = cnt;
            }
        }
        for(int i1 = 0; i1 < 9; i1 += 3) {
            for(int j1 = 0; j1 < 9; j1 += 3) {
                cnt += 1;
                for(int i = i1; i < i1 + 3; ++i) {
                    for(int j = j1; j < j1 + 3; ++j) {
                        if(board[i][j] == '.') continue;
                        if(ok[board[i][j] - '0'] == cnt) return false;
                        ok[board[i][j] - '0'] = cnt;
                    }
                }
            }
        }
        return true;
    }
};
