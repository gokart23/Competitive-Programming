#include "iostream"
#include "climits"

using namespace std;

struct TreeNode 
{
	TreeNode *left, *right;
	char val;
};



int findClosest(TreeNode *root, char key, TreeNode *ancestors, int level)
{
	if (!root)
		return INT_MAX;
	if (root->val == key)
	{
		int down_min = closestDown(root);
		int ancestors_min = INT_MAX;
		for (int i = 0; i < index; ++i)
		{
			
		}
	}
}

int main(int argc, char const *argv[])
{
	
	return 0;
}