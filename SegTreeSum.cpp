vector < ll > t;
vector < ll > a;
void build(ll v,ll tl,ll tr)
{
      if(tl==tr)
      {
           t[v]=a[tl];
      }
      else
      {
           ll tm=(tl+tr)/2;
           build(v*2,tl,tm);
           build(v*2+1,tm+1,tr);
           t[v]=t[v*2]+t[v*2+1];
      }

}


void getSegTree(ll n)
{
       t=vector< ll> (4*n);
       build(1,0,n-1);

}
ll sum(ll v, ll tl,ll tr, ll l, ll r)
{
       if(l>r)
           return 0;
       if(l==tl && r==tr)
       {
        return t[v];
       }
       ll tm=(tl+tr)/2;
       return sum(v*2,tl,tm,l,std::min(r,tm))+sum(v*2+1,tm+1,tr,std::max(l,tm+1),r);
}
//call by incidices purely
void update(ll tl, ll tr,ll pos, ll new_val)
{
       if(tl==tr)
        t[v]=new_val;
        else
        {
            ll tm=(tl+tr)/2;
            if(pos<=tm)
                update(v*2,tl,tm,pos,new_val);
            else
                update(v*2+1,tm+1,tr,pos,new_val);
            t[v]=t[v*2]+t[v*2+1];

        }


}
