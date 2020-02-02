#include<iostream>
using namespace std;
int level(int n)
{
if(n!=1)
{
int sum=0;

for(int i=n-1;i>=1;i++)
{
sum=sum+level(i);
}
}
else
{
return 1;
}
}

int main()
{

level[100];


}
/* Complexity of this program is n^n */
