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
private:
    ListNode* reverseLinklist(ListNode* head){
        if(head == NULL || head->next == NULL ){
            return NULL;
        }
        ListNode* newHead = reverseLinklist(head->next);
        ListNode* front = head->next;
        front->next = head;
        head->next = NULL;
        return newHead;
    }

private:
    ListNode* findkth(ListNode* temp ,int k){
        k--;
        while(temp != NULL && k > 0){
            k--;
        
            temp = temp->next;

        }
        return temp;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
         ListNode* prevNode = NULL;
        
        while(temp != NULL){
            ListNode* kthNode = findkth(temp,k);
           
           
            if(kthNode == NULL){
                if(prevNode != NULL){
                    prevNode->next = temp;
                    
                }
                break;
            

            }
            ListNode* nextNode = kthNode->next;
            kthNode->next = NULL;
            reverseLinklist(temp);
            if(temp == head){
                head = kthNode;
            }
            else{
                prevNode->next = kthNode;

            }
            prevNode = temp;
            temp = nextNode;
            

 
        }
        return head;
        
    }
};