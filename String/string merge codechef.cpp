#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

string  a, b;
int t, n, m;

int arr[5002][5002];

int longestCommonSubsequence(string text1, string text2) {
    int N1 = text1.length(), N2 = text2.length();
    memset(arr, 0, sizeof(arr));
    for (int i = 1; i <= N1; ++i)
    {
        for (int j = 1; j <= N2; ++j)
        {
            if (text1[i - 1] == text2[j - 1])
                arr[i][j] = arr[i - 1][j - 1] + 1;
            else
                arr[i][j] = max(arr[i][j - 1], arr[i - 1][j]);
        }
    }
    return arr[N1][N2];
}

int main() {
    cin >> t;
    while (t--)
    {
        cin >> n >> m>>a>>b;
        auto it = unique(a.begin(), a.end());
        a.resize(distance(a.begin(), it));
        it = unique(b.begin(), b.end());
        b.resize(distance(b.begin(), it));
        cout << (a.size() + b.size() - longestCommonSubsequence(a, b)) << endl;
    }
    return 0;
}