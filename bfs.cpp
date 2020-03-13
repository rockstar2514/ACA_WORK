#include <bits/stdc++.h>
using namespace std;
#define loop(i,a,n) for (int i=a;i<n;i++)
#define loopm(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<long long> VI;
typedef long long ll;
typedef pair<int,int> PII;
typedef double db;
struct Node
{
    ll val;
    Node* next;
};
void enqueue(Node** head,ll data)
{
Node* newp=new Node;
newp->val=data;
newp->next=NULL;
Node* temp=*head;
if(*head==NULL)
{*head=newp;}else{//not understood
while(temp->next!=NULL)
{
    temp=temp->next;

}

temp->next=newp;}
}
int dequeue(Node** head)
{


    Node* tmp=*head;
    *head=(*head)->next;
    int a=tmp->val;
    delete(tmp);
    return a;

}
int main()
{
//    /ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    cout.tie(0);
    cout<<"Enter Number of vertices\n";
    ll n;
    cin>>n;
    vector<Node*> v(n);
    loop(i,0,n)
    {
        cout<<"Enter connection for vertex (-1) for terminate"<<i<<"\n";
        ll inp=-1;
        cin>>inp;
        while(inp!=-1)
        {
            enqueue(&v[i],inp);//please this is not an actual queue just implemented as one
            cin>>inp;

        }

    }
    vector<bool> visit(n,0);
    visit[0]=1;
    Node* head=new Node;
    head->val=0;
    head->next=NULL;
    while(head!=NULL)
    {
        ll curr=dequeue(&head);
        Node* tmp=v[curr];
        while((tmp->next)!=NULL)
        {
            tmp=tmp->next;
            ll get=tmp->val;
            if(visit[get]!=1)
            {
               enqueue(&head,get);
               visit[get]=1;
            }

        }
    }
}
