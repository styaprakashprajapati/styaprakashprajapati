class Solution {
public:
    bool validMountainArray(vector<int>& arr) {

        int n = arr.size();

        if (n < 3)
            return false;

        int i = 0;

        // Go Up
        while (i + 1 < n && arr[i] < arr[i + 1]) {
            i++;
        }

        // Peak should not be first or last
        if (i == 0 || i == n - 1)
            return false;

        // Go Down
        while (i + 1 < n && arr[i] > arr[i + 1]) {
            i++;
        }

        return i == n - 1;
    }
};