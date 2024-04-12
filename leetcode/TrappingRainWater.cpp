#include<bits/stc++.h>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int leftMax = 0, rightMax = 0;
        int result = 0;

        while(left < right){
            if(height[left] < height[right]){
                if(leftMax <= height[left]){
                    leftMax = height[left];
                }else{
                    result += leftMax - height[left];
                }
                left++;
            }else{
                if(rightMax <= height[right]){
                    rightMax = height[right];
                }else{
                    result += rightMax - height[right];
                }
                right--;
            }
        }

        return result;
    }
};

int main(){
    
    return 0;
}