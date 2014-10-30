我的方法是递归的，会浪费堆栈空间，所以不是**in-place**。

下面是discuss里面看到的循环解法：   
```C++
while ( root ) {
    if ( root->left ) {
        TreeNode *ptr = root->left;
	while ( ptr->right ) ptr = ptr->right;
	ptr->right = root->right;
	root->right = root->left;
	root->left = NULL;
    }
    root = root->right;
}
```
