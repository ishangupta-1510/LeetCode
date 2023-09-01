class Solution {
public:
    void targetsum(vector<vector<int>> &ans, vector<int>& vec, vector<int>& c, int target, int i) {
        if (target == 0) {
            ans.push_back(vec);
            return;
        }
        if (i == c.size() || target < 0) {
            return;
        }
        
        // Include the current element in the combination
        vec.push_back(c[i]);
        targetsum(ans, vec, c, target - c[i], i + 1);
        vec.pop_back();
        
        // Skip duplicates
        while (i + 1 < c.size() && c[i] == c[i + 1]) {
            i++;
        }
        
        // Exclude the current element and move to the next
        targetsum(ans, vec, c, target, i + 1);
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> vec;
        
        // Sort the candidates to handle duplicates properly
        sort(candidates.begin(), candidates.end());
        
        targetsum(ans, vec, candidates, target, 0);
        
        return ans;
    }
};
