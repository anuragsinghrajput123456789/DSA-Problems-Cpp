# 🚀 DSA Journey in C++  

Welcome to my **Data Structures & Algorithms (DSA) in C++ Repository** 🎯  
This repo is my personal space where I solve **LeetCode, Codeforces, GFG, and other DSA problems** daily, documenting not only the **solutions** but also the **learning process**.  

---

## 📌 What You’ll Find Here  

- ✅ **C++ Implementations** of DSA problems  
- ✅ **Clean & Well-Commented Code** for clarity  
- ✅ **Problem Links** (LeetCode/GFG/CF) in each solution  
- ✅ **Brute Force vs Optimal Approaches**  
- ✅ **Dry Runs & Explanations** in code comments  
- ✅ **DSA Notes & Concepts** (coming soon 📒)  

---

## 🌟 Topics Covered So Far  

- 🔹 Arrays & Strings  
- 🔹 Recursion & Backtracking  
- 🔹 Linked List  
- 🔹 Stacks & Queues  
- 🔹 Trees & Binary Search Trees  
- 🔹 Graphs (BFS, DFS, Shortest Path)  
- 🔹 Dynamic Programming  
- 🔹 Bit Manipulation  
- 🔹 Sliding Window & Two Pointers  

*(More topics added as I progress through my #100DaysOfCode journey 🚀)*  

---

## ⚡ Example Highlight  

### Problem: [78. Subsets](https://leetcode.com/problems/subsets/)  

- **Brute Force:** Binary representation of subsets.  
- **Optimal:** Recursion with include/exclude strategy.  
- ⏱️ TC: `O(n·2^n)` | 💾 SC: `O(n)`  

```cpp
void solve(vector<int>& nums, vector<int> output, int index, vector<vector<int>>& ans) {
    if(index >= nums.size()){
        ans.push_back(output);
        return;
    }
    // exclude
    solve(nums, output, index+1, ans);
    // include
    output.push_back(nums[index]);
    solve(nums, output, index+1, ans);
}


🏆 My Progress

📅 Currently on Day 59 of #100DaysOfLeetCode
Check out my daily updates on:

Linkdin = https://www.linkedin.com/in/anurag-singh-09629b22a/

github = https://github.com/Anurag-Singh-02
leetcode = https://leetcode.com/u/12345anuragsingh