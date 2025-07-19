# Notes

## Part 1

### Given inputs [4, 5, 8, 3]

### Identify what is stored in the text segment when the process is admitted by the OS and is in the ready state

The text segment stores the program code functions in the form of compiled machine code. This includes the written functions in the program sum() and main(), and functions included in standard library code like the references to cout/cin. The OS admits the process, and when it's in a ready state the function machine code sits in the text segment of memory.

### Identify what variables will be stored in the data segment

The data segment for a process holds the global and static variables which have been initialised explicitly, which would be int size = 4 (global) and static int result = 0 (local static).

### Identify what is stored in heap and stack segments when line 12 is being executed for the third time

On the third iteration of the main loop, i == 2:

Stack: Stack memory holds local variables and the function call stack of the currently-scoped function(s). The function call stack contains things like the local function variables, arguments, return address, etc.

- Local vars: p pointer, i == 2, int total == p[0] + p[1] + p[2] (on iteration complete, so 4 + 5 + 8 = 17)
- Function stack frames: main() and sum()

Heap: Heap memory holds the array being summed, integers 4, 5, and 8 have been stored here.

- Dynamically allocated int array: p = new int[size] where p[0], p[1], p[2] are filled with 4, 5, and 8.

### Identify what is stored in heap and stack segments when line 33 is being executed

When line 33 is executed, the loop has finished all iterations:

Stack:

- Local vars: index i = 4, and total = sum(p[0], p[1], p[2], p[3]), so the sum 4 + 5 + 8 + 3 = 20
- Function stack frames: only main() with its local vars since this step lies outside sum() execution scope

Heap:

After calling delete p, the memory that was assigned to the array has been cleared, so the array is removed from heap and only the pointer remains in the stack frame of main()

## Part 2

### Based on the design and the code, explain what the primary function of this board is. Complete the code by adding appropriate comments in the designated lines

The code is designed to toggle an LED on and off when the user presses it, but the behaviour corresponds to the light being toggled only when the user holds their finger down on the button, no toggle. There's also some pretty noticeable latency, so the sleep(500) creates a janky experience. I've added comments to address each stage of the script.

