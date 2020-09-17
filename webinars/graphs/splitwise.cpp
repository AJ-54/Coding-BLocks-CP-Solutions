#include <iostream>
#include <set>
using namespace std;


int main(){
	int p,t; // p-number of person, t-number of transactions
	cin>>p>>t;
	int arr[10000]={0};

	for(int i=0;i<t;i++){
		int p1,p2,amount;
		cin>>p1>>p2>>amount;

		arr[p1] -= amount;
		arr[p2] += amount;
	}

	multiset<pair<int,int> > s;
	
	for(int i=0;i<p;i++){
		s.insert(make_pair(arr[i],i));
	}

	while(!s.empty()){
		// do something
		auto front = *(s.begin());
		s.erase(s.begin());
		auto end = *(prev(s.end()));
		s.erase(prev(s.end()));

		int front_amount = front.first;
		int front_person = front.second;

		int end_amount = end.first;
		int end_person = end.second;

		int settlement_amount = min(-1*front_amount,end_amount);

		front_amount += settlement_amount;
		end_amount -= settlement_amount;

		cout<<"Person "<<front_person<<"Pays "<<settlement_amount<<" to person"<<end_person<<endl;

		if(front_amount){
			s.insert(make_pair(front_amount,front_person));
		}
		if(end_amount){
			s.insert(make_pair(end_amount,end_person));
		}
	}


	return 0;
}