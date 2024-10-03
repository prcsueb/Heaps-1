/*
**Time Complexity (TC):** O(N log K)

**Space Complexity (SC):** O(log K)

Where:
- `N` is the total number of elements across all linked lists.
- `K` is the number of linked lists.
*/

class Solution {
public:
    ListNode *mergeSortedLists(ListNode *first, ListNode *second) {
        ListNode *start = new ListNode(-1);
        ListNode *returnNode = start;
        while(first && second) {
            if(first->val <= second->val) {
                start->next = first;
                first=first->next;
            } else {
                start->next = second;
                second=second->next;
            }
            start=start->next;
        }
        if(first) {
            start->next=first;
        }
        if(second) {
            start->next=second;
        }
        return returnNode->next;
    }
    ListNode* merge(vector<ListNode*>& lists, int low, int high) {
        if(low == high) return lists[low];
        int mid = low + (high - low) / 2;
        ListNode *firstSortedList = merge(lists, low, mid);
        ListNode *secondSortedList = merge(lists, mid + 1, high);
        return mergeSortedLists(firstSortedList, secondSortedList);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        return merge(lists, 0, lists.size()-1);
    }
};