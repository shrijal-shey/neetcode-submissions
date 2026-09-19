#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> rows[9];
        unordered_set<char> cols[9];
        unordered_set<char> squares[3][3];

        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                char val = board[r][c];

                if (val == '.') {
                    continue;
                }

                if (rows[r].count(val) ||
                    cols[c].count(val) ||
                    squares[r / 3][c / 3].count(val)) {
                    return false;
                }

                rows[r].insert(val);
                cols[c].insert(val);
                squares[r / 3][c / 3].insert(val);
            }
        }

        return true;
    }
};