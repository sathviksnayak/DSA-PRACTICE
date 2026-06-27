class Solution {
    vector<int> bit;
    int n;

    void add(int i) {
        while (i <= n) {
            bit[i]++;
            i += i & -i;
        }
    }

    int get(int i) {
        int ans = 0;
        while (i > 0) {
            ans += bit[i];
            i -= i & -i;
        }
        return ans;
    }

public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {

        int sz = nums.size();
        int offset = sz + 1;

        n = 2 * sz + 2;
        bit.resize(n + 1, 0);

        long long ans = 0;
        int pref = 0;

        add(offset);   

        for (int x : nums) {

            pref += (x == target ? 1 : -1);

            int idx = pref + offset;

            ans += get(idx - 1); 

            add(idx);
        }

        return ans;
    }
};