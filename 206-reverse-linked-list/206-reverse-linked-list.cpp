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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL) return head;
        if(head->next==NULL) return head;
        ListNode* prev = head;
        head = head->next;
        ListNode* temp;
        temp = head->next;
        head->next = prev;
        prev->next = NULL;
        while(temp){
            prev = head;
            head = temp;
            temp = temp->next;
            head->next = prev;
        }
        
        return head;
    }
};