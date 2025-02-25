class Solution(object):
    def numOfSubarrays(self, arr):
        n = len(arr)
        count_odd = 0
        count_even = 1
        result = 0
        sum = 0
        mod = 10**9+7
        for i in arr:
            sum=sum+i
            if sum%2==0:
                result+=count_odd %mod
                count_even+=1
            else :
                result += count_even %mod
                count_odd+=1
        result = result%mod
        return result