#include<bits/stc++.h>

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int maxArea = 0;
        int row = matrix.size();
        int col = matrix[0].size();
        vector<int> height(col, 0);
        
        for(int i = 0;i<row;i++){
            for(int j = 0;j<col;j++){
                if(matrix[i][j] == '1'){
                    height[j]++;
                }else{
                    height[j] = 0;
                }
            }
            maxArea = max(maxArea,largestRectangleArea(height));
        }
        return maxArea;
    }
private: 
    int largestRectangleArea(vector<int>& height) {
        height.push_back(0);
        int n = height.size(), area = 0;
        stack<int> indexes;
        for (int i = 0; i < n; i++) {
            while (!indexes.empty() && height[indexes.top()] > height[i]) {
                int h = height[indexes.top()]; indexes.pop();
                int l = indexes.empty() ? -1 : indexes.top();
                area = max(area, h * (i - l - 1));
            }
            indexes.push(i);
        }
        return area; 
    }
};

int main(){
    
    return 0;
}