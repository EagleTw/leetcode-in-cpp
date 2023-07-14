class Solution {
  struct comp {
    bool operator()(const ListNode* l, const ListNode* r) {
      return l->val > r->val;
    }
  };

 public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<ListNode*, vector<ListNode*>, comp> pq;
    for (auto l : lists) {
      if (l) pq.push(l);
    }
    if (pq.empty()) return nullptr;

    ListNode* result = pq.top();
    pq.pop();

    ListNode* tail = result;
    if (tail->next) pq.push(tail->next);

    while (!pq.empty()) {
      tail->next = pq.top();
      pq.pop();
      tail = tail->next;
      if (tail->next) pq.push(tail->next);
    }
    return result;
  }
};
