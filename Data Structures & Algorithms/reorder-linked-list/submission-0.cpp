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
    ListNode* getMid(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* slow = head, *fast = head->next->next;
        while(slow && fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* rev(ListNode* head) {
        ListNode* prev = NULL;
        while(head) {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }

        return prev;
    }
public:
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL) return;

        ListNode* mid = getMid(head);
        ListNode* temp = mid->next;
        mid->next = NULL;
        mid = temp;
        mid = rev(mid);

        while(head) {
            ListNode* next = head->next;
            ListNode* mnext = mid->next;
            head->next = mid;
            if(next)
                mid->next = next;

            head = next;
            mid = mnext;
        }
    }
};
