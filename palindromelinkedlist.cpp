#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

bool isPalindrome(ListNode *head)
{
    int n = 0, rem = 0, res = 0, temp;
    // cout << head->val << endl;
    while (head->next)
    {
        int num = head->val;
        n = (n * 10) + num;
        head = head->next;
    }
    temp = n;
    while (temp)
    {
        rem = temp % 10;
        res = (res * 10) + rem;
        temp = temp / 10;
    }

    if (res == n)
    {
        return true;
    }
    return false;
}

int main()
{
    ListNode *head = new ListNode;
    int n;
    cout << "enter number of nodes" << endl;
    cin >> n;
    int a[n];
    cout << "enter the node elements" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    head->val = a[0];
    ListNode *temp = new ListNode();
    temp = head;

    for (int i = 1; i <= n; i++)
    {
        ListNode *temp2 = new ListNode;
        temp2->val = a[i];
        temp2->next = NULL;
        temp->next = temp2;
        temp = temp2;
    }

    int palindrome = isPalindrome(head);
    if (palindrome == 0)
    {
        cout << "not palindrome";
    }
    else
        cout << "Palindrome";
    return 0;
    // while (head->next)
    // {
    //     cout << head->val << " ";
    //     head = head->next;
    // }
}