// https://leetcode.com/problems/first-bad-version

// The API isBadVersion is defined for you.
bool isBadVersion(int version);

class Solution {
public:
    int binarySearch(int l, int r){
    
        if (l <= r) {
            int m = l + (r - l)/2;
        
            if(!isBadVersion(m-1) && isBadVersion(m)){
                return m;
            }
            if(isBadVersion(m-1) && isBadVersion(m)){
                return binarySearch(l, m-1);
            }
            if(!isBadVersion(m)){
                return binarySearch(m+1, r);
            }
        }
        
        return -1;
    }
    int firstBadVersion(long int n) {
        int l = 1, r = n;
        return binarySearch(l, r);
    }
};