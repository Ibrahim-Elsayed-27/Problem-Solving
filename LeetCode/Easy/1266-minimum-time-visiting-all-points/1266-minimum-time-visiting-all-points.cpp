class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int start_x = points[0][0];
        int start_y = points[0][1];
        int steps = 0;
        for(int i=1;i < points.size(); ++i){
            steps+= max(abs(start_x - points[i][0]), abs(start_y - points[i][1]));
            start_x = points[i][0];
            start_y = points[i][1];
        }

        return steps;
    }
};