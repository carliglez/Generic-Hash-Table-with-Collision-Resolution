# Generic Hash Table Implementation with Collision Resolution and Probing Techniques

The goal of this project is to work with various search algorithms and implement hashing techniques in C++ using generic types, dynamic polymorphism, and operator overloading.

## Overview

This project involves the development of a generic `HashTable<class Key>` data structure in C++ to efficiently store key-value pairs using hashing techniques. The implementation focuses on allowing users to customize the size of the hash table, the hash function, and the collision resolution method. It also incorporates dynamic polymorphism, operator overloading, and generic types to create a flexible and reusable solution.

## Key components of the project

### 1. Customizable Hash Table Size:

The user can define the `tableSize`, which represents the number of available slots in the hash table.

### 2. Hashing Functions:

Several hash functions are implemented to map keys to positions in the table. These include:
- **Division Modulo Method:** `h(k) = k % tableSize`
- **Sum-based hashing:** `h(k) = Sum(ki) % tableSize`
- **Pseudo-random hashing:** `h(k) = {srand(k); rand()}`

### 3. Collision Resolution Techniques:

The project supports different methods for handling key collisions, where multiple keys hash to the same table index. The techniques implemented are:
- **Open Hashing (Closed Addressing):** Each position in the table holds a list to store multiple keys that hash to the same index (synonyms).
- **Closed Hashing (Open Addressing):** Each table position holds a fixed-size array to store a limited number of keys.

### 4. Block Size and Overflow Handling (Closed Hashing):

- **Block Size:** Specifies the maximum number of keys that can be stored in a single hash table cell.
- **Probing Functions for Overflow Resolution:** When a block overflows, various probing strategies are used to find an available slot. These include:
  - **Linear Probing:** `g(k, i) = i`
  - **Quadratic Probing:** `g(k, i) = i²`
  - **Double Hashing:** `g(k, i) = f(k) * i`
  - **Rehashing:** `g(k, i) = f(i)(k)` where `f(k)` and `f(i)(k)` are appropriate hash functions.

## Interactive User Configuration and Key Operations

The program is interactive, allowing the user to choose the size of the hash table, the hashing function, and the collision resolution method. Additionally, if closed addressing is selected, the user can define the block size and exploration strategy. The implemented hash table allows insertion and searching of keys via a menu-based system, providing feedback on the success or failure of each operation.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
