void printkthnode(NODE* root, int k)
{
  if(!root) return;
  if(k == 0) cout << root->data ;
  else 
  { 
    printkthnode(root->left, k-1);
    printkthnode(root->right, k-1);
  }
}
