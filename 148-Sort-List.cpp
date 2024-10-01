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
// class Solution {
// public:
//     ListNode* findMiddle(ListNode* head){
//         ListNode* slow = head;
//         ListNode* fast = head->next;
//         while(fast != NULL && fast->next != NULL){
//             slow = slow->next;
//             fast = fast->next->next;
//         }
//         return slow;
//     }
//     ListNode* mergeL(ListNode* leftHead,ListNode* rightHead){
//         ListNode* dummy = new ListNode(-1);
//         ListNode* temp = dummy;
//         while(leftHead != NULL && rightHead != NULL){
//             if(leftHead->val <=rightHead->val){
//                 temp->next = leftHead;
//                 temp = leftHead;
//                 leftHead = leftHead->next;
//             }
//             else{
//                 temp->next = rightHead;
//                 temp = rightHead;
//                 rightHead = rightHead->next;
//             }
//             temp = temp->next;
//         }
//         if(leftHead != nullptr){
//             temp->next = leftHead;
           

//         }
//         if(rightHead != nullptr){
//             temp->next = rightHead;
//         }
//         return dummy->next;
           

//     }
//     ListNode* sortList(ListNode* head) {
//         if(head == NULL || head->next == NULL) return head;
//         ListNode* middle = findMiddle(head); 
//          ListNode* rightHead = middle->next;
//          middle->next = nullptr;
//         ListNode* leftHead = head;
      
        
//         leftHead = sortList(leftHead);
//         rightHead = sortList(rightHead);

//         return mergeL(leftHead,rightHead);
        
//     }
// };

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
    // Function to find the middle of the linked list
    ListNode* findMiddle(ListNode* head) {
        if (head == nullptr) {
            return nullptr; // Check for null
        }
        
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }

    // Function to merge two sorted linked lists
    ListNode* mergeL(ListNode* leftHead, ListNode* rightHead) {
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        while (leftHead != nullptr && rightHead != nullptr) {
            if (leftHead->val <= rightHead->val) {
                temp->next = leftHead;
                leftHead = leftHead->next;
            } else {
                temp->next = rightHead;
                rightHead = rightHead->next;
            }
            temp = temp->next; // Move to the next node
        }

        // Attach the remaining elements
        if (leftHead != nullptr) {
            temp->next = leftHead;
        }
        if (rightHead != nullptr) {
            temp->next = rightHead;
        }

        return dummy->next; // Return the merged list, skipping the dummy node
    }

    // Main function to sort the linked list
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head; // Base case: if list is empty or has one node
        }

        // Find the middle of the list
        ListNode* middle = findMiddle(head);
        ListNode* rightHead = middle->next;
        middle->next = nullptr; // Split the list into two halves
        ListNode* leftHead = head;

        // Recursively sort both halves
        leftHead = sortList(leftHead);
        rightHead = sortList(rightHead);

        // Merge the sorted halves
        return mergeL(leftHead, rightHead);
    }
};
