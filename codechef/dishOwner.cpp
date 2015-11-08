#include "cstdio"
#include "vector"

using namespace std;

typedef long long unsigned int ulint;
typedef long long int lint;

typedef struct ChefTag
{
	ulint maxScore, id;
	struct ChefTag *next;
} Chef;

int main(int argc, char const *argv[])
{
	ulint testcases=0, N=0, Q=0, queryType=0, x=0, y=0;

	scanf("%llu", &testcases);

	while(testcases--)
	{
		vector<ulint> dishes;
		vector<Chef> chefs;

		scanf("%llu", &N);
		dishes.reserve(N);
		chefs.reserve(N);

		for (ulint i = 0; i < N; ++i)
		{
			scanf("%llu", &chefs[i].maxScore);
			dishes[i] = i;
			chefs[i].next = NULL;
			chefs[i].id = i;
			
		}

		scanf("%llu", &Q);
		
		while(Q--)
		{
			scanf("%llu", &queryType);

			switch(queryType)
			{
				case 0:
				{
					scanf("%llu %llu", &x, &y);
					Chef *t1 = &chefs[dishes[--x]], *t2 = &chefs[dishes[--y]];
					while(t1->next != NULL)
						t1 = t1->next;
					while(t2->next != NULL)
						t2 = t2->next;
					if(t1->id == t2->id)
						printf("Invalid query!\n");
					else if(t1->maxScore > t2->maxScore)
					{
						chefs[dishes[y]].next = t1;
						t2->next = t1;
					}
					else if(t1->maxScore < t2->maxScore)
					{
						chefs[dishes[x]].next = t2;
						t1->next = t2;
					}
				}
					break;
				case 1:
				{
					scanf("%llu", &x);
					Chef *t = &chefs[dishes[--x]];
					while(t->next != NULL)
						t = t->next;
					printf("%llu\n", t->id + 1);
				}
					break;
			}
		}
	}

	return 0;
}