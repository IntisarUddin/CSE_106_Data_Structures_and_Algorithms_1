#include <iostream>
#include <string>
using namespace std;

const int N = 1000;
int dp[N][N];

bool isMatch(int i, int j, string &str1, string &str2)
{

    if (i >= str1.length() && j >= str2.length())
    {
        return true;
    }

    if (j >= str2.length())
    {
        return false;
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    if (j + 1 < str2.length() && str2[j + 1] == '*')
    {

        dp[i][j] = (i < str1.length() && (str1[i] == str2[j] || str2[j] == '.') && isMatch(i + 1, j, str1, str2));
        dp[i][j] |= isMatch(i, j + 2, str1, str2);
    }
    else if (j + 1 < str2.length() && str2[j + 1] == '+')
    {

        dp[i][j] = (i < str1.length() && (str1[i] == str2[j] || str2[j] == '.') && isMatch(i + 1, j, str1, str2));
        dp[i][j] |= (i < str1.length() && (str1[i] == str2[j] || str2[j] == '.') && isMatch(i + 1, j + 2, str1, str2));
    }
    else if (i < str1.length() && (str2[j] == '.' || str1[i] == str2[j]))
    {
        dp[i][j] = isMatch(i + 1, j + 1, str1, str2);
    }
    else
    {
        dp[i][j] = false;
    }
    return dp[i][j];
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    string str1, str2;
    cin >> str1 >> str2;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            dp[i][j] = -1;
        }
    }
    bool ans = isMatch(0, 0, str1, str2);
    if (ans)
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }
    return 0;
}