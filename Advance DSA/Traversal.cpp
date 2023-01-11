#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node *left, *right;
};

Node* newNode(int data)
{
	Node* temp = new Node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

void printInorder(struct Node* node)
{
	if (node == NULL)
		return;

	printInorder(node->left);

	cout << node->data << " ";

	printInorder(node->right);
}

void printPreOrder(struct Node* node)
{
	if (node == NULL)
		return;

    cout << node->data << " ";

	printPreOrder(node->left);


	printPreOrder(node->right);
}

void printPostOrder(struct Node* node)
{
	if (node == NULL)
		return;

	printPostOrder(node->left);

	printPostOrder(node->right);

    cout << node->data << " ";

}

void printQueue(queue<struct Node*>q)
{
    while(!q.empty())
    {
        cout<<q.front()->data<<" ";
        q.pop();
    }
    cout<<endl;
}

void printLevelOrder(struct Node* node)
{
	queue<struct Node*>q;
    q.push(node);
    cout<<node->data<<endl;
    while(!q.empty())
    {
       int size=q.size();
       while(size--)
       {
          struct Node* p=q.front();
          q.pop();

          if(p->right)
          q.push(p->right);

          if(p->left)
          q.push(p->left);
       }
       printQueue(q);
    }

}

int main()
{
	struct Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);


	cout << "\nInorder traversal of binary tree is \n";
	printInorder(root);

    cout << "\nPreorder traversal of binary tree is \n";
	printPreOrder(root);

    cout << "\nPostorder traversal of binary tree is \n";
	printPostOrder(root);

    cout << "\n LevelOder traversal of binary tree is \n";
	printLevelOrder(root);



	return 0;
}
