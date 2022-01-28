struct node_t;

typedef struct node_t {
	struct node_t* left;
	struct node_t* right;
} node;

typedef struct {
	int size;
	struct node_t* first;
} tree;

tree* createTree();

int calculateDepth(tree* tree_p);

void insertTreeNode(tree* tree_p, char* str);

void printTree(tree* tree_p);