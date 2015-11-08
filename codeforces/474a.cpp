#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

#define ulint unsigned long long int
#define lint long long int
#define VI vector<int>
#define VLL vector<lint>
#define VB vector<bool>
#define VVLL vector< VLL >
#define ci(i) cin>>i
#define co(i) cout<<i<<endl
#define FOR(i,j,n) for(lint i=j;i<n;i++)
#define pb push_back
#define s(v) v.size()

int main()
{	_
	map<char, char> left, right;

	left['w'] = 'q';
	left['e'] = 'w';
	left['r'] = 'e';
	left['t'] = 'r';
	left['y'] = 't';
	left['u'] = 'y';
	left['i'] = 'u';
	left['o'] = 'i';
	left['p'] = 'o';
	left['s'] = 'a';
	left['d'] = 's';
	left['f'] = 'd';
	left['g'] = 'f';
	left['h'] = 'g';
	left['j'] = 'h';
	left['k'] = 'j';
	left['l'] = 'k';
	left[';'] = 'l';
	left['x'] = 'z';
	left['c'] = 'x';
	left['v'] = 'c';
	left['b'] = 'v';
	left['n'] = 'b';
	left['m'] = 'n';
	left[','] = 'm';
	left['.'] = ',';
	left['/'] = '.';
	

	right['w'] = 'e';
	right['e'] = 'r';
	right['r'] = 't';
	right['t'] = 'y';
	right['y'] = 'u';
	right['u'] = 'i';
	right['i'] = 'o';
	right['o'] = 'p';
	right['q'] = 'w';
	right['s'] = 'd';
	right['d'] = 'f';
	right['f'] = 'g';
	right['g'] = 'h';
	right['h'] = 'j';
	right['j'] = 'k';
	right['k'] = 'l';
	right['l'] = ';';
	right['a'] = 's';
	right['x'] = 'c';
	right['c'] = 'v';
	right['v'] = 'b';
	right['b'] = 'n';
	right['n'] = 'm';
	right['m'] = ',';
	right[','] = '.';
	right['.'] = '/';
	right['z'] = 'x';

	char choice;
	string s;
	cin>>choice>>s;

	if(choice == 'L')
	{
		FOR(i, 0, s.length())
		{
			s[i] = left[s[i]];
		}
	}
	else
	{
		FOR(i, 0, s.length())
		{
			s[i] = right[s[i]];
		}
	}

	cout<<s;
	return 0;
}