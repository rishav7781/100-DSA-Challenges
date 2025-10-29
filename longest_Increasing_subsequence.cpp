//o(n^2) approach with memoization
class Solution {
public:
    int n;
    int t[2501][2501];
    int solve(vector<int>&nums, int i, int prev){
        if(i>=n) return 0;
        if(prev!=-1 && t[i][prev]!=-1){
            return t[i][prev];
        }
        int take=0;
        //take
        if(prev==-1 || nums[prev]<nums[i]){
            take= 1+solve(nums,i+1,i);
        }
        //skip
        int skip=solve(nums,i+1,prev);
        if(prev!=-1){
            return t[i][prev]= max(take,skip);
        }
      return  max(take,skip);

    }
    int lengthOfLIS(vector<int>& nums) {
       memset(t,-1,sizeof(t)); 
        n=nums.size();
        return solve(nums,0,-1);
    }
};


//o(nlogn) approach
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> sorted;
        int n=nums.size();
        //trick used ki soch lo vector of linked list h sorted jaise koi elemnt just bada mil jayega sorted me iterator uska position de dega then humlog uss position me kam val wala elemnt ko replace kr dengye or agr ni mila toh push kr dengy naya value like as a linked list head will be 2(lower me uska 9->10)then uske baad 5 ayega jo 2 se toh chita h tohj usko push krna hoga as a new value aise hi humlog krte rahngye pr isme humlog ko linked list ki jarurat nhi toh heads se hi ho jayega then iska size will be our answer!!
        for(int i=0;i<n;i++){
            auto it=lower_bound(sorted.begin(),sorted.end(),nums[i]); 

            if(it==end(sorted)){ //not found
                sorted.push_back(nums[i]);
            }
            else{
                *it=nums[i];
            }
        }
        return sorted.size();

    }
};