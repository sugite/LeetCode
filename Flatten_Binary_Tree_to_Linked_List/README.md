�ҵķ����ǵݹ�ģ����˷Ѷ�ջ�ռ䣬���Բ���**in-place**��

������discuss���濴����ѭ���ⷨ��   
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
