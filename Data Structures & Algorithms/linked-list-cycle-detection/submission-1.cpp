/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    bool hasCycle(ListNode* head) {
        if(head == NULL || head->next == NULL) return false;

        ListNode* slow = head, *fast = head->next->next;
        while(slow && fast && fast->next && slow != fast) {
            slow = slow->next;
            fast = fast->next->next;
        }

        if(slow == NULL || fast == NULL || fast->next == NULL) return false;
        return true;
    }
};
