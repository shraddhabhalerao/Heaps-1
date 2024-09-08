// Time : O(n log k) 
// Space : O(k)

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;

        for(int num : nums)
        {
            if(pq.size() < k)
            {
                pq.push(num);
            }
            else if(pq.size() >= k && num < pq.top())continue;
            else
            {
                pq.pop();
                pq.push(num);
            }
        }

        return pq.top();
    }
};