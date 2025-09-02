class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        for(int row = 0; row < numRows; row++) {
            vector<int> ansRow;
            long long int ans = 1;
            ansRow.push_back(1);
            
            for(int col = 1; col <= row; col++) {
                ans = ans * (row - col + 1);
                ans = ans / col;
                ansRow.push_back(ans);
            }
            result.push_back(ansRow);
        }
        return result;
    }
};