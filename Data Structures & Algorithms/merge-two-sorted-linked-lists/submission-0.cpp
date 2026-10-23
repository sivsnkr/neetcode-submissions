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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL) return list2;
        else if(list2 == NULL) return list1;
        ListNode* res = NULL, *cur = NULL;

        while(list1 && list2) {
            ListNode* minNode = NULL;
            if(list1->val <= list2->val) {
                minNode = list1;
                list1 = list1->next;
            }else {
                minNode = list2;
                list2 = list2->next;
            }

            if(cur == NULL) {
                res = minNode;
                cur = minNode;
                cur->next = NULL;
            }else {
                cur->next = minNode;
                cur = cur->next;
                cur->next = NULL;
            }
        }

        if(list1) cur->next = list1;
        else if(list2) cur->next = list2;

        return res;
    }
};
