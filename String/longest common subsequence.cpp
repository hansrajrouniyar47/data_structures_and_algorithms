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