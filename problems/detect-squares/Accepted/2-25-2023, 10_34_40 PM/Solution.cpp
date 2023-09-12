// https://leetcode.com/problems/detect-squares

class DetectSquares {
private:
map<pair<int, int>, int> map;
public:
    // unordered_map<vector<int>, int> map;

    DetectSquares() {

    }
    
    void add(vector<int> point) {
        int x = point[0];
        int y = point[1];
        if (map.find({x, y}) == map.end()) map[{x, y}] = 0;
        map[{x, y}]++;    
    }
    
    int count(vector<int> point) {
        int x = point[0];
        int y = point[1];

        int result = 0;
        for (auto p: map) {
            if (abs(p.first.first - x) != abs(p.first.second - y) || p.first.first == x || p.first.second == y) continue; 
            if (map.find({p.first.first, y}) == map.end() || map.find({x, p.first.second}) == map.end()) continue;

            result += map[p.first] * map[{p.first.first, y}] * map[{x, p.first.second}];
        }
        return result;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */