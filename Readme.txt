
There are many ways to store and search strings inside the text, like binary search trees or hash tables.
 key collisions are the hash function mapping of different keys to the same position in a hash table.
 The worst-case lookup speed in an imperfect hash table is O(N) time, but far more typically is O(1), with O(m) time spent evaluating the hash.
There are no collisions of different keys in a trie.

But in this problem, I have used the trie data structure. Trie can be visualized like a graph. It consists of nodes and edges. Each node consists of at max 26 children and edges connect each parent node to its children. These 26 pointers are nothing but pointers for each of the 26 letters of the English alphabet 'a' separate edge is maintained for every edge. 

Using the basics of structures and pointer we have created a trie data structure

Finally in Words1.text file contains three maximum same length string 2 of them are printed.













