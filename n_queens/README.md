# Constraint Satisfaction Problems (CSP) & Backtracking Framework

## Overview

Many computational tasks involve **placing, arranging, or selecting elements** under a set of constraints. These tasks are collectively known as **Constraint Satisfaction Problems (CSPs)**.  

A CSP typically requires:

- A set of **variables** that need values.
- A **domain** of possible values for each variable.
- **Constraints** that define which combinations of values are valid.

The goal is to **find all valid assignments** of values to variables that satisfy all constraints.

---

## Categories of Problems

CSPs appear in many contexts, such as:

- Puzzle solving (crosswords, Sudoku, logic puzzles)
- Scheduling (tasks, exams, meetings)
- Combinatorial arrangements (permutations, seating plans)
- Graph coloring and assignment problems

---

## Core Principle: Backtracking

Backtracking is a systematic **trial-and-error search** that builds solutions incrementally and **abandons partial solutions** as soon as a constraint is violated.  

### Mental Model

1. **Start with an empty solution**.
2. **Select the next variable** to assign.
3. **Try all possible values** from its domain:
   - Check **constraints** with the current partial solution.
   - If the assignment is **valid**, **recurse** to the next variable.
   - If the assignment leads to a dead-end, **backtrack** and try the next value.
4. **Repeat** until:
   - A complete valid solution is found (record it), or  
   - All possibilities are exhausted.

---

## Reusable Framework (Step-by-Step)

1. **Define Variables and Domains**
   - Identify each element that requires a choice.
   - Enumerate all possible values for that element.

2. **Define Constraints**
   - Specify rules that make a partial assignment invalid.
   - Must be able to check **incrementally** as new values are added.

3. **Recursive Function**
   - Input: partial solution, current variable index
   - Base case: all variables are assigned → solution complete → record or output
   - Recursive case: for each value in the variable’s domain:
     - Check constraints
     - If valid → extend solution and recurse
     - If invalid → skip

4. **Backtracking Mechanism**
   - Undo the last assignment when all options fail for the current variable.
   - Ensure that the state of the solution is restored before trying the next option.

5. **Output or Collect Solutions**
   - Either print, count, or store all valid solutions.

---

## Example Problems Suited for This Framework

- Generating **all permutations** or combinations under constraints
- Solving **puzzles** where placement rules exist
- Scheduling **non-conflicting events**
- Assigning **resources** with mutual exclusivity or other constraints
- Coloring **graphs** such that adjacent nodes have different colors

---

## Mental Template to Reuse

Whenever you see a problem that asks:

- “Place/assign elements without conflict”
- “Find all valid arrangements”
- “Select combinations satisfying rules”

…think in terms of:

1. **Variables → what needs to be chosen**
2. **Domains → what can each variable be**
3. **Constraints → what is allowed**
4. **Recursive assignment → try, check, recurse**
5. **Backtracking → undo and try alternatives**
6. **Collect/print valid solutions**

By following this template, you can approach dozens of combinatorial or CSP tasks without needing a problem-specific solution from scratch.

