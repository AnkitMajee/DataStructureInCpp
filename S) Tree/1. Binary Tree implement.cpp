#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
// struct node  
//     {  
//          int data;  
//          struct node *left, *right;  
//      };  
//      
//      struct node *create()  
//{  
//   struct node *temp;  
//   int data,choice;  
//   temp = (struct node *)malloc(sizeof(struct node));  
//   printf("Press 0 to exit");  
//   printf("\nPress 1 for new node");  
//   printf("Enter your choice : ");  
//   scanf("%d", &choice);   
//   if(choice==0)  
//{  
//return 0;  
//}  
//else  
//{  
//   printf("Enter the data:");  
//   scanf("%d", &data);  
//   temp->data = data;  
//   printf("Enter the left child of %d", data);  
//   temp->left = create();  
//printf("Enter the right child of %d", data);  
//temp->right = create();  
//return temp;   
//}  
//}
//      
//      int main()  
//    {  
//       struct node *root;  
//       root = create();  
//    }  
//  
struct Node{
	int key;
	Node *left;
	Node *right;
	Node(int k){
		key=k;
		left=right=NULL;
	}
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  Node *root=new Node(10);
  root ->left= new Node(20);
  root ->right= new Node(30);
  root ->left-> left= new Node(40);

  return 0;
}






//Goto tools > Editor Option > Snippets >Default Source Code

