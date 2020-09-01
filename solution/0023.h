//合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。
//
//示例:
//输入:
//[
//  1->4->5,
//  1->3->4,
//  2->6
//]
//输出: 1->1->2->3->4->4->5->6

#ifdef t0023

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<ListNode*>::iterator it;
//        删除空数组
        for(it = lists.begin(); it != lists.end();){
            if(! *it){
                it = lists.erase(it);
            } else{
                ++it;
            }
        }
        if(lists.empty()) return NULL;
        
        ListNode *head = lists[0];
        ListNode *node = lists[0];

        auto cnt = lists.begin();
        
        for(it = lists.begin(); it != lists.end(); ++it){
            if(head->val > (*it)->val){
                head = node = *it;
                cnt = it;
            }
        }
        
        (*cnt) = (*cnt)->next;
        if(!*cnt) lists.erase(cnt);
        
        while(!lists.empty()){
            cnt = lists.begin();
            for(it = lists.begin(); it != lists.end();++it){
                if((*cnt)->val > (*it)->val){
                    cnt = it;
                }
            }
            node->next = *cnt;
            node = node->next;
            (*cnt) = (*cnt)->next;
            if(!(*cnt)) lists.erase(cnt);
        }
        return head;     
    }  
    
    void run()
    {
        vector<vector<int>> v = {{1,2,4}, {1,3,4}};        
        vector<ListNode*> lists;    
        ListNode *node;
        ListNode *head;
        
        for(int i = 0; i < 2; i++){
            head = new ListNode(v[i][0]);
            node = head;
            for(int j = 1; j < v[i].size(); j++){
                node->next = new ListNode(v[i][j]);
                node = node->next;
            }
            lists.push_back(head);
        }
        
        for(int i = 0; i < lists.size(); i++){
            node = lists[i]->next;
            cout << lists[i]->val;
            while(node){
                cout << " -> " << node->val;
                node = node->next;
            }
            cout << endl;
        }   
        
        mergeKLists(lists);
        while(head){
            cout << head->val << " -> ";
            head = head->next;
        }
        cout << endl;
        return 0;
    }
};



#endif