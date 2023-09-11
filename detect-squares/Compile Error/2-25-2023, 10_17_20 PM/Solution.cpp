// https://leetcode.com/problems/detect-squares

class DetectSquares {
public:
    unordered_map<vector<int>, int> hash;

    // DetectSquares() {
    //     hash.clear();
    // }
    
    void add(vector<int> point) {
        if (hash.find(point) == hash.end()) hash[point] = 0;
        hash[point]++;    
    }
    
    int count(vector<int> point) {
        for (auto p: hash) {
            if (abs(p.first[0] - point[0]) != abs(p.first[1] - point[1]) || p.first[0] == point[0] || p.first[1] == point[1]) continue; 
            if (hash.find({p.first[0], point[1]}) == hash.end() || hash.find([p.first[1], point[0]]) == hash.end()) continue;

            return hash[p.first] * hash[[p.first[0], point[1]] * hash[[p.first[1], point[0]];
        }
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */