

// link: https://leetcode.com/problems/merge-k-sorted-lists/description/

// method 1(brute force)
ListNode *mergeKLists(vector<ListNode *> &lists)
{
    int n = lists.size();
    vector<int> nums;
    for (int i = 0; i < n; i++)
    {
        ListNode *head = lists[i];
        while (head)
        {
            nums.push_back(head->val);
            head = head->next;
        }
    }
    sort(nums.begin(), nums.end());
    ListNode *dummy = new ListNode(-1);
    ListNode *temp = dummy;
    for (auto item : nums)
    {

        ListNode *newnode = new ListNode(item);
        temp->next = newnode;
        temp = newnode;
    }

    return dummy->next;
}

// method 2(optimize - recursion)
class Solution
{
public:
    ListNode *merge_two_sorted_list(ListNode *l1, ListNode *l2)
    {

        if (l1 == NULL)
        {
            return l2;
        }

        if (l2 == NULL)
        {
            return l1;
        }

        if (l1->val < l2->val)
        {
            l1->next = merge_two_sorted_list(l1->next, l2);
            return l1;
        }
        else
        {

            l2->next = merge_two_sorted_list(l1, l2->next);
            return l2;
        }
        return NULL;
    }
    ListNode *partician(int start, int end, vector<ListNode *> lists)
    {

        if (start == end)
            return lists[start];

        if (start > end)
            return NULL;
        int mid = start + (end - start) / 2;
        ListNode *l1 = partician(start, mid, lists);
        ListNode *l2 = partician(mid + 1, end, lists);

        return merge_two_sorted_list(l1, l2);
    }

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {

        int k = lists.size();
        return partician(0, k - 1, lists);
    }
};