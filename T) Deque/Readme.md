# Deque Implementation in C++

### Overview

A **deque** (double-ended queue) is a dynamic data structure similar to arrays, but with added flexibility to insert and remove elements from both the front and the back in amortized constant time. This implementation avoids using the C++ STL, ensuring a hands-on approach to understanding the internal workings of a deque.

### Features

- **Dynamic Resizing**: The deque dynamically resizes itself to accommodate more elements as needed.
- **Efficient Operations**:
  - Insertion and deletion at both ends in **O(1)** amortized time.
  - Access to elements via index in **O(1)** time.
  - Middle insertion and deletion in **O(n)** time.

### Supported Operations

1. `deque()` – Initializes an empty deque.
2. `deque(n, x)` – Initializes a deque of size `n` with all values set to `x`.
3. `push_back(x)` – Appends the value `x` to the back of the deque.
4. `pop_back()` – Removes the value at the back of the deque.
5. `push_front(x)` – Appends the value `x` to the front of the deque.
6. `pop_front()` – Removes the value at the front of the deque.
7. `front()` – Returns the value at the front of the deque.
8. `back()` – Returns the value at the back of the deque.
9. `empty()` – Returns `true` if the deque is empty, otherwise `false`.
10. `size()` – Returns the current size of the deque.
11. `resize(x, d)` – Resizes the deque to `x` elements, filling new spaces with `d` if expanded.
12. `clear()` – Clears all elements from the deque.
13. `D[n]` – Returns the nth element of the deque using the bracket operator `[]`.

### Example Usage

```cpp
Deque dq;
dq.push_back(10);
dq.push_front(20);
dq.push_back(30);

cout << "Front: " << dq.front() << endl;  // Output: 20
cout << "Back: " << dq.back() << endl;    // Output: 30

dq.pop_front();
cout << "After pop_front, Front: " << dq.front() << endl;  // Output: 10

dq.pop_back();
cout << "After pop_back, Back: " << dq.back() << endl;    // Output: 10
