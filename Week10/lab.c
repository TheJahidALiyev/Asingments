#include <stdio.h>
#include <stdlib.h>

struct Node{
  int value;
  struct Node* left;
  struct Node* right;
};

struct Node* newNode(int value) 
{ 
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->value = value; 
    node->left = NULL;
    node->right = NULL; 
    return (node); 
}

int Biggest(struct Node* iter)
{
  if (iter == NULL)
	  return 0;
  if (Biggest(iter->left) < Biggest(iter->right))
	return iter->value + Biggest(iter->right);
  else
	  return iter->value + Biggest(iter->left);


}

                
  

int main(){
  struct Node* sum = newNode(0);
  struct Node* root = newNode(1);
  root->left = newNode(10);
  root->right = newNode(5);
  root->left->left = newNode(20);
  root->left->right = newNode(4);
  root->left->left->left = newNode(999);
  root->right->right = newNode(25);
  root->right->left = newNode(21);
  root->right->right->right = newNode(15);
  root->right->left->left = newNode(13);
  printf("the max values of binary tree are: %d\n", Biggest(root));
  return 0;
}
