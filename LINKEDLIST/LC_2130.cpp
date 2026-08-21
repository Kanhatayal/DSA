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
    ListNode* reverseList(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* after= head->next;
        while(curr){
            curr->next = prev;
            prev = curr;
            curr = after;
            if(after)
            after = after->next;
        }
        return prev;
    }
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* p = reverseList(slow->next);
        slow->next = NULL;
        int result = INT_MIN;
        while(head && p){
            result = max(result, head->val + p->val);
            head = head->next;
            p  = p->next;
        }
        return result;
    }
};