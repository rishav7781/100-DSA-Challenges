class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int leftP=1;
        int rightP=1;
        int ans=nums[0];
        int n=nums.size();

        for(int i=0;i<n;i++){
            leftP = leftP==0 ? 1 :leftP;
            rightP = rightP==0 ? 1 :rightP;

            leftP *=nums[i];
            rightP *=nums[n-1-i];

            ans= max ({leftP,rightP,ans});

        }
        return ans;



    }
};