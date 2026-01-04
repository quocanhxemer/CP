#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n = fruits.size();

        if (n == 1) return fruits[0][0];

        auto valid_region = [n] (int x, int y) -> bool{
            return x >= 0 && y >= 0 && x < n && y < n;
        };

        auto valid_red = [&] (int x, int y) -> bool {
            return valid_region(x, y) && x < y && x + y >= n - 1;
        };

        auto valid_blue = [&] (int x, int y) -> bool {
            return valid_region(x, y) && x > y && x + y >= n - 1;
        };

        int sum_green = 0;
        for (int i = 0; i < n; i++) {
            sum_green += fruits[i][i];
            for (int j = 0; j < n; j++) {
                if (valid_red(i, j)) {
                    int left = valid_red(i-1, j-1) ? fruits[i-1][j-1] : 0;
                    int mid = valid_red(i-1, j) ? fruits[i-1][j] : 0;
                    int right = valid_red(i-1, j+1) ? fruits[i-1][j+1] : 0;

                    fruits[i][j] += max({left, mid, right});
                }
            }
        }
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < n; i++) {             
                if (valid_blue(i, j)) {
                    int up = valid_blue(i-1, j-1) ? fruits[i-1][j-1] : 0;
                    int mid = valid_blue(i, j-1) ? fruits[i][j-1] : 0;
                    int down = valid_blue(i+1, j-1) ? fruits[i+1][j-1] : 0;
                    
                    fruits[i][j] += max({up, mid, down});
                }
            }
        }

        return sum_green + fruits[n-1][n-2] + fruits[n-2][n-1];
    }
};

