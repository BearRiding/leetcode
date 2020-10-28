/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
struct ListNode{
    int val;
    ListNode* next;
}
 
 
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp = head;        
        while(temp && temp->next){
            while(temp->next && temp->val == temp->next->val){
                temp->next = temp->next->next;
            }            
            temp = temp->next;
        }
        return head;
    }
};