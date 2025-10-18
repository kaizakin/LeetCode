class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> li;
        int n = asteroids.size();

        for (int i = 0; i < n; i++) {
            if (asteroids[i] > 0) {
                li.push_back(asteroids[i]);
            } else {
                while (!li.empty() && li.back() > 0 &&
                       li.back() < abs(asteroids[i])) {
                    li.pop_back();
                }
                if (!li.empty() && li.back() == abs(asteroids[i])) {
                    li.pop_back();
                } else if (li.empty() || li.back() < 0) {
                    li.push_back(asteroids[i]);
                }
            }
        }

        return li;
    }
};