#include <iostream>
#include <stdexcept>

using namespace std;

struct Node {
    int value;
    Node* left = NULL;
    Node* right = NULL;

    Node(int value) : value(value) {}
};

int probeNode(const Node* node) {
    if (!node) {
        throw invalid_argument("Node cannot be null");
    }
    return node->value;
}

Node* findLocalMinimum(Node* root) {
    if (!root) {
        return NULL;
    }

    Node* current = root;

    while (true) {
        int leftValue = -1, rightValue = -1;

        if (current->left) {
            leftValue = probeNode(current->left);
        }

        if (current->right) {
            rightValue = probeNode(current->right);
        }

        if (leftValue == -1 || rightValue == -1 ||
            (leftValue > current->value && rightValue > current->value)) {
            return current;
        }

        if (leftValue != -1 && leftValue < rightValue) {
            current = current->left;
        }
        else if (rightValue != -1) {
            current = current->right;
        }
    }
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(3);
    root->left->right = new Node(8);

    Node* localMin = findLocalMinimum(root);

    if (localMin) {
        cout << "Local minimum: " << localMin->value << endl;
    }
    else {
        cout << "No local minimum found" << endl;
    }

    return 0;
}
