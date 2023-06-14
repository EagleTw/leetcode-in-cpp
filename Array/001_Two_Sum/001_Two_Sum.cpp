class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> lookup;
    
        for (int i = 0; i < nums.size(); i++) {
            int second = target - nums[i];
            auto pos = lookup.find(second);
            if (pos != lookup.end()) {
                if (pos->second == i) 
                    continue;
                return {i, pos->second};
            }
            lookup[nums[i]] = i;
        }
        return {};
    }
};
