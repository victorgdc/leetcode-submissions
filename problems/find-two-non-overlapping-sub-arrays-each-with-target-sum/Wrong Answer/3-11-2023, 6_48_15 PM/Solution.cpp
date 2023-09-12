// https://leetcode.com/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum

class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {

        int sum = 0;
        int start = 0;
        int n = arr.size();
        int window;
        vector<int> mins;

        for (int i = 0; i < n; i++) {
            sum += arr[i];

            while (sum > target) {
                sum -= arr[start];
                start++;
            }
            if (sum == target) {
                window = i - start + 1;
                mins.push_back(window);
            }

        }

        sort(mins.begin(), mins.end());

        return (mins.size() < 2) ? -1 : (mins[0] + mins[1]);
        

    }
};