## 🧩 Problem Category

**Category:** Combinatorial Search / Backtracking / Subset Generation  

This problem belongs to the family of **combinatorial enumeration** problems —  
where you explore *all possible combinations* or *configurations* of a given set  
and filter them based on some condition (e.g., subset sum, constraints, validity).

Typical examples in this category:
- Generating all subsets (power set)
- Subset sum / target sum problems
- Combinations (n choose k)
- Permutation generation
- N-Queens and Sudoku (constraint satisfaction)
- Knapsack problem (include/exclude pattern)

---

## 🧠 Core Idea

At each step, you decide whether to **include** or **exclude** the current element  
and recursively explore the remaining options.  
This naturally forms a **binary decision tree** of all possibilities.

> **Recursive Backtracking = Systematic exploration of all valid configurations**

---

## 🧮 Mental Template (Reusable Pattern)

```text
function explore(index, current_state):
    if index == total_elements:
        if current_state satisfies condition:
            process(current_state)
        return

    // Decision 1: include the current element
    add current_element to current_state
    explore(index + 1, current_state)
    remove current_element from current_state

    // Decision 2: exclude the current element
    explore(index + 1, current_state)

