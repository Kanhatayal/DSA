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
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* before = dummy;
        ListNode* prev = head;
        ListNode* curr = head->next;
        while(prev && curr){
            prev->next = curr->next;
            curr->next = prev;
            before->next = curr;
            before = prev;
            prev = prev->next;
            if(prev) curr = prev->next;
        }
        return dummy->next;
    }
};