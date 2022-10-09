class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size();

        ++digits[len-1];
        if (digits[len-1] < 10) {
            return digits;
        }
        int carry = 0;
        for (int i=len-1; i>=0; i--) {
            int sum = carry + digits[i];
            carry = sum / 10;
            digits[i] = sum % 10;
            if (carry == 0) return digits;
        }
        if (carry == 1) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};
