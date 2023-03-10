class Solution
{
public:
    ListNode *head;
    int len = 0;
    Solution(ListNode *head)
    {
        this->head = head;
        ListNode *temp = head;

        while (temp != NULL)
        {
            temp = temp->next;
            len++;
        }
    }

    int getRandom()
    {

        int pos = rand() % len;

        ListNode *temp = head;

        while (pos--)
        {
            temp = temp->next;
        }

        return temp->val;
    }
};