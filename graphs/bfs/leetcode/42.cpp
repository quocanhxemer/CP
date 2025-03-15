//  https://leetcode.com/problems/trapping-rain-water/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;

        int sum = 0;
        while (left < right) {
            if (height[left] < height[right]) {
                int diff = height[left] - height[left + 1];
                if (diff > 0) {
                    sum += diff;
                    height[left + 1] += diff;
                }
                left++;
            } else {
                int diff = height[right] - height[right - 1];
                if (diff > 0) {
                    sum += diff;
                    height[right - 1] += diff;
                }
                right--;
            }
        }

        return sum;
    }
};