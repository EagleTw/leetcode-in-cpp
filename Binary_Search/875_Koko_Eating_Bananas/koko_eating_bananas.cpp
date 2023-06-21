class Solution {
public:
    double calcH(vector<int> &piles, int div) {
        if (div == 0)
            return INT_MAX;

        double ret = 0;
        for (int i : piles) {
            ret += (i % div) ? (i / div) + 1 : (i / div);
        }
        return ret;
    }

    int minEatingSpeed(vector<int>& piles, int h) {

        int low = 0;  // lower bound of k
        int high = 0;

        for (int i : piles) {
            high = max(high, i);
        }

        while (low < high) {
            int mid = (low + high) / 2;
            double val = calcH(piles, mid);
            if (val > h) { /* val too large */
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }
};
