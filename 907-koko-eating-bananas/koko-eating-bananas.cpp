class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        int answer = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            long long hours = 0;

            // Calculate total hours needed at speed = mid
            for (int pile : piles) {
                hours += (pile + mid - 1) / mid;   // ceil(pile / mid)
            }

            if (hours <= h) {
                answer = mid;      // possible answer
                right = mid - 1;   // try smaller speed
            } else {
                left = mid + 1;    // need higher speed
            }
        }

        return answer;
    }
};