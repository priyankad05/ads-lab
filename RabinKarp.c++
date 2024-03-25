#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  string text,pattern;
  cout<<"Enter the text :"<< endl;
  cin>>text;
  cout<<"Enter the pattern :"<<endl;
  cin>>pattern;

  n=text.length();
  m=pattern.length();
  int q=13,d=10,h=1,p=0,t0=0;

  for(int i=0;i<m-1;i++){
    h=(h*q)%d;
  }

  for(int i=0;i<m;i++){
    p=(d*p+pattern[i])%q;
    t0=(d*t0+text[i])%q;

  }

  for(int s=0;s<=n-m;s++){
    if(p==t0){
      int i;
      for(i=0;i<m;i++){
        if(text[s+i]!=pattern[i])
        break;

      }
      if(i==m)
        cout<<"Pattern occurs with shift:"<<s<<endl;

    }

      if(s<n-m){
        t0=(d*(t0-text[s]*h)+text[s+m])%q;

      }

      if (t0 < 0) {
        t0 = (t0 + q) % q;
        }

    }
}

