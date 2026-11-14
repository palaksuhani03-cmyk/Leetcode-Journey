class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        multiset<int> s;
        int ans = INT_MAX;

        for (int i = l; i <= n; i++) {
            s.insert(prefix[i - l]);

            if (i - r - 1 >= 0) {
                auto it = s.find(prefix[i - r - 1]);
                if (it != s.end())
                    s.erase(it);
            }

            auto it = s.lower_bound(prefix[i]);

            if (it != s.begin()) {
                --it;
                int sum = prefix[i] - *it;

                if (sum > 0)
                    ans = min(ans, sum);
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};