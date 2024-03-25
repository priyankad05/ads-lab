#include <bits/stdc++.h>
using namespace std;

vector<int> ComputeLpsArray(string pattern,int m){
  int len=0;
  int i=1;
  vector<int> lps(m);


  while(i<m){
    if(pattern[i]==pattern[len]){
      lps[i]=len+1;
      len++;
      i++;

    }
    else{
      if(len!=0)
      len=lps[len-1];
      else{
      lps[i]=0;
      i++;
      }
    }
  }
  return lps;
}

int main(){
  int n,m;

  string text,pattern;

  cout<<"Enter the text:" <<endl;
  cin>>text;
  cout<<"Enter the pattern:" <<endl;
  cin>>pattern;

  n=text.length();
  m=pattern.length();

  vector<int> lpsArr=ComputeLpsArray(pattern,m);
  for(int i=0;i<lpsArr.size();i++)
  cout<< lpsArr[i]<<" " << endl;
  

  int shifts=0;
  int i=0;
  int j=0;

  while(i<n){
    if(text[i]==pattern[j]){
      i++;
      j++;
    }
    else{
      if(j!=0)
      j=lpsArr[j-1];
      else
      i++;
    }

    if(j==m){
      cout<< "The pattern is found at the position"<<" " << i-j<<endl;
      j=lpsArr[j-1];
    }

    shifts++;
  }
  cout<< "Shifts:" <<shifts<< endl;
  
  return 0;

}