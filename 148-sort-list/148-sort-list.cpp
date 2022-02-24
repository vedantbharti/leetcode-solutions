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
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* left = head;
        ListNode* right = slow->next;
        slow->next = NULL;
        
        ListNode* sortedLeft = sortList(left);
        ListNode* sortedRight = sortList(right);
        
        
        return merge(sortedLeft,sortedRight);
    }
    
    
    ListNode* merge(ListNode* left, ListNode* right){
        ListNode* result = NULL;
        if(left==NULL) return right;
        if(right==NULL) return left;
        if(left->val<=right->val){
            result = left;
            result->next = merge(left->next,right);
        } else{
            result = right;
            result->next = merge(left, right->next);
        }
        
        return result;
    }
};