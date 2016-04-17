/*

1)Given a BST ,Find its Maximum Height 

Height of a NULL BST is 0

Height of a BST which has only one node is 1

Ex Input : 

    10 
    /\
   5 80
  /  /
 2  50
  \
   4

Height of above Tree is 4

Ex Output : Return the Height of the Tree , -1 if Invalid

2) Get Sum of Left subtree gets the sum of all nodes ,in the left subtree of the given node
Ex : get_sum_left for 10 in above Tree ,returns 11
get_sum_left for 80 returns 0
Return -1 for invalid inputs

3) Get Sum of Left subtree gets the sum of all nodes ,in the left subtree of the given node
Ex : get_sum_left for 10 in above Tree ,returns 130
get_sum_left for 80 returns 0
Return -1 for invalid inputs

*/
#include <stdlib.h>
#include <stdio.h>
int sum;
struct node{
	struct node * left;
	int data;
	struct node *right;
};

void inorder1(struct node *root)
{

	if (!root) return;
	inorder1(root->left);
	sum=sum+root->data;

	inorder1(root->right);
}
void inorder(struct node *root)
{
	sum = 0;
	inorder1(root);

}
int get_height(struct node *root)
{
	if (root == NULL)
		return 0;
	else
	{
		/* compute the depth of each subtree */
		int lDepth = get_height(root->left);
		int rDepth = get_height(root->right);

		/* use the larger one */
		if (lDepth > rDepth)
			return(lDepth + 1);
		else return(rDepth + 1);
	}
	
}

int get_left_subtree_sum(struct node *root)
{
	if (root == NULL)
		return 0;
	sum=0;
	inorder(root->left);
	return sum;
}

int get_right_subtree_sum(struct node *root)
{
	if (root == NULL)
		return 0;
	sum = 0;
	inorder(root->right);
	return sum;
}

