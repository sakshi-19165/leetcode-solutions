class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> ans;

        int m = mat.size();
        int n = mat[0].size();

        for (int d = 0; d < m + n - 1; d++) {

            vector<int> diagonal;

            int row, col;

            // Starting point of the diagonal
            if (d < n) {
                row = 0;
                col = d;
            }
            else {
                row = d - n + 1;
                col = n - 1;
            }

            // Traverse diagonal
            while (row < m && col >= 0) {
                diagonal.push_back(mat[row][col]);
                row++;
                col--;
            }

            // Reverse alternate diagonals
            if (d % 2 == 0) {
                reverse(diagonal.begin(), diagonal.end());
            }

            // Add diagonal to answer
            for (int x : diagonal) {
                ans.push_back(x);
            }
        }

        return ans;
    }
};