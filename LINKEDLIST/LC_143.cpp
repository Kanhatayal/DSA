class Solution {
public:
    ListNode* reverseList(ListNode* head){
        ListNode* prev = NULL;
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
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL) return;

        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* second = slow->next;
        slow->next = nullptr;

        second = reverseList(second);

        ListNode* first = head;

        while(second){
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;

            first->next = second;
            second->next= temp1;
            first = temp1;
            second = temp2;
        }
    }
};