# 📚 Data Structures Repo

## Overview
This repository contains **implementations of common Data Structures in C++**, covering both **linear and non-linear structures**. Each structure includes basic operations, along with notes and examples to help understand edge cases and build strong DSA fundamentals.  

---

## Data Structures and Operations

| Type        | Data Structure | Main Operations |
|------------|----------------|----------------|
| Linear     | Arrays          | Traverse, Search, Insert, Delete |
| Linear     | Linked List     | Traverse, Insert, Delete |
| Linear     | Stack           | Push, Pop, Peek |
| Linear     | Queue           | Enqueue, Dequeue, Peek |
| Non-Linear | Binary Tree     | Traversals (Preorder, Inorder, Postorder), Insert, Delete |
| Non-Linear | Binary Search Tree (BST) | Insert, Search, Delete, Traversals |
| Non-Linear | Graph           | BFS, DFS, Adjacency Matrix/List representation |

---

## How to Use
1. Clone the repository:  
```bash
git clone https://github.com/your-username/ds-repo.git
Open in VS Code or any C++ IDE

Compile and run any .cpp file:

g++ filename.cpp -o output
./output
Check notes.md for step-by-step explanations, edge cases, and mental models

Folder Structure
ds-repo/
│
├─ arrays/         # Array programs
├─ linkedlist/     # Linked List programs
├─ stack/          # Stack programs
├─ queue/          # Queue programs
├─ trees/          # Binary Trees & BST programs
├─ graphs/         # Graph programs
├─ notes.md        # Step-by-step notes for all DS
└─ README.md       # This file
Tips
Track size vs capacity for static structures

Use backward shifting for insertion and forward shifting for deletion

Always handle empty or invalid cases

Use proper traversal techniques for trees and graphs

License
Open-source — free to use for learning and practice