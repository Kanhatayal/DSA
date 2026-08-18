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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* slow = head;
        ListNode* fast = head;
        int n = 1;
        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            n++;
        }
        if(fast->next == NULL){
            n = 2*n - 1;
            fast->next = head;
        }
        else{
            n = 2*n;
            fast->next->next = head;
        }
        k = k%n;
        for(int i = 1; i < n-k; i++){
            head = head->next;
        }
        ListNode* p = head->next;
        head->next = NULL;
        return p;
    }
};