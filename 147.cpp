// 147. Insertion Sort List


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
    ListNode* insertionSortList(ListNode* head) {
        if (!head)
            return nullptr;

        std::vector<int> arr;
        ListNode* current = head;

        while (current) {
            arr.push_back(current->val);
            current = current->next;
        }

        for (int i = 1; i < arr.size(); i++) {
            int currVal = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > currVal) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = currVal;
        }

        current = head;
        for (int i = 0; i < arr.size(); i++) {
            current->val = arr[i];
            current = current->next;
        }

        return head;
    }
};
