class Solution {
    double result1(int l , int b){
        int a = ((l*l) +(b*b));
        return Math.sqrt(a);
    }
    public int areaOfMaxDiagonal(int[][] dimensions) {
        int n = dimensions.length;
        int result = 0;
        double maxi = 0;
        for(int i =0 ;i<n;i++){
            double a = result1(dimensions[i][0], dimensions[i][1]);
            if(a > maxi){
                maxi = a;
                result = dimensions[i][0] * dimensions[i][1];
            }else if (a==maxi){
                result = Math.max(result,dimensions[i][0] * dimensions[i][1]);
            }
        }
        return result;
    }
}