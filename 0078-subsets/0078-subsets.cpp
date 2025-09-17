class Solution {
public:
    void backtrack(vector<int>& nums, int idx, vector<int>& current, vector<vector<int>>& res) {
        if (idx == nums.size()) {
            res.push_back(current); // add current subset
            return;
        }

        // Include nums[idx]
        current.push_back(nums[idx]);
        backtrack(nums, idx + 1, current, res);

        // Exclude nums[idx]
        current.pop_back();
        backtrack(nums, idx + 1, current, res);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> current;
        backtrack(nums, 0, current, res);
        return res;
    }
};
