class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0;
        int right = n-1;
        int maxi = INT_MIN;
        
        while(left<right){
            int h = min(height[left], height[right]);
            int w = right - left;
            maxi = max(maxi, h*w);
            if(height[left]>height[right]){
                right--;
            }
            else{
                left++;
            }
        }
        return maxi;
    }
};