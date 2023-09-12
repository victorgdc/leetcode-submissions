// https://leetcode.com/problems/rotate-array

using namespace std;
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int start = 0, end = nums.size()-1;
        int m = start + (end-start)/2;
        reverse(nums, start, m);
        reverse(nums, m+1, end);
        reverse(nums, 0, end);
    }
    void reverse (vector<int>& v, int start, int end) {
        while (start <= end) {
            int temp = v[start];
            v[start] = v[end];
            v[end] = temp;
            start++;
            end--;
        }
    }
};