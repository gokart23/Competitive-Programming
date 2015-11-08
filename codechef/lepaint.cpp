#include "algorithm"
#include "cstdio"
#include "vector"
#include "cmath"

typedef unsigned long long int ulint;
typedef long long int lint;

using namespace std;

int main(int argc, char const *argv[])
{
	ulint testcases=0, n=0, k=0;
	int d = 0;
	double c=0;

	scanf("%llu", &testcases);

	while(testcases--)
	{
		scanf("%llu %lf %llu", &n, &c, &k);
		d = (int)c;
		int index = 0;
		double col[d], temp[d], prob[d][d], sum=0.0f;
		vector<int> factors, vals(n);

		prob[0][0] = 1;

		for (int j = d-1; j > 0; --j)
		{
			if(d%j == 0 && j != 1)
				factors.push_back(j);
			for (int k = 0; k < c; ++k)
			{
				prob[j][k] = (double)1/c;				
			}			
		}

		sort(factors.begin(), factors.end());

		for (int j = (factors.size() - 1); j >= 0 ; --j)
		{	
			for(int k = 0; k < d; k++)
			{
				if(k%factors[j]==0)
					prob[factors[j]][k] = 1/(c/factors[j]);
				else
					prob[factors[j]][k] = 0;
			}
			for (int k = 2*factors[j]; k < d; k += factors[j])
			{
				if(fabs(prob[k][0] - (1/c)) > 1e-4)
				{
					continue;
				}
				else
				{
					// cout<<factors[j]<<": "<<k<<endl;
					// printf("%d : %d\n", factors[j], k);
					for (int l = 0; l < d; ++l)
					{
						if(l % factors[j] == 0)
							prob[k][l] = 1/(c/factors[j]);	
						else
							prob[k][l] = 0;
					}
					
				}
			}			
		}
		
		for (int i = 0; i < k; ++i)
		{
			int m=0, n=0;
			scanf("%d %d", &m, &n);
			for (int l = --m; l < n; ++l)
			{
				// printf("%d : %d -> %d\n", l, vals[l], vals[l] + 1);
				vals[l]++;
			}
			// printf("\n");
		}

		sort(vals.begin(), vals.end());

		// for (int i = 0; i < vals.size(); ++i)
		// {
		// 	printf("vals(%d): %d\n", i, vals[i]);
		// }
		for (int i = 0; i < d; ++i)
		{
			col[i] = 0;
		}
		col[1] = 1;

		while(vals[index] == 0)
		{
			sum += 1;
			index++;
		}

		for(int l = 1;index != n; ++l)
		{
			// printf("%d %d\n", l, vals[index]);
			copy(col, col + d, temp);
			
			for (int i = 0; i < d; ++i)
			{
				col[i] = temp[i];
				for (int j = 1; j < d; ++j)
				{
					col[i] += (temp[j] * prob[j][i]);
				}

				col[i] *= 0.5f;
			}
			
			if(vals[index] < l)
			{
				for(;vals[index] < l && index <= n;index++);
			}

			if(index != n && vals[index] == l)
			{
				double tempSum = 0.0f;
				// printf("%f +=", sum);
				for (int j = 0; j < c; ++j)
				{
					// printf("%f(%d, %f) + ", j*col[j], j, col[j]);
					tempSum += (j*col[j]);
				}
				while(vals[index] == l)
				{
					sum += tempSum;
					index++;
				}
				// printf("\n");
			}
		}

		printf("%.9f\n", sum);
		// for (int i = 0; i < d; ++i)
		// {
		// 	for (int j = 0; j < d; ++j)
		// 	{
		// 		printf("%.8lf, ", prob[i][j]);
		// 	}
		// 	printf("\n");
		// }
	}

	return 0;
}