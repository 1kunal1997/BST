
/* Node class for the binary tree. Contains a value (an integer), and 
two pointers to its children. Getter and setter methods are provided. */
class Node {
	public:
		Node(int val);
		Node();
		int getValue();
		void setValue(int v);
		Node* getLeft();
		void setLeft(Node *makeleft);
		Node* getRight();
		void setRight(Node *makeright);
	private:
		int value;
		Node *left, *right;
};

Node::Node(int val) {
	value = val;
	left = nullptr;
	right = nullptr;
}

Node::Node() {
	left = nullptr;
	right = nullptr;
}

int Node::getValue() {
	return value;
}

void Node::setValue(int v) {
	value = v;
}

Node* Node::getLeft() {
	return left;
}

void Node::setLeft(Node *makeleft) {
	left = makeleft;
}

Node* Node::getRight() {
	return right;
}

void Node::setRight(Node *makeright) {
	right = makeright;
}
