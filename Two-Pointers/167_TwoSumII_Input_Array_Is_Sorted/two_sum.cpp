class Solution {
 public:
  vector<int> twoSum(vector<int>& numbers, int target) {
    vector<int> ret;
    int front = 0;
    int rear = numbers.size() - 1;

    while (front < rear) {
      int sum = numbers[front] + numbers[rear];
      if (sum == target) {  // matches
        ret.push_back(front + 1);
        ret.push_back(rear + 1);
        break;
      } else if (sum > target) {
        rear--;
      } else {
        front++;
      }
    }
    return ret;
  }
};
