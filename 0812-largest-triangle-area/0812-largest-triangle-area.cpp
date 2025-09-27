class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        int maxarea = 0;
    for (int i=0; i<points.size()-2 ; i++){
        for (int j=i+1; j<points.size()-1 ; j++){
            for (int k=j+1; k<points.size() ; k++){
                int x1,y1,x2,y2;
                x1 = points[i][0] - points[j][0];
                y1 = points[i][1] - points[j][1];
                x2 = points[i][0] - points[k][0];
                y2 = points[i][1] - points[k][1];
                int area = x1*y2 - x2*y1; // rectangle area, triangle is half
                if (area < 0){
                    area = -area;
                if (area > maxarea){
                    maxarea = area;
                }
            }
        }
        }
    }
        return maxarea/2.0; // triangle area is half
    }
};