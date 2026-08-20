/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        if (head == NULL || head->next == NULL)
            return head;

        // Calculate length
        int n = 0;
        ListNode* temp = head;
        while (temp) {
            n++;
            temp = temp->next;
        }

        int pos1 = k;
        int pos2 = n - k + 1;

        if (pos1 == pos2)
            return head;

        // Make sure pos1 < pos2
        if (pos1 > pos2)
            swap(pos1, pos2);

        ListNode *prev1 = NULL, *curr1 = head;
        for (int i = 1; i < pos1; i++) {
            prev1 = curr1;
            curr1 = curr1->next;
        }

        ListNode *prev2 = NULL, *curr2 = head;
        for (int i = 1; i < pos2; i++) {
            prev2 = curr2;
            curr2 = curr2->next;
        }

        // Adjacent nodes
        if (curr1->next == curr2) {

            if (prev1)
                prev1->next = curr2;
            else
                head = curr2;

            curr1->next = curr2->next;
            curr2->next = curr1;
        }
        else {

            if (prev1)
                prev1->next = curr2;
            else
                head = curr2;

            if (prev2)
                prev2->next = curr1;
            else
                head = curr1;

            ListNode* tempNext = curr1->next;
            curr1->next = curr2->next;
            curr2->next = tempNext;
        }

        return head;
    }
};