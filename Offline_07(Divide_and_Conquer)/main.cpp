#include <iostream>
#include <utility>
using namespace std;

pair<long long int, pair<int, int>> arraySum(int ara[], int mid, int low, int hi)
{
    long long int leftSum = INT64_MIN;
    int i = mid;
    long long int sum1 = 0;
    for (int k = mid; k >= low; k--)
    {
        sum1 += ara[k];
        if (sum1 > leftSum)
        {
            leftSum = sum1;
            i = k;
        }
    }
    long long int rightSum = INT64_MIN;
    int j = mid + 1;
    sum1 = 0;
    for (int k = mid + 1; k <= hi; k++)
    {
        sum1 += ara[k];
        if (sum1 > rightSum)
        {
            rightSum = sum1;
            j = k;
        }
    }

    return {leftSum + rightSum, {i, j}};
}

pair<long long int, pair<int, int>> SubArraySum(int ara[], int low, int hi)
{
    if (hi == low)
    {
        return {ara[low], {low, hi}};
    }

    int mid = (hi + low) / 2;

    pair<long long int, pair<int, int>> left, right, sum;

    left = SubArraySum(ara, low, mid);
    right = SubArraySum(ara, mid + 1, hi);

    sum = arraySum(ara, mid, low, hi);

    if (left.first >= right.first && left.first >= sum.first)
    {

        if (left.first == right.first)
        {
            if ((left.second.second - left.second.first) > (right.second.second - right.second.first))
            {

                return right;
            }
        }
        else if (left.first == sum.first)
        {
            if ((left.second.second - left.second.first) > (sum.second.second - sum.second.first))
            {

                return sum;
            }
        }
        return left;
    }

    else if (right.first > left.first && right.first >= sum.first)
    {

        if (right.first == sum.first)
        {
            if ((right.second.second - right.second.first) > (sum.second.second - sum.second.first))
            {

                return sum;
            }
        }
        return right;
    }

    return sum;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    int ara[n];
    for (int i = 0; i < n; i++)
    {
        cin >> ara[i];
    }

    pair<long long int, pair<int, int>> sum;

    sum = SubArraySum(ara, 0, n - 1);
    if (sum.first > 0)
    {

        cout << "[";
        for (int i = sum.second.first; i < sum.second.second; i++)
        {
            cout << ara[i] << ", ";
        }
        cout << ara[sum.second.second] << "] with a sum of " << sum.first << endl;
    }
    else
    {
        cout << "[] with a sum of 0" << endl;
    }
    return 0;
}