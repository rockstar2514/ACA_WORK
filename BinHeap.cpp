class BHeap{
private:
	vector<ll> heap;
	ll l(ll parent);
	ll r(ll parent);
	ll par(ll child);
	void heapifyup(ll index);
	void heapifydown(ll index);
public:
	BHeap(){}
	void insert(ll element);
	void deleteMin();
	void extractMin();
	void showHeap();
	ll size();
}
ll BHeap::size(){
	return heap.size();
}
void BHeap::insert(ll elem)
{
	heap.pb(elem);
	heapifyup(heap.size()-1);

}
void BHeap::deleteMin(){
	if(heap.size()==0)
	{
          cout<<"Error here bro::size is 0";
	}else
	{
          heap[0]=heap.back();
          heap.pop_back();//O(1)
          heapifydown(0);
	}
}
void BHeap::ExtractMin(){if(heap.size()==0){cout<<"Bhak **";}else{return heap.front();}}
void BHeap::showHeap(){
	vector < ll>::iterator pos=heap.begin();
	while(pos!=heap.end())
	{
		cout<<*pos<<" ";
		pos++;
	}

}
ll BHeap::l(ll parent){
	ll l=2*parent+1;
	if(l<heap.size())
		return l;
	else
		return -1;
}
ll BHeap::l(ll parent){
	ll r=2*parent+2;
	if(r<heap.size())
		return r;
	else
		return -1;
}
ll BHeap::par(ll child){
	ll p=(child-1)/2;
	if(child==0)
		return -1;
	else return p;
}
void BHeap::heapifyup(ll in){
	if(in>=0&&par(in)>=0&&heap[par(in)]>heap[in]){
		ll tmp=heap[in];
		heap[in]=heap[par(in)];
		heap[par(in)]=tmp;
		heapifyup(par(in));
	}
}
void BHeap::heapifydown(ll in){
	ll child=l(in);
	ll child1=r(in);
	if(child>=0&child1>=0&&heap[child] > heap[child1])
		child=child1;
	if(child>0&&heap[in]>heap[child]]){
		ll t=heap[in];
		heap[in]=heap[child];
		heap[child]=t;
		heapifydown(child);
	}
}
