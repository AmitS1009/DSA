class Solution {
public:

    int CntSubset(int idx, int currOr, vector<int> &nums, int maxOr){
        if(idx == nums.size()){
            if(currOr == maxOr) return 1;
            return 0;
        }
        //taken nums[idx]
        int TakenCnt =  CntSubset(idx+1, currOr|nums[idx],  nums, maxOr);
        // Not taken nums[idx]
        int NotTakenCnt =  CntSubset(idx+1, currOr, nums, maxOr);
        
        return TakenCnt+NotTakenCnt;
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr = 0;
        for(int &num : nums){
            maxOr |= num;
        }
        int currOr = 0;
        return CntSubset(0, currOr, nums, maxOr);
    }
};
