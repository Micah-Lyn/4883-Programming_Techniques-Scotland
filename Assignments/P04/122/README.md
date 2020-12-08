122 - Tress on the level
### Micah-Lyn Scotland
### Description:

Given a sequence of binary trees, you are to write a program
that prints a level-order traversal of each tree. In this problem
each node of a binary tree contains a positive integer and all
binary trees have have fewer than 256 nodes.
In a level-order traversal of a tree, the data in all nodes at a
given level are printed in left-to-right order and all nodes at level
k are printed before all nodes at level k + 1.
For example, a level order traversal of the tree on the right is:
5, 4, 8, 11, 13, 4, 7, 2, 1.
In this problem a binary tree is specified by a sequence of
pairs ‘(n,s)’ where n is the value at the node whose path from
the root is given by the string s. A path is given be a sequence of ‘L’s and ‘R’s where ‘L’ indicates a
left branch and ‘R’ indicates a right branch. In the tree diagrammed above, the node containing 13 is
specified by (13,RL), and the node containing 2 is specified by (2,LLR). The root node is specified by
(5,) where the empty string indicates the path from the root to itself. A binary tree is considered to
be completely specified if every node on all root-to-node paths in the tree is given a value exactly once.

### Files

|   #   | File                       | Description                                                |
| :---: | -------------------------- | ---------------------------------------------------------- |
|   1   | [main.cpp](https://github.com/Micah-Lyn/4883-Programming_Techniques-Scotland/blob/master/Assignments/P04/122/main.cpp)     | solution file.                                             |
|   2   | [input](https://github.com/Micah-Lyn/4883-Programming_Techniques-Scotland/blob/master/Assignments/P04/122/input)           | Test input file from problem statement                     |
