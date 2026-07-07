class Solution {
public:
    vector<int> ans;

    void merge(vector<pair<int,int>>& nums, int low, int mid, int high)
    {
        vector<pair<int,int>> temp;

        int left = low;
        int right = mid + 1;

        int rightCount = 0;

        while(left <= mid && right <= high)
        {
            if(nums[right].first < nums[left].first)
            {
                rightCount++;
                temp.push_back(nums[right]);
                right++;
            }
            else
            {
                ans[nums[left].second] += rightCount;
                temp.push_back(nums[left]);
                left++;
            }
        }

        while(left <= mid)
        {
            ans[nums[left].second] += rightCount;
            temp.push_back(nums[left]);
            left++;
        }

        while(right <= high)
        {
            temp.push_back(nums[right]);
            right++;
        }

        for(int i = low; i <= high; i++)
        {
            nums[i] = temp[i - low];
        }
    }

    void mergeSort(vector<pair<int,int>>& nums, int low, int high)
    {
        if(low >= high)
            return;

        int mid = low + (high - low)/2;

        mergeSort(nums, low, mid);
        mergeSort(nums, mid + 1, high);

        merge(nums, low, mid, high);
    }

    vector<int> countSmaller(vector<int>& nums)
    {
        int n = nums.size();

        ans.resize(n);

        vector<pair<int,int>> arr;

        for(int i=0;i<n;i++)
        {
            arr.push_back({nums[i],i});
        }

        mergeSort(arr,0,n-1);

        return ans;
    }
};