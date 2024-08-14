# AVL Tree 

<img width="388" alt="image" src="https://github.com/user-attachments/assets/1ba3dfe9-a2b0-400f-984a-da5f00975d4b">
## Overview

This project implements an AVL tree, a type of self-balancing binary search tree. The balance is maintained by ensuring the difference in height between the left and right subtrees of any node is no more than one. This keeps operations like insertion, deletion, and search efficient.

My implementation of the AVL tree stands out due to its efficient handling of data and robust error checking, ensuring smooth and reliable operations.

## Files and Classes

### `AVL.h`
This file contains the main AVL tree implementation. It handles the creation, insertion, deletion, and searching of nodes in the tree. The tree automatically balances itself after every insertion and deletion to maintain optimal performance.

Key methods:
- **`insert(string name, string UFID)`**: Inserts a node with a name and UFID. The tree rebalances if needed.
- **`remove(TreeNode* root, string UFID)`**: Removes a node with the given UFID and rebalances the tree.
- **`search(string UFID)`**: Searches for a node with the specified UFID.

### `runMyCode`
This struct is responsible for managing commands from the user and interacting with the AVL tree. It verifies input validity and performs the appropriate tree operations based on user commands.

Key methods:
- **`parser(string &s, Tree& tree)`**: Parses user input and determines which AVL tree operation to perform.
- **`isUFID(string num)`**: Checks if a given string is a valid UFID.
- **`isAName(string name)`**: Checks if a given string is a valid name.

### `main`
This file is the entry point of the program. It handles user input, initializes the AVL tree, and uses `runMyCode` to execute commands based on the input.

## Conclusion

This AVL tree implementation is not just functional but also optimized for performance and reliability. Whether you're inserting, deleting, or searching for nodes, the tree ensures operations are performed quickly and accurately.



