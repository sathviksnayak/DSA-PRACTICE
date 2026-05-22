class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;
        int ops = 0;

        for (int i = 0; i < n; i++) {

            while (!dq.empty() && dq.front() + k-1 < i) {
                dq.pop_front();
            }


            int effective = nums[i];
            if (dq.size() % 2 == 1) {
                effective ^= 1;
            }

 
            if (effective == 0) {
                if (i + k-1 >= n) return -1;

                dq.push_back(i); 
                ops++;
            }


        }
        return ops;

    }
};