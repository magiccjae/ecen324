typedef struct ELE *tree_ptr;

struct ELE{
	long val;
	tree_ptr left;
	tree_ptr right;
};

long trace(tree_ptr tp){
	long temp = 0;
	while(tp != 0){
		temp = tp->val;
		tp = tp->right;
	}
	return temp;
}
