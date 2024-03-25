#include<iostream>
#include<bits/stdc++.h>
using namespace std;

const int diagonal =1;
int maxlen= 0;
unordered_set<string> result;

void printmat(const vector<vector<int>>& matrix)
{
    for(const auto& row:matrix)
    {
        for(int val: row)
        {
            cout<<val<<" ";
        }
        cout<<endl;
    }
}
void printseq(const vector<vector<int>>& cost, vector<vector<int>>& direcn, const string& s1, const string& s2,int n, int m, string seq)
{
     if(n==0 || m==0)
     {
        result.insert(seq);
        return;
     }
     string helper = seq;
     if(direcn[n][m]==diagonal)
     {
        helper+=s1[m-1];
        printseq(cost,direcn,s1,s2,n-1,m-1,helper);
     }
     else
     {
        if(cost[n-1][m]== cost[n][m-1])
        {
            printseq(cost,direcn,s1,s2,n-1,m,helper);
            printseq(cost,direcn,s1,s2,n,m-1,helper);   
        }
        else if(cost[n-1][m]==cost[n][m])
        {
            printseq(cost,direcn,s1,s2,n-1,m,helper);
        }
        else
        printseq(cost,direcn,s1,s2,n,m-1,helper);
     }
}
void computeLCS(const string& s1, const string& s2)
{
    int m = s1.length();
    int n = s2.length();
    vector<vector<int>>cost(n+1,vector<int>(m+1,0));
    vector<vector<int>>direcn(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s1[i-1]==s2[j-1])
            {
                cost[i][j] = cost[i-1][j-1]+1; 
                direcn[i][j] = diagonal;
            }
            else
            {
               cost[i][j]= max(cost[i-1][j],cost[i][j-1]);
            }
        }
    }
    maxlen = cost[n][m];
    cout<<endl;
    cout<<"cost matrix:"<<endl;
    printmat(cost);

    cout<<endl;
    cout<<"direction mat:"<<endl;
    printmat(direcn);
    printseq(cost,direcn,s1,s2,n,m,"");
    for(const string&s : result ){
        cout<<s<<endl;
    }
}
int main()
{
    string s1="abaaba";
    string s2 = "babbab";
    computeLCS(s1,s2);
    return 0;
}