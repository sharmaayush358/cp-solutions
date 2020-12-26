class Solution {
public:
    int maxArea(vector<int>& wallHeights) {
        int n = wallHeights.size();
        int i = 0, j = n-1;
        int maxArea = 0;
        
        while(i<j) {
            int leftWallHeight = wallHeights[i], rightWallHeight = wallHeights[j];
            int area = min(leftWallHeight, rightWallHeight) * (j-i);
            maxArea = max(area, maxArea);
            
            if(leftWallHeight < rightWallHeight) {
                i++;
            }
            else {
                j--;
            } 
        }
        
        return maxArea;
    }
};
