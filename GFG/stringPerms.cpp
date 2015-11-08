#include <bits/stdc++.h>

using namespace std;

void nextHigherPerm(string perm)
{
	int i = 0, k = 0;
	for(i = (perm.size() - 2); i >= 0 && ( perm[i] >= perm[i+1] ); i--);
	if(i == -1)
		return;
	k = i+1;
	for(int j = i + 1; j < (perm.size()); j++)
		if(perm[j] > perm[i] && perm[j] < perm[k])
			k = j;
	swap(perm[i], perm[k]);
	sort(perm.begin() + i + 1, perm.end());
	cout<<perm<<endl;
	nextHigherPerm(perm);
}

void printPerms(string str, int l, int r)
{
	if(l == r)
		cout<<str<<endl;
	else
	{
		for(int i = l; i <= r; i++)
		{
			swap(str[l], str[i]);
			printPerms(str, l+1, r);
			swap(str[l], str[i]);
		}
	}
}

int main(int argc, char const *argv[])
{
	string s;
	cin>>s;
	sort(s.begin(), s.end());
	cout<<s<<endl;
	nextHigherPerm(s);	
	//printPerms(s, 0, s.size()-1);
	return 0;
}
