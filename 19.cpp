//19. Remove Nth Node From End of List

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL) {
            return NULL; 
        }
        //count the number of nodes in the list
        ListNode* ptr = head;
        int count = 0;
        while (ptr != NULL) {
            ptr = ptr->next;
            count++;
        }
        //if we need to remove the head node
        if (count == n) {
            return head->next; // Return the new head
        }

        ListNode* prev = head;
        //we need to go to (count - n - 1)th node for the previous pointer
        for (int i = 0; i < count - n - 1; i++) {
            prev = prev->next;
        }
        
        //remove the nth node from the end
        prev->next = prev->next->next;

        return head; 
    }
};
