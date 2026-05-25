# Infix to Postfix Conversion (Using Stack)
## Step 0: Initialize
* Create an empty stack
* Create an empty output string
---
## Step 1: Read Expression
* Traverse the infix expression from **left to right**
---
## Step 2: If Operand (A–Z, a–z, 0–9)
* Add it directly to output
---
## Step 3: If '(' (Opening Bracket)
* Push it into stack
---
## Step 4: If ')' (Closing Bracket)
* Pop elements from stack and add to output
* Stop when '(' is found
* Remove '(' from stack (do not add to output)
---
## Step 5: If Operator (+, -, *, /, ^)
### Case 1: Stack is empty OR top is '('
* Push operator into stack
### Case 2: Stack has operator
* While:
  * Stack is not empty AND
  * Top is not '(' AND
  * Precedence(top) >= Precedence(current)
  Do:
  * Pop from stack and add to output
* Finally, push current operator into stack
---
## Step 6: End of Expression
* Pop all remaining elements from stack
* Add them to output
---
## Precedence Rules
* ^  → Highest
* *, / → Medium
* +, - → Lowest
---
## Final Output
* The output string is the postfix expression

------------------------------------------------------------------------------------------

