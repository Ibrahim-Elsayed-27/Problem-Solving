class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double minY = 1e18;
        double maxY = -1e18;
        double total_area = 0.0;
        for (const auto& sq : squares) {
            double yi = sq[1];
            double li = sq[2];

            minY = min(minY, yi);
            maxY = max(maxY, yi + li);
            total_area += li * li;
        }

        double l = minY;
        double r = maxY;
        double mid = 0.0;
        while(r - l > 1e-6){
            mid = l + (r - l)/2.0;

            double mid_area_below = calculateAreaUnderY(squares, mid);
            if(mid_area_below < total_area / 2.0){
                l = mid;
            }else{
                r = mid;
            }
        }

        return l;
    }

    double calculateAreaUnderY(vector<vector<int>>& squares, double y){
        double area = 0;
        for (const auto& sq: squares){
            double yi = sq[1];
            double li = sq[2];

            if(y <= yi){
                continue;
            }

            if(y >= yi + li){
                area += li * li;
            }
            else{
                area += li * (y - yi);
            }
        }

        return area;
    }
};