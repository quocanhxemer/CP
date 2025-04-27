// https://www.hackerrank.com/challenges/queries-with-fixed-length/problem

#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> arr, vector<int> queries) {
    vector<int> prev_greater(arr.size(), -1);
    vector<int> next_greater(arr.size(), arr.size());

    stack<int> s1;
    for (int i = 0; i < arr.size(); i++) {
        while (!s1.empty() && arr[s1.top()] <= arr[i])
            s1.pop();
        if (!s1.empty())
            prev_greater[i] = s1.top();
        s1.push(i);
    }

    stack<int> s2;
    for (int i = arr.size() - 1; i >= 0; i--) {
        while (!s2.empty() && arr[s2.top()] <= arr[i])
            s2.pop();
        if (!s2.empty())
            next_greater[i] = s2.top();
        s2.push(i);
    }

    vector<int> res(arr.size() + 1, INT_MAX);
    for (int i = 0; i < arr.size(); i++) {
        int length = next_greater[i] - prev_greater[i] - 1;
        res[length] = min(arr[i], res[length]);
    }

    for (int i = arr.size() - 1; i >= 1; i--)
        if (res[i] > res[i + 1])
            res[i] = res[i + 1];

    vector<int> ret;
    for (int q : queries) {
        if (q > arr.size())
            q = arr.size();
        ret.push_back(res[q]);
    }

    return ret;
}
