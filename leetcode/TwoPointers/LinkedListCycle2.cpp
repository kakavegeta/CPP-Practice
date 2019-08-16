  //Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(nullptr) {}
  };
 
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head->next || !head->next->next) return nullptr;
        ListNode *slow = head->next;
        ListNode *fast = head->next->next;
        while(slow!=fast){
            if(fast==nullptr && fast->next==nullptr) return nullptr;
            slow = slow->next;
            fast = fast->next->next;
        }
        slow = head;
        while(slow!=fast){
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
        
    }
};