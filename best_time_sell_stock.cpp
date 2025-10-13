class Solution {
public:
    int maxProfit(vector<int>& nums) {
       int buy=nums[0];
       int profit=0;

       for(int i=0;i<nums.size();i++){
        if(nums[i] < buy){
            buy=nums[i];
        }
        else{
            profit=max (profit, nums[i]-buy);
        }
       } 
       return profit;
    }
};