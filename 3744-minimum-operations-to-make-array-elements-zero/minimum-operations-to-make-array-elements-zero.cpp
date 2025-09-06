class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        vector<long long> lefts, rights, steps;
        long long p = 1;
        int k = 1;
        while (p <= 1e9) {
            long long L = p;
            long long R = min((long long)1e9, 4 * p - 1);
            lefts.push_back(L);
            rights.push_back(R);
            steps.push_back(k);
            p *= 4;
            k++;
        }

        long long ans = 0;

        for (auto &q : queries) {
            long long l = q[0], r = q[1];
            long long totalSteps = 0;

            for (int i = 0; i < (int)lefts.size(); i++) {
                if (r < lefts[i] || l > rights[i]) continue; // no overlap
                long long L = max(l, lefts[i]);
                long long R = min(r, rights[i]);
                long long len = R - L + 1;
                totalSteps += len * steps[i];
            }

            // ceil(totalSteps / 2)
            ans += (totalSteps + 1) / 2;
        }

        return ans;
    }
};