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
    //see how you can add these numbers without reversing the linkedlist
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        ListNode* temp1 = l1, *temp2 = l2;
        ListNode* prev1 = NULL, *prev2 = NULL;
        int n1 = 0, n2 = 0;
        while(temp1){
            n1++;
            if(temp1->next==NULL) prev1 = temp1;
            temp1 = temp1->next;
        }
        while(temp2){
            n2++;
            if(temp2->next==NULL) prev2 = temp2;
            temp2 = temp2->next;
        }
        
        if(n1<n2){
            return addTwoNumbers(l2,l1);
        }
        
        temp1 = l1;
        temp2 = l2;
        int sum = 0;
        int carry = 0;
        
        while(temp1 && temp2){
            sum = (temp1->val + temp2->val + carry)%10;
            carry = (temp1->val + temp2->val + carry)/10;
            temp1->val = sum;
            temp1 = temp1->next, temp2 = temp2->next;
        }
        
        while(temp1){
            sum = (temp1->val + carry)%10;
            carry = (temp1->val + carry)/10;
            temp1->val = sum;
            temp1 = temp1->next;
        }
        
        if(carry!=0){
            prev1->next = new ListNode(carry);
        }
        
        return l1;
    }
};