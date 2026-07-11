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
        // deal with empty list
        if(list1 == nullptr) return list2;
        if(list2 == nullptr) return list1;

        // decide head: merge sub into main
        ListNode* main = nullptr;
        ListNode* sub = nullptr;
        ListNode* ret = nullptr;

        if(list1->val < list2->val){
            main = list1;
            sub = list2;
        } else {
            main = list2;
            sub = list1;
        }
        ret = main;

        // go through each node
        while(sub != nullptr){
            while(main->next && main->next->val < sub->val) main = main->next;
            if(main->next == nullptr){
                main->next = sub;
                break;
            }
            ListNode* tmp1 = main->next;
            main->next = sub;
            ListNode* tmp2 = sub->next;
            sub->next = tmp1;
            sub = tmp2;
            main = main->next;
        }
        

        return ret;
    }
};
