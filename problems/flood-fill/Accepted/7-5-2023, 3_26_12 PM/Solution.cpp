// https://leetcode.com/problems/flood-fill

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] != color) fill(image, sr, sc, image[sr][sc], color);
        return image;
    }

    void fill (vector<vector<int>>& image, int x, int y, int oldc, int newc) {
        if (x == image.size() || x < 0 || y == image[0].size() || y < 0) return;
        if (image[x][y] != oldc) return;

        image[x][y] = newc;
        fill(image, x+1, y, oldc, newc);
        fill(image, x-1, y, oldc, newc);
        fill(image, x, y-1, oldc, newc);
        fill(image, x, y+1, oldc, newc);

        return;
    }

};