class Solution {
 public:
  int eval(int v1, int v2, char op) {
    switch (op) {
      case '+':
        return v1 + v2;
      case '-':
        return v1 - v2;
      case '*':
        return v1 * v2;
      case '/':
        return v1 / v2;
      default:
        __builtin_unreachable();
    }
  }

  int evalRPN(vector<string>& tokens) {
    std::stack<int> ms;

    for (auto t = tokens.begin(); t != tokens.end(); t++) {
      int v1;
      int v2;
      if (*t == "+" || *t == "-" || *t == "*" || *t == "/") {
        if (ms.empty()) assert(0);
        v1 = ms.top();
        ms.pop();
        if (ms.empty()) assert(0);
        v2 = ms.top();
        ms.pop();
        ms.push(eval(v2, v1, (*t)[0]));
      } else {
        ms.push(stoi(*t));
      }
    }

    if (ms.empty()) assert(0);

    return ms.top();
  }
};
