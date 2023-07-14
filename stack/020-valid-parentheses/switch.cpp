class Solution {
 public:
  bool isValid(string s) {
    std::stack<char> paraStack;

    for (auto c : s) {
      char expected;
      switch (c) {
        case '{':
        case '(':
        case '[':
          paraStack.push(c);
          break;
        case '}':
          if (paraStack.empty() || paraStack.top() != '{') return false;
          paraStack.pop();
          break;
        case ')':
          if (paraStack.empty() || paraStack.top() != '(') return false;
          paraStack.pop();
          break;
        case ']':
          if (paraStack.empty() || paraStack.top() != '[') return false;
          paraStack.pop();
          break;
      }
    }

    return paraStack.empty();
  }
};
