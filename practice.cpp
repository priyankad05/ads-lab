#include <bits/stdc++.h>
using namespace std;

void lps(string p, int m, int lpsa[])
{
    int len =0, i=1;
    lpsa[0]=0;
    while(i<m){
    if(p[i]==p[len])
    {
        lpsa[i] = len+1;
        len++;
        i++;
    }
    else
    {
        if(len!=0)
        {
            len = lpsa[len -1];
        }
        else
        {
            lpsa[i]=0;
            i++;

        }
    }
    }
}
void kmp(string pat, string txt)
{
    int n = txt.length();
    int m = pat.length();
    int lpsa[m];
    int shift =0;
    lps(pat,m,lpsa);
    int i=0,j=0;
    while(i<n){
        if(txt[i]==pat[j])
        {
            cout<<"checking "<<txt[i]<<" and "<<pat[j]<<endl;
            i++;
            j++;
        }
        else{
            if(j!=0)
            {
                j = lpsa[j-1];
                cout<<"mismatch j to "<<lpsa[j-1]<<" ie "<<pat[j]<<endl;
                shift++;
            }
            else{
                i++;
                cout<<"mismath i to "<<i<<" ie "<<txt[i]<<endl;
                shift++;
            }
        }
        if(j==m)
        {
            if(shift!=0){
            shift++;
            }
            cout<<endl;
            cout<<"found at:"<<i-j;
            cout<<endl<<"shift:"<<shift;
            j = lpsa[j-1];
        }
    }
}
int main() {
    string pat, txt;
    cout << "Enter the string" << endl;
    getline(cin,txt);
    cout << "Enter the pattern to be searched" << endl;
    getline(cin,pat);
    kmp(pat, txt);
    return 0;
}