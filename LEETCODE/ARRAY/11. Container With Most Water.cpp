class Solution {
public:
    int maxArea(vector<int>& height) {
        long long maxarea=0,area;
        int minh,distance;
        int left=0;
        int right=height.size()-1;
        while(left<right){
            minh=min(height[left],height[right]);
            distance=right-left;
            area=distance*minh;
            if(area>maxarea){
                maxarea=area;
            }
            if(height[left]<height[right]){
                left++;
            }
            else{
                right--;
            }
           
        }
      return (int)maxarea;  
    }
};