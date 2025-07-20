class Solution:
    def canMeasureWater(self, x: int, y: int, target: int) -> bool:
        return (target%math.gcd(x,y)==0 and x+y>=target)
        