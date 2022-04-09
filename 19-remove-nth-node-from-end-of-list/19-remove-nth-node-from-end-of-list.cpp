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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int l = 0;
        ListNode* temp = head;
        while(temp!=NULL){
            l++;
            temp = temp->next;
        }
        
        n = l-n;
        
        int i=1;
        temp = head;
        while(i<n){
            temp = temp->next;
            i++;
        }
        
        if(n==0){
            return temp->next;
        }
        temp->next = temp->next->next;
        
        return head;
    }
};