class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftP(n, 1);
        vector<int> rightP(n, 1);
        vector<int> ans(n);

        // Build prefix product
        for (int i = 1; i < n; i++) {
            leftP[i] = leftP[i - 1] * nums[i - 1];
        }

        // Build suffix product
        for (int i = n - 2; i >= 0; i--) {
            rightP[i] = rightP[i + 1] * nums[i + 1];
        }

        // Combine them
        for (int i = 0; i < n; i++) {
            ans[i] = leftP[i] * rightP[i];
        }

        return ans;
    }
};


//optimised
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
       int n = nums.size();
        vector<int> result(n, 1);

        // Left product
        int leftProd = 1;
        for (int i = 0; i < n; i++) {
            result[i] = leftProd;
            leftProd *= nums[i];
        }

        // Right product
        int rightProd = 1;
        for (int i = n-1; i >= 0; i--) {
            result[i] *= rightProd;
            rightProd *= nums[i];
        }

        return result;
    }
};
