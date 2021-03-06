typedef long long ll;
const int lim = 1e6+10;
int spf[lim];//spf[i]=smallest prime factor of i
void sieve(int lim){
	iota(spf,spf+lim,0);//initially spf[i]=i
	for(int i=2;i<lim;i++){
		if(spf[i]==i){
			if((ll)i*i > lim)continue;
			for(int j=i*i;j<lim;j+=i){
				if(spf[j]==j)spf[j]=i;
			}
		}
	}
}
template<class T>
void getPrimes(int x, T get){
    while(x != 1){
        int p = spf[x];
        while(x%p==0){
            x/=p;
        }
        get(p);
    }
    return;
}

vector<int> getDivisors(int x){
	vector<int>divisors({1});
	while(x!=1){
		int p=spf[x];
		int e=0;
		while(x%p==0){x/=p;e++;}
		int n = (int)divisors.size();
		for(int i=0;i<n;i++){
			int u = divisors[i];
			for(int j=1,v=p;j<=e;j++,v*=p){
				divisors.push_back(u*v);
			}
		}
	}
	return divisors;
}
