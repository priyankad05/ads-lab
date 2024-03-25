#include <bits/stdc++.h>
using namespace std;

vector<int> computeLpsArray(string pattern , int m){
  int len=0;
  int i=1;
  vector<int> lps(m, 0);
  while(i<m){
    if(pattern[i]==pattern[len]){
      lps[i]=len+1;
      len++;
      i++;

    }
    else{
      if(len!=0)
      len=lps[len-1];
      else
      {
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
  vector<int> positions;


  cout << "Enter the text:" << endl;
  cin>>text;
  cout<< "Enter the pattern:" << endl;
  cin>>pattern;

  n=text.length();
  m=pattern.length();

  vector<int> lpsArr=computeLpsArray(pattern,m);

  int i=0,j=0;

  cout << "The lps array is :" << endl;
  for (int i=0;i<lpsArr.size();i++){
    
    cout << lpsArr[i] << endl;
  }

  int shifts=0;

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
      positions.push_back(i-j);
      j=lpsArr[j-1];
    }

    shifts++;
  }

  if(!positions.empty()){
    cout << " Pattern is found at the positions :" << endl;

    for(int pos:positions){
      cout << " " << pos;
    }
    cout << endl;

  }
  else{
    cout  << "Pattern not found in the text"<< endl;
  }
  cout << "The number of shifts are:" << shifts << endl;

  return 0;


}