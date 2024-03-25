#include<iostream>
#include <bits/stdc++.h>
using namespace std;

const int diagonal=1;

int maxLength=0;

unordered_set<string> results;

void printMatrix(const vector<vector<int>>& matrix){
  for(const auto& row:matrix){
    for(int val:row){
      cout<< val << " "; 
    }
    cout << endl;
  }

}

void printSequences(const vector<vector<int>>& cost ,const vector<vector<int>>& direction,const string& s1,const string& s2,int n, int m ,string seq ){

  if(n==0||m==0){
    results.insert(seq);
    return;
  }

  string helper=seq;

  if(direction[n][m]==diagonal){
    helper+=s1[m-1];
    printSequences(cost ,direction,s1,s2,n-1,m-1,helper);
  }
  else{
    if(cost[n-1][m]==cost[n][m-1]){
      printSequences(cost,direction,s1,s2,n-1,m,helper);
      printSequences(cost ,direction ,s1,s2,n,m-1,helper);
    }
    else if(cost[n-1][m]==cost[n][m]){
      printSequences(cost,direction,s1,s2,n-1,m,helper);
    }
    else{
      printSequences(cost,direction,s1,s2,n,m-1,helper);
    }
  }
}

void computeLcs(const string& s1, const string& s2){
  int m=s1.length();
  int n=s2.length();

  //cost matrix
  vector<vector<int>> cost(n+1,vector<int>(m+1,0));
  //direction matrix
  vector<vector<int>> direction(n+1,vector<int>(m+1,0));

  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      if(s1[i-1]==s2[j-1]){
        cost[i][j]=cost[i-1][j-1]+1;
        direction[i][j]=diagonal;
      }
      else{
        cost[i][j]=max(cost[i-1][j],cost[i][j-1]);
      }

    }
  }

  maxLength=cost[n][m];

  cout << "Cost Matrix" << endl;
  printMatrix(cost);

  cout<< "Direction matrix" <<endl;

  printMatrix(direction);


  printSequences(cost,direction,s1,s2,n,m,"");

  for(const string& s:results){
    cout<< s << endl;
  }
}


int main(){
  string s1="abaaba";
  string s2="babbab";
  computeLcs(s1,s2);

  return 0;
}