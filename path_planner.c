
/*
* EcoMender Bot (EB): Task 2B Path Planner
*
* This program computes the valid path from the start point to the end point.
* Make sure you don't change anything outside the "Add your code here" section.
*/

#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <limits.h>
#define V 32

#ifdef __linux__ // for host pc

    #include <stdio.h>

    void _put_byte(char c) { putchar(c); }

    void _put_str(char *str) {
        while (*str) {
            _put_byte(*str++);
        }
    }

    void print_output(uint8_t num) {
        if (num == 0) {
            putchar('0'); // if the number is 0, directly print '0'
            _put_byte('\n');
            return;
        }

        if (num < 0) {
            putchar('-'); // print the negative sign for negative numbers
            num = -num;   // make the number positive for easier processing
        }

        // convert the integer to a string
        char buffer[20]; // assuming a 32-bit integer, the maximum number of digits is 10 (plus sign and null terminator)
        uint8_t index = 0;

        while (num > 0) {
            buffer[index++] = '0' + num % 10; // convert the last digit to its character representation
            num /= 10;                        // move to the next digit
        }
        // print the characters in reverse order (from right to left)
        while (index > 0) { putchar(buffer[--index]); }
        _put_byte('\n');
    }

    void _put_value(uint8_t val) { print_output(val); }

#else  // for the test device

    void _put_value(uint8_t val) { }
    void _put_str(char *str) { }

#endif

