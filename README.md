# CSCI 3761 - Lab Assignment 4: Link-State Routing (Dijkstra's Algorithm)

## 📌 Overview

This project implements the **Link-State Routing Algorithm** (Dijkstra’s Algorithm) in C++ as part of Lab 4 for the CSCI 3761 course. The program computes least-cost paths from a given source node to all other nodes in a network based on a provided adjacency matrix.

---

## 📥 Input Format

- Input file begins with the number of nodes `N`
- Followed by an `N x N` matrix of costs:
  - `C[i][j] = cost` if there is a direct connection (0 <= cost < 100)
  - `C[i][j] = 1073741824 (2^30)` if no direct connection

Sample:
```
6
0 2 5 1 1073741824 1073741824
2 0 3 2 1073741824 1073741824
...
```

---

## 🚀 Usage

```bash
./mylinkstate <input_file> <source_node> <flag>
```

- `<input_file>`: file containing the network topology
- `<source_node>`: index of the starting node (0-based)
- `<flag>`:
  - `1` — print each iteration table
  - `0` — suppress table output (just final result)

---

## 🖥️ Sample Command

```bash
./mylinkstate test10nodes 0 1
```

---

## ⚙️ Build Instructions

### Compile

```bash
g++ -o mylinkstate mylinkstate.cpp
```

### Run

```bash
./mylinkstate test10nodes 0 1
```

---

## 📊 Output Format

1. **If flag = 1**: Prints step-by-step distance table per iteration.
2. **Always**:
   - Final forwarding table from source node
   - Total execution time in milliseconds

---

## 📝 Submission Instructions

1. Include:
   - `mylinkstate.cpp`
   - `README.md`
   - `Makefile`

2. Create a tar file with your last name’s first 3 letters + last 4 of your student ID  
   **Example:** `cli5678.tar`

3. **DO NOT include any executable or object files**

4. Submit via Canvas before **Wednesday, May 14, 2025, at 11:59 PM**

---

## 🏆 Extra Credit

The **top 10% fastest** programs receive **+3 extra points**!

---

## ✅ Dependencies

- Standard C++ libraries (`iostream`, `fstream`, `vector`, `chrono`)
- Works on `csegrid` as required

---

## 📁 Sample Files

Test and output samples:
- `test10nodes`, `test100nodes`: sample inputs
- `sample-out-4-10nodes`: example of expected output

---

## 👨‍💻 Author

Shivam Pathak — CSCI 3761 Spring 2025
