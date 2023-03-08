class Solution
{
public:
    // first approach(brute force)- O(n*m)
    int minEatingSpeed(vector<int> &piles, int h)
    {

        int k = 1;

        while (true)
        {

            long long ans = 0;
            for (auto num : piles)
            {

                ans += num / k;

                if (num % k != 0)
                {
                    ans++;
                }
            }

            if (ans <= h)
            {
                break;
            }
            k++;
        }

        return k;
    }
};

// second approach(binary search) -  O(log(max(m,n));
bool possible(vector<int> piles, int acctual_k, int h)
{
    long long ans = 0;
    for (auto num : piles)
    {
        ans += num / acctual_k;

        if (num % acctual_k != 0)
        {
            ans++;
        }
    }

    return ans <= h;
}
int minEatingSpeed(vector<int> &piles, int h)
{

    int l = 1;
    int r = *max_element(piles.begin(), piles.end());

    while (l < r)
    {

        int mid = l + (r - l) / 2;

        if (possible(piles, mid, h))
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }

    return l;
}
}
;