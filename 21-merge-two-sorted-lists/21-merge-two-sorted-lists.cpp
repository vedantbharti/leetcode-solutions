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
        if(list1 && list2){
            if(list1->val>list2->val) return mergeTwoLists(list2, list1);
        } else if(list1){
            return list1;
        } else {
            return list2;
        }
        
        ListNode* head1 = list1, *head2 = list2;
        ListNode *temp = head1->next;
        ListNode *prev1 = list1, *prev2 = list2;
        head1 = head1->next;
        while(head1 && head2){
            if(head1->val<=head2->val){
                head1 = head1->next;
                prev1 = prev1->next;
            } else {
                prev1->next = head2;
                head2 = head2->next;
                prev1->next->next = head1;
                prev1 = prev1->next;
            }
        }
        
        if(head2){
            prev1->next = head2;
        }
        
        return list1;
    }
};