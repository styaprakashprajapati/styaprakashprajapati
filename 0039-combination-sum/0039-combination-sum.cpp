class Solution {
public:

    void solve(vector<int>& candidates,
               int target,
               int start,
               vector<int>& current,
               vector<vector<int>>& ans) {

        // Target mil gaya
        if (target == 0) {
            ans.push_back(current);
            return;
        }

        // Target se chhota nahi ja sakta
        for (int i = start; i < candidates.size(); i++) {

            // Agar number target se bada hai
            // toh aage ke numbers bhi bade honge
            if (candidates[i] > target)
                break;

            // Number choose karo
            current.push_back(candidates[i]);

            // i hi bhej rahe hain
            // kyunki same number dobara use kar sakte hain
            solve(candidates,
                  target - candidates[i],
                  i,
                  current,
                  ans);

            // Number hata do
            // aur next choice try karo
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates,
                                        int target) {

        vector<vector<int>> ans;
        vector<int> current;

        sort(candidates.begin(), candidates.end());

        solve(candidates, target, 0, current, ans);

        return ans;
    }
};