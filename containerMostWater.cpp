class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0;
        int r= height.size()-1;

        int maxArea=0;

        while(l<r){
             int h= min(height[l],height[r]);
             int b= (r-l);
             int area = h*b;

            maxArea= max(maxArea, area);

            if(height[l]<height[r]) l++;
            else r--;
        }
        return maxArea;

    }
};