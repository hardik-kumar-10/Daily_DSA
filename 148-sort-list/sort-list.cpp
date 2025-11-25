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
    // Function to merge two sorted linked lists
    ListNode* mergeTwoSortedLinkedLists(ListNode* list1, ListNode* list2) {
        // Create a dummy node
        ListNode* dummyNode = new ListNode(-1);
        
        // Temp pointer to build merged list
        ListNode* temp = dummyNode;

        // Traverse both lists
        while (list1 != nullptr && list2 != nullptr) {
            // Choose smaller node
            if (list1->val <= list2->val) {
                temp->next = list1;
                list1 = list1->next;
            } else {
                temp->next = list2;
                list2 = list2->next;
            }
            // Move temp pointer
            temp = temp->next;
        }

        // Attach remaining nodes
        if (list1 != nullptr) {
            temp->next = list1;
        } else {
            temp->next = list2;
        }

        // Return head of merged list
        return dummyNode->next;
    }

    // Function to find middle of linked list
    ListNode* findMiddle(ListNode* head) {
        // If list empty or single node
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        // Slow and fast pointers
        ListNode* slow = head;
        ListNode* fast = head->next;

        // Move fast twice as fast as slow
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Return middle node
        return slow;
    }

    // Function to perform merge sort
    ListNode* sortList(ListNode* head) {
        // Base case: empty or single node
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        // Find middle node
        ListNode* middle = findMiddle(head);

        // Split into two halves
        ListNode* right = middle->next;
        middle->next = nullptr;
        ListNode* left = head;

        // Recursively sort both halves
        left = sortList(left);
        right = sortList(right);

        // Merge sorted halves
        return mergeTwoSortedLinkedLists(left, right);
    }
};