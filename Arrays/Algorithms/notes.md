## 📄 Traversal 
Visiting each element of a data structure sequentially to perform an operation (print, search, update, count, validate).
### 🔁 Standard Pattern (Array)
for (int i = 0; i < size; i++)
### 🚧 Loop Boundary Rules
* Start at index 0.
* Stop at `i < size`.
* Never use `i <= size` (out-of-bounds risk).
* Size must be correct.
### 📏 Why Size Matters
* Defines safe memory limit.
* Wrong size → missing elements OR accessing garbage memory.
### ⚠️ Edge Cases
* Empty (`size == 0`) → handle before loop.
* Single element → loop should still run once.
* Negative size → invalid input.
* Very large data → performance consideration.
### 🪄 Common Uses
* Print elements
* Search value
* Find max/min
* Count occurrences
* Update values
* Check conditions
### ❌ Common Mistakes
* Off-by-one errors (`<=` vs `<`)
* Forgetting empty check
* Passing wrong size
* Skipping elements accidentally
* Infinite loop due to wrong condition
### 🧩 Mental Model
Walking through lockers in a hallway — one by one, no skipping.
### ⚡ Complexity
* Time: O(n)
* Space: O(1)
### 📝 Quick Checklist
☑ Correct size known
☑ Loop boundary correct
☑ Empty case handled
☑ Visiting each element once
☑ No out-of-bounds access

---------------------------------------------------------------------------------

## 📌 Linear Search 
Linear search is a method of finding an element by checking each element one by one until the target is found or the list ends.
### 🔁 Basic Idea
Start from first element → compare with key → move forward → stop if found or finished.
### ⚙️ Algorithm Steps
1. Start at index 0.
2. Compare element with key.
3. If match → return index.
4. Else move to next element.
5. If end reached → element not found.
### ⏱ Time Complexity
* Best case: O(1) (found at start)
* Worst case: O(n) (found at end or not present)
* Average case: O(n)
### 💾 Space Complexity
O(1) — no extra memory needed.
### ✅ When to Use
* Data is small.
* Data is unsorted.
* Simplicity is preferred.
### ⚠️ Edge Cases
* Empty array.
* Element not present.
* Duplicate elements.
* Single element array.
### ❌ Common Mistakes
* Printing “not found” inside loop.
* Wrong loop boundary.
* Forgetting to stop after finding.
* Not handling empty array.
### 🧩 Mental Model
Like scanning a list line by line.
### 💬 One-liner
Linear search sequentially checks each element until the target is found or the search ends.

---------------------------------------------------------------------------------

