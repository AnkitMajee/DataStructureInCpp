# Linked List Reversal Visualization

This README demonstrates the process of reversing a linked list using recursion.

## Visualization

The following diagram illustrates the steps of the recursive linked list reversal:

```mermaid
graph TD
    subgraph "Initial List"
        A1[1] --> B1[2]
        B1 --> C1[3]
        C1 --> D1[4]
    end
    subgraph "First Recursive Call"
        A2[1] --> B2[2]
        B2 --> C2[3]
        C2 --> D2[4]
        D2 -.-> C2
    end
    subgraph "Second Recursive Call"
        A3[1] --> B3[2]
        B3 --> C3[3]
        C3 --> D3[4]
        D3 --> C3
        C3 -.-> B3
    end
    subgraph "Third Recursive Call"
        A4[1] --> B4[2]
        B4 --> C4[3]
        C4 --> D4[4]
        D4 --> C4
        C4 --> B4
        B4 -.-> A4
    end
    subgraph "Final Reversed List"
        A5[1] --> B5[2]
        B5 --> C5[3]
        C5 --> D5[4]
        D5 --> C5
        C5 --> B5
        B5 --> A5
    end
    Initial --> First
    First --> Second
    Second --> Third
    Third --> Final
```

This diagram shows how the linked list is reversed step by step through recursive calls.

## Explanation

The diagram illustrates the following steps:

1. Initial List: The original linked list (1 -> 2 -> 3 -> 4)
2. First Recursive Call: The last node (4) is identified as the new head
3. Second Recursive Call: Node 3 is connected to node 4
4. Third Recursive Call: Node 2 is connected to node 3
5. Final Reversed List: Node 1 is connected to node 2, completing the reversal

For more details on the implementation, please refer to the code in this repository.
