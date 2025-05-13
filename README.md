# CSCI 3761 - Lab Assignment 4: Link-State Routing (Dijkstra's Algorithm)

##  Overview

This project implements the **Link-State Routing Algorithm** (Dijkstra’s Algorithm) in C++ as part of Lab 4 for the CSCI 3761 course. The program computes least-cost paths from a given source node to all other nodes in a network based on a provided adjacency matrix.



##  Usage

```bash
./mylinkstate <input_file> <source_node> <flag>
```

- `<input_file>`: file containing the network topology
- `<source_node>`: index of the starting node (0-based)
- `<flag>`:
  - `1` — print each iteration table
  - `0` — suppress table output (just final result)

--

##  Build Instructions

### Compile

```bash
g++ -o mylinkstate mylinkstate.cpp
```

### Run

```bash
./mylinkstate test10nodes 0 1
```

---

##  Output Format

1. **If flag = 1**: Prints step-by-step distance table per iteration.
2. **Always**:
   - Final forwarding table from source node
   - Total execution time in milliseconds




##  Sample Files

Test and output samples:
- `test10nodes`, `test100nodes`: sample inputs
- `sample-out-4-10nodes`: example of expected output

