//将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
//
//示例：
//
//输入：1->2->4, 1->3->4
//输出：1->1->2->3->4->4
#ifdef t0021
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {        
        if(!l1) return l2;
        if(!l2) return l1;
        
        ListNode *node = NULL;
        ListNode *head = NULL;
        
        if(l1->val < l2->val){
            head = node = l1;
            l1 = l1->next;
        } else{
            head = node = l2;
            l2 = l2->next;
        }
        
        while(l1 || l2){
            if(l1 && l2){
                ListNode *&temp = l1->val > l2->val ? l2 : l1;
                node->next = temp;
                node = node->next;
                temp = temp->next;
            } else{
                node->next = l1 ? l1 : l2;
                break;
            }
        }
        return head;
    }
    
    void run()
    {
        vector<vector<int>> v = {{1,2,4}, {1,3,4}};
        
        ListNode *head[2];
        head[0] = new ListNode(v[0][0]);
        head[1] = new ListNode(v[1][0]);
        
        ListNode *node;
        for(int i = 0; i < 2; i++){
            node = head[i];
            for(int j = 1; j < v[i].size(); j++){
                node->next = new ListNode(v[i][j]);
                node = node->next;
            }
        }
       
        for(int i = 0; i < 2; i++){
            node = head[i];
            while(node){
                cout << node->val << "  ";
                node = node->next;
            }
            cout << endl;
        }

        
        node = mergeTwoLists(head[0], head[1]);
        while(node){
            cout << node->val << "  ";
            node = node->next;
        }
        return 0;
    }

};

#endif