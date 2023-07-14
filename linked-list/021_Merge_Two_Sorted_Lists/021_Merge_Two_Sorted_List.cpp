class Solution {
 public:
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* vhead = new ListNode(0);
    ListNode* tmp = vhead;

    while (list1 || list2) {
      if (list1 && list2) {
        if (list1->val < list2->val) {
          tmp->next = list1;
          list1 = list1->next;
          tmp = tmp->next;
        } else {
          tmp->next = list2;
          list2 = list2->next;
          tmp = tmp->next;
        }
      } else if (list1) {
        tmp->next = list1;
        break;
      } else {
        tmp->next = list2;
        break;
      }
    }
    return vhead->next;
  }
};
