// https://leetcode.com/problems/rotate-array

using namespace std;
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        int end = n-1;
        k = k%n;
        reverse(nums, 0, n-k-1);
        reverse(nums, n-k, end);
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