class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        int sum = 0;
        for(int i=0; i<piles.size(); i++){
            pq.push(piles[i]);
            sum += piles[i];
        }
        while(k--){
            int top = pq.top();
            pq.pop();

            sum -= top/2;
            pq.push(top - top/2);
        }

        return sum;
    }
};
