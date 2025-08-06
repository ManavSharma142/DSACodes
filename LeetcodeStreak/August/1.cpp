#include<bits/stdc++.h>
//this is iterative solution
class Solution {
public:
    std::vector<std::vector<int>> generate(int numRows) {
        if (numRows == 0) return {};

        std::vector<std::vector<int>> ans;
        ans.push_back({1}); // Add the first row

        // Loop to generate rows from the second row onwards
        for (int i = 1; i < numRows; ++i) {
            const std::vector<int>& prevRow = ans.back();
            std::vector<int> currentRow(i + 1);

            currentRow[0] = 1; // First element is always 1
            
            // Calculate middle elements from the previous row
            for (int j = 1; j < i; ++j) {
                currentRow[j] = prevRow[j - 1] + prevRow[j];
            }

            currentRow[i] = 1; // Last element is always 1

            ans.push_back(currentRow);
        }

        return ans;
    }
};