// main function
int main(int argc, char const *argv[]) {

    #ifdef __linux__

        const uint8_t START_POINT   = atoi(argv[1]);
        const uint8_t END_POINT     = atoi(argv[2]);
        uint8_t NODE_POINT          = 0;
        uint8_t CPU_DONE            = 0;

    #else
        // Address value of variables for RISC-V Implementation
        #define START_POINT         (* (volatile uint8_t * ) 0x02000000)
        #define END_POINT           (* (volatile uint8_t * ) 0x02000004)
        #define NODE_POINT          (* (volatile uint8_t * ) 0x02000008)
        #define CPU_DONE            (* (volatile uint8_t * ) 0x0200000c)

    #endif

    // array to store the planned path
    uint8_t path_planned[32];
    // index to keep track of the path_planned array
    uint8_t idx = 0;

    /* Functions Usage

    instead of using printf() function for debugging,
    use the below function calls to print a number, string or a newline

    for newline: _put_byte('\n');
    for string:  _put_str("your string here");
    for number:  _put_value(your_number_here);

    Examples:
            _put_value(START_POINT);
            _put_value(END_POINT);
            _put_str("Hello World!");
            _put_byte('\n');
    */

    // ############# Add your code here #############
    // prefer declaring variable like this
    #ifdef __linux__
        uint32_t graph[32];
    #else
        uint32_t *graph = (uint32_t *) 0x02000010;
    #endif


    graph[0] =  (0b0000 << 28) |  // First 4 bits (MSB)
                (0b0000 << 24) |  // Next 4 bits
                (0b0000 << 20) |  // Next 4 bits
                (0b0000 << 16) |  // Next 4 bits
                (0b0000 << 12) |  // Next 4 bits
                (0b0100 << 8)  |  // Next 4 bits
                (0b0100 << 4)  |  // Next 4 bits
                (0b0010);          // Last 4 bits (LSB)

    graph[1] =  (0b0000 << 28) |  // First 4 bits (MSB)
                (0b0000 << 24) |  // Next 4 bits
                (0b0000 << 20) |  // Next 4 bits
                (0b0000 << 16) |  // Next 4 bits
                (0b0000 << 12) |  // Next 4 bits
                (0b1000 << 8)  |  // Next 4 bits
                (0b0000 << 4)  |  // Next 4 bits
                (0b0101);          // Last 4 bits (LSB)

    graph[2] =  (0b0000 << 28) |  // First 4 bits (MSB)
                (0b0000 << 24) |  // Next 4 bits
                (0b0000 << 20) |  // Next 4 bits
                (0b0000 << 16) |  // Next 4 bits
                (0b0000 << 12) |  // Next 4 bits
                (0b0000 << 8)  |  // Next 4 bits
                (0b0011 << 4)  |  // Next 4 bits
                (0b1010);          // Last 4 bits (LSB)

    graph[3] =  (0b0000 << 28) |  // First 4 bits (MSB)
                (0b0000 << 24) |  // Next 4 bits
                (0b0000 << 20) |  // Next 4 bits
                (0b0000 << 16) |  // Next 4 bits
                (0b0000 << 12) |  // Next 4 bits
                (0b0000 << 8)  |  // Next 4 bits
                (0b0000 << 4)  |  // Next 4 bits
                (0b0100);          // Last 4 bits (LSB)
    
    graph[4] =  (0b0000 << 28) |  // First 4 bits (MSB)
                (0b0000 << 24) |  // Next 4 bits
                (0b0000 << 20) |  // Next 4 bits
                (0b0000 << 16) |  // Next 4 bits
                (0b0000 << 12) |  // Next 4 bits
                (0b0000 << 8)  |  // Next 4 bits
                (0b0000 << 4)  |  // Next 4 bits
                (0b0100);          // Last 4 bits (LSB)

    graph[5] =  (0b0000 << 28) |  // First 4 bits (MSB)
                (0b0000 << 24) |  // Next 4 bits
                (0b0000 << 20) |  // Next 4 bits
                (0b0000 << 16) |  // Next 4 bits
                (0b0000 << 12) |  // Next 4 bits
                (0b0000 << 8)  |  // Next 4 bits
                (0b0000 << 4)  |  // Next 4 bits
                (0b0100);          // Last 4 bits (LSB)

    graph[6] =  (0b0000 << 28) |  // First 4 bits (MSB)
                (0b0000 << 24) |  // Next 4 bits
                (0b0000 << 20) |  // Next 4 bits
                (0b0000 << 16) |  // Next 4 bits
                (0b0000 << 12) |  // Next 4 bits
                (0b0011 << 8)  |  // Next 4 bits
                (0b1000 << 4)  |  // Next 4 bits
                (0b0001);          // Last 4 bits (LSB)

    graph[7] =  (0b0000 << 28) |  // First 4 bits (MSB)
                (0b0000 << 24) |  // Next 4 bits
                (0b0000 << 20) |  // Next 4 bits
                (0b0000 << 16) |  // Next 4 bits
                (0b0000 << 12) |  // Next 4 bits
                (0b0000 << 8)  |  // Next 4 bits
                (0b0100 << 4)  |  // Next 4 bits
                (0b0000);          // Last 4 bits (LSB)
    graph[8] =  (0b0000 << 28) |  // First 4 bits (MSB)
                (0b0000 << 24) |  // Next 4 bits
                (0b0000 << 20) |  // Next 4 bits
                (0b0000 << 16) |  // Next 4 bits
                (0b0000 << 12) |  // Next 4 bits
                (0b0000 << 8)  |  // Next 4 bits
                (0b0100 << 4)  |  // Next 4 bits
                (0b0000);          // Last 4 bits (LSB)

    graph[9] =  (0b0000 << 28) |  // First 4 bits (MSB)
                (0b0000 << 24) |  // Next 4 bits
                (0b0000 << 20) |  // Next 4 bits
                (0b0000 << 16) |  // Next 4 bits
                (0b0000 << 12) |  // Next 4 bits
                (0b0000 << 8)  |  // Next 4 bits
                (0b0100 << 4)  |  // Next 4 bits
                (0b0000);          // Last 4 bits (LSB)

    graph[10] = (0b0000 << 28) |  // First 4 bits (MSB)
                (0b0101 << 24) |  // Next 4 bits
                (0b0000 << 20) |  // Next 4 bits
                (0b0000 << 16) |  // Next 4 bits
                (0b0000 << 12) |  // Next 4 bits
                (0b1000 << 8)  |  // Next 4 bits
                (0b0000 << 4)  |  // Next 4 bits
                (0b0001);          // Last 4 bits (LSB)

    graph[11] = (0b0000 << 28) |  // First 4 bits (MSB)
                (0b0000 << 24) |  // Next 4 bits
                (0b0000 << 20) |  // Next 4 bits
                (0b1000 << 16) |  // Next 4 bits
                (0b0001 << 12) |  // Next 4 bits
                (0b0100 << 8)  |  // Next 4 bits
                (0b0000 << 4)  |  // Next 4 bits
                (0b0010);          // Last 4 bits (LSB)

    graph[12] = (0b0000 << 28) |  // First 4 bits (MSB)
                (0b0000 << 24) |  // Next 4 bits
                (0b0000 << 20) |  // Next 4 bits
                (0b0000 << 16) |  // Next 4 bits
                (0b0110 << 12) |  // Next 4 bits
                (0b1000 << 8)  |  // Next 4 bits
                (0b0000 << 4)  |  // Next 4 bits
                (0b0000);          // Last 4 bits (LSB)

    graph[13] = (0b0000 << 28) |  // First 4 bits (MSB)
                (0b0000 << 24) |  // Next 4 bits
                (0b0000 << 20) |  // Next 4 bits
                (0b0000 << 16) |  // Next 4 bits
                (0b0001 << 12) |  // Next 4 bits
                (0b0000 << 8)  |  // Next 4 bits
                (0b0000 << 4)  |  // Next 4 bits
                (0b0000);          // Last 4 bits (LSB)

    graph[14] = (0b0000 << 28) |  // First 4 bits (MSB)
                (0b0000 << 24) |  // Next 4 bits
                (0b0000 << 20) |  // Next 4 bits
                (0b0001 << 16) |  // Next 4 bits
                (0b1001 << 12) |  // Next 4 bits
                (0b0000 << 8)  |  // Next 4 bits
                (0b0000 << 4)  |  // Next 4 bits
                (0b0000);          // Last 4 bits (LSB)
    
    graph[15] = (0b0000 << 28) |  // First 4 bits (MSB)
                (0b0000 << 24) |  // Next 4 bits
                (0b0000 << 20) |  // Next 4 bits
                (0b0000 << 16) |  // Next 4 bits
                (0b0100 << 12) |  // Next 4 bits
                (0b0000 << 8)  |  // Next 4 bits
                (0b0000 << 4)  |  // Next 4 bits
                (0b0000);          // Last 4 bits (LSB)

    graph[16] = (0b0000 << 28) |  // First 4 bits (MSB)
                (0b0000 << 24) |  // Next 4 bits
                (0b0000 << 20) |  // Next 4 bits
                (0b0110 << 16) |  // Next 4 bits
                (0b0100 << 12) |  // Next 4 bits
                (0b0000 << 8)  |  // Next 4 bits
                (0b0000 << 4)  |  // Next 4 bits
                (0b0000);          // Last 4 bits (LSB)

    graph[17] = (0b0000 << 28) |  // First 4 bits (MSB)
                (0b0000 << 24) |  // Next 4 bits
                (0b0000 << 20) |  // Next 4 bits
                (0b0001 << 16) |  // Next 4 bits
                (0b0000 << 12) |  // Next 4 bits
                (0b0000 << 8)  |  // Next 4 bits
                (0b0000 << 4)  |  // Next 4 bits
                (0b0000);          // Last 4 bits (LSB)

    graph[18] = (0b0000 << 28) |  // First 4 bits (MSB)
                (0b0000 << 24) |  // Next 4 bits
                (0b0010 << 20) |  // Next 4 bits
                (0b1001 << 16) |  // Next 4 bits
                (0b0000 << 12) |  // Next 4 bits
                (0b0000 << 8)  |  // Next 4 bits
                (0b0000 << 4)  |  // Next 4 bits
                (0b0000);          // Last 4 bits (LSB)

    graph[19] = (0b0000 << 28) |  // First 4 bits (MSB)
                (0b0000 << 24) |  // Next 4 bits
                (0b0001 << 20) |  // Next 4 bits
                (0b0100 << 16) |  // Next 4 bits
                (0b0000 << 12) |  // Next 4 bits
                (0b1000 << 8)  |  // Next 4 bits
                (0b0000 << 4)  |  // Next 4 bits
                (0b0000);          // Last 4 bits (LSB)

    graph[20] = (0b0000 << 28) |  // First 4 bits (MSB)
                (0b0000 << 24) |  // Next 4 bits
                (0b0000 << 20) |  // Next 4 bits
                (0b1000 << 16) |  // Next 4 bits
                (0b0000 << 12) |  // Next 4 bits
                (0b0000 << 8)  |  // Next 4 bits
                (0b0000 << 4)  |  // Next 4 bits
                (0b0000);          // Last 4 bits (LSB)

    graph[21] = (0b0000 << 28) |  // First 4 bits (MSB)
                (0b0000 << 24) |  // Next 4 bits
                (0b1100 << 20) |  // Next 4 bits
                (0b0100 << 16) |  // Next 4 bits
                (0b0000 << 12) |  // Next 4 bits
                (0b0000 << 8)  |  // Next 4 bits
                (0b0000 << 4)  |  // Next 4 bits
                (0b0000);          // Last 4 bits (LSB)

    graph[22] = (0b0000 << 28) |  // First 4 bits (MSB)
                (0b0000 << 24) |  // Next 4 bits
                (0b0010 << 20) |  // Next 4 bits
                (0b0000 << 16) |  // Next 4 bits
                (0b0000 << 12) |  // Next 4 bits
                (0b0000 << 8)  |  // Next 4 bits
                (0b0000 << 4)  |  // Next 4 bits
                (0b0000);          // Last 4 bits (LSB)

    graph[23] = (0b0100 << 28) |  // First 4 bits (MSB)
                (0b0001 << 24) |  // Next 4 bits
                (0b0010 << 20) |  // Next 4 bits
                (0b0000 << 16) |  // Next 4 bits
                (0b0000 << 12) |  // Next 4 bits
                (0b0000 << 8)  |  // Next 4 bits
                (0b0000 << 4)  |  // Next 4 bits
                (0b0000);          // Last 4 bits (LSB)

    graph[24] = (0b0000 << 28) |  // First 4 bits (MSB)
                (0b0010 << 24) |  // Next 4 bits
                (0b1000 << 20) |  // Next 4 bits
                (0b0000 << 16) |  // Next 4 bits
                (0b0000 << 12) |  // Next 4 bits
                (0b0100 << 8)  |  // Next 4 bits
                (0b0000 << 4)  |  // Next 4 bits
                (0b0000);          // Last 4 bits (LSB)

    graph[25] = (0b0000 << 28) |  // First 4 bits (MSB)
                (0b0001 << 24) |  // Next 4 bits
                (0b0000 << 20) |  // Next 4 bits
                (0b0000 << 16) |  // Next 4 bits
                (0b0000 << 12) |  // Next 4 bits
                (0b0000 << 8)  |  // Next 4 bits
                (0b0000 << 4)  |  // Next 4 bits
                (0b0000);          // Last 4 bits (LSB)

    graph[26] = (0b0001 << 28) |  // First 4 bits (MSB)
                (0b1000 << 24) |  // Next 4 bits
                (0b0000 << 20) |  // Next 4 bits
                (0b0000 << 16) |  // Next 4 bits
                (0b0000 << 12) |  // Next 4 bits
                (0b0100 << 8)  |  // Next 4 bits
                (0b0000 << 4)  |  // Next 4 bits
                (0b0000);          // Last 4 bits (LSB)

    graph[27] = (0b0000 << 28) |  // First 4 bits (MSB)
                (0b0100 << 24) |  // Next 4 bits
                (0b0000 << 20) |  // Next 4 bits
                (0b0000 << 16) |  // Next 4 bits
                (0b0000 << 12) |  // Next 4 bits
                (0b0000 << 8)  |  // Next 4 bits
                (0b0000 << 4)  |  // Next 4 bits
                (0b0000);          // Last 4 bits (LSB)

    graph[28] = (0b0110 << 28) |  // First 4 bits (MSB)
                (0b0100 << 24) |  // Next 4 bits
                (0b0000 << 20) |  // Next 4 bits
                (0b0000 << 16) |  // Next 4 bits
                (0b0000 << 12) |  // Next 4 bits
                (0b0000 << 8)  |  // Next 4 bits
                (0b0000 << 4)  |  // Next 4 bits
                (0b0000);          // Last 4 bits (LSB)

    graph[29] = (0b0001 << 28) |  // First 4 bits (MSB)
                (0b0000 << 24) |  // Next 4 bits
                (0b0000 << 20) |  // Next 4 bits
                (0b0000 << 16) |  // Next 4 bits
                (0b0000 << 12) |  // Next 4 bits
                (0b0000 << 8)  |  // Next 4 bits
                (0b0000 << 4)  |  // Next 4 bits
                (0b0000);          // Last 4 bits (LSB)

    graph[30] = (0b1001 << 28) |  // First 4 bits (MSB)
                (0b0000 << 24) |  // Next 4 bits
                (0b1000 << 20) |  // Next 4 bits
                (0b0000 << 16) |  // Next 4 bits
                (0b0000 << 12) |  // Next 4 bits
                (0b0000 << 8)  |  // Next 4 bits
                (0b0000 << 4)  |  // Next 4 bits
                (0b0000);          // Last 4 bits (LSB)

    graph[31] = (0b0100 << 28) |  // First 4 bits (MSB)
                (0b0000 << 24) |  // Next 4 bits
                (0b0000 << 20) |  // Next 4 bits
                (0b0000 << 16) |  // Next 4 bits
                (0b0000 << 12) |  // Next 4 bits
                (0b0000 << 8)  |  // Next 4 bits
                (0b0000 << 4)  |  // Next 4 bits
                (0b0000);          // Last 4 bits (LSB)



    // ##############################################

    // the node values are written into data memory sequentially.
    for (int i = 0; i < idx; ++i) {
        NODE_POINT = path_planned[i];
    }
    // Path Planning Computation Done Flag
    CPU_DONE = 1;

    #ifdef __linux__    // for host pc

        _put_str("######### Planned Path #########\n");
        for (int i = 0; i < idx; ++i) {
            _put_value(path_planned[i]);
        }
        _put_str("################################\n");

    #endif

    return 0;
}

