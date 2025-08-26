class Solution {
    public int lastStoneWeight(int[] stones) {
        PriorityQueue<Integer>pq = new PriorityQueue<Integer>(Collections.reverseOrder());
        int n = stones.length;
        for(int i=0; i<n; i++){
            pq.add(stones[i]);
        }
        while(pq.size()>1){
            int a = pq.peek();
            pq.remove(a);
            int b = pq.peek();
            pq.remove(b);
            int left = a-b;
            pq.add(left);
        }
        if(pq.size()==0){
            return 0;
        }else{
            return pq.peek();
        }
    }
}