/*
https://binarysearch.com/problems/Largest-One-Submatrix-with-Column-Swaps

*/


int solve(vector<vector<int>>& matrix) {
    
  int n = matrix.size(), m = matrix[0].size(), ret = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j]) matrix[i][j] += matrix[i - 1][j];
        }
    }
    for (auto& row : matrix) sort(row.begin(), row.end());
    for (int i = 0; i < n; i++) {
        for (int j = m - 1; j >= 0; j--) {
            ret = max(ret, matrix[i][j] * (m - j));
        }
    }
    return ret;

}