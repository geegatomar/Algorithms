#include<bits/stdc++.h>
using namespace std;
 
 
const int N = 1e6, logN = 20;
int n = 7, m, k, dots = 0, cou = 0, yes = 0, r, wt, sum = 0, d;

int reset[100];

void precompute(string pat)
{
    int len = 0, i = 1;
    while(i < m)
    {
        if(pat[len] == pat[i])
        {
            len++;
            reset[i] = len;
            i++;
        }
        else
        {
            if(len != 0)
                len = reset[len - 1];
            else
                reset[i] = 0, i++;
        }
    }
}

int KMP(string txt, string pat)
{
    int i = 0, j = 0;
    while(i < n)
    {
        if(txt[i] == pat[j])
            i++, j++;
        else
        {
            if(j != 0)
                j = reset[j - 1];
            else
                i++;
        }
        if(j == m)
            return i - j;
    }
    return -1;
}

int32_t main()
{
    
    string txt, pat;
    cin >> txt >> pat;
    n = txt.size(), m = pat.size();
    precompute(pat);
    cout << KMP(txt, pat);

}
