class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        
        while(left < right) {
            int mid = left + (right - left) / 2;
            
            // If mid element is greater than rightmost, min is to the right
            if(nums[mid] > nums[right]) {
                left = mid + 1;
            } 
            // Else min is at mid or to the left
            else {
                right = mid;
            }
        }
        
        // left == right is the index of minimum
        return nums[left];
    }
};
