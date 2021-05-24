#include <iostream>
#include<string>
#include<vector>
#include<math.h>
using namespace std;

void merge (int arr[],int l, int mid, int r)
{
  int n1=mid-l+1;
  int n2=r-mid;
  int a[n1];
  int b[n2];
  for(int i=0;i<n1;i++)
  {
    a[i]=arr[l+i];
  }
  for(int i=0;i<n2;i++)
  {
    b[i]=arr[mid+1+i];
  }
  int i=0;
  int j=0;
  int k=l;
  while (i<n1 && j<n2)
  {
    if(a[i]<b[j])
    {
      arr[k]=a[i];
      k++;
      i++;
    }
    else
    {
      arr[k]=b[j];
      k++;
      j++;
    }
  }
  while(i<n1)
  {
    arr[k]=a[i];
    k++;
    i++;
  }
    while(j<n2)
  {
    arr[k]=b[j];
    k++;
    j++;
  }
}

int subsequenceofstring(string input,string output[])
{
  if(input.empty())
  {
    output[0]=" ";
    return 1;
  }
  string smallstring= input.substr(1);
  int smalloutputsize=subsequenceofstring(smallstring,output);
  for(int i=0;i<smalloutputsize;i++)
  {
    output[i+smalloutputsize]=input[0]+output[i];
  }
  return 2*smalloutputsize;
}

void mergesort(int arr[],int l,int r)
{
  if(l<r)
  {
    int mid=(l+r)/2;
    mergesort(arr,l,mid);
    mergesort(arr,mid+1,r);
    merge(arr,l,mid,r);
  }
} 

int staircase(int n)
{
  if(n==1)
  {
    return 1;
  }
  if(n==2)
  {
    return 2;
  }
  if(n==3)
  {
    return 4;
  }
  return staircase(n-1)+staircase(n-2)+staircase(n-3);
}

int staircaseunknown(int n,int o)
{
  if(n<0)
  {
    return 0;
  }
  if(n==0)
  {
    return 1;
  }
  int count=0;
  for(int i=1;i<=o;i++)
  {
    count=count+staircaseunknown(n-i, o);
  }
  return count;
}

int subsetofarray(int input[], int n,int startindex,int output[][20])
{
  if(n==0)
  {
    output[0][0]=0;
    return 1;
  }
  int smallsize=subsetofarray(input,n, startindex+1, output);
  for(int i=0;i<smallsize;i++)
  {
    output[i+smallsize][0]=output[i][0]+1;
    output[i+smallsize][1]=input[startindex];
    for(int j=1;j<=output[i][0];j++)
    {
      output[i+smallsize][j+1]=output[i][j];
    }
  }
  return 2*smallsize;
}
int subset(int input[],int n,int output[][20])
{
  return subsetofarray(input, n, 0, output);
}

int subsettok(int input[],int n,int startindex,int output[][50],int k)
{
  if(startindex==n)
  {
    if(k==0)
    {
      output[0][0]=0;
      return 1;
    }
    else
    {
      return 0;
    }
  }
  int smalloutput1[1000][50],smalloutput2[1000][50];
  int size1=subsettok(input,n,startindex+1,smalloutput1,k);
  int size2=subsettok(input,n,startindex+1,smalloutput2,k-input[startindex]);

  int row=0;
  for(int i=0;i<size1;i++)
  {
    for(int j=0;j<=smalloutput1[i][0];j++)
    {
      output[row][j]=smalloutput1[i][j];
    }
    row++;
  }
  for(int i=0;i<size2;i++)
  {
    output[row][0]=smalloutput2[i][0]+1;
    output[row][1]=input[startindex];
    for(int j=1;j<= smalloutput2[i][0];j++)
    {
      output[row][j+1]=smalloutput2[i][j];
    }
    row++;
  }
  return row;
}
int subsetstok(int input[],int n,int k,int output[][50])
{
  return subsettok(input,n,0,output,k);
}

int getcodes(string input,string output[])
{
  if(input[0]=='\0')
  {
    output[0]=" ";
    return 1;
  }
  int first= input[0]-48;
  char firstchar = first+'a'-1;
  char secondchar='\0';
  string smalloutput1[500];
  string smalloutput2[500];
  int size1 = getcodes(input.substr(1),smalloutput1);
  int size2=0;
  if (input[1]!='\0')
  {
    int second=first*10+input[1]-48;
    if(second>=10&& second<=26)
    {
      secondchar=second + 'a' -1;
      size2 = getcodes(input.substr(2),smalloutput2);
    }
  }
  int k=0;
  for(int i=0;i<size1;i++)
  {
    output[k]=firstchar+smalloutput1[i];
    k++;
  }
  for(int i=0;i<size2;i++)
  {
    output[k]=secondchar+smalloutput2[i];
    k++;
  }
  return k;
}
int main() 
{

  int arr[]={5,4,3,2,1,7};
  mergesort(arr, 0, 5);
  for(int i=0;i<6;i++)
  {
    cout<<arr[i]<<" ";
  }
  cout<<endl;
  string input;
  cin>>input;
  string *output=new string[1000];
  int count=subsequenceofstring(input, output);
  for(int i=0;i<count;i++)
  {
    cout<<output[i]<<endl;
  }
  cout<<staircase(4)<<endl;
  cout<<staircaseunknown(4, 5)<<endl;
}