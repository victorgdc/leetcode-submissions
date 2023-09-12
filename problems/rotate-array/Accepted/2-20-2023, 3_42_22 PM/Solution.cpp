// https://leetcode.com/problems/rotate-array

using namespace std;
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int tam = nums.size();
        int v[tam];
        int i = 0;
        for (auto el: nums) {
            v[(i+k)%tam] = el;
            i++;
        }
        nums.clear();
        for (int i = 0; i < tam; i++) {
            nums.push_back(v[i]);
        }
    }
};