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
        if(head == NULL) return head;
        if(head->next == NULL && n == 1) return NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        int count = 1;
        while(fast->next != NULL && fast->next->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
            count++;
        }
        int length;
        if(fast->next == NULL) length = count*2 - 1;
        else if(fast->next->next == NULL) length = 2*count;
        
        ListNode* p = head;
        if(length == n){
            p = head->next;
            head->next = NULL;
            return p;
        }
        for(int i = 1; i < length - n; i++) p = p->next;
        ListNode* p1 = p->next;
        p->next = p1->next;
        p1->next = NULL;
        return head;
    }
};