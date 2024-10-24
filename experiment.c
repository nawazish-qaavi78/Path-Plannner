#include<stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <stdint.h>

#define V 32

int min_cost(int *cost, bool *processed) {
    uint8_t min = UINT8_MAX;
    int8_t index = -1;
    for(uint8_t i = 0; i<V; i++){
        if(!processed[i]) {
            if(cost[i]<min){
                index = i;
                min = cost[i];
            } 
        }
    }
    return index;
}

void algo(uint8_t start_node, uint8_t end_node, uint32_t* graph){
    // setting up the variables
    uint8_t cost[V], parent[V];
    bool processed[V];

    for(uint8_t i = 0; i<V; i++){
        parent[i] = -1;
        processed[i] = false;
        if(i != start_node) cost[i] = UINT8_MAX;
        else cost[i] = 0;
    }

    // starting the algo
    for(uint8_t j = 0; j<V; j++){
        uint8_t index = 0;
        int8_t parent_index = 0;
        parent_index = min_cost(cost, processed);
        for(index = 0; index<V; index++){
            if(graph[parent_index] & (1<<index)){
                if(cost[index] > cost[parent_index] + 1) {
                    cost[index] = cost[parent_index] + 1;
                    parent[index] = parent_index;
                }
                if(index == end_node) break; // considering all of equal weight edges
            }
        }
        processed[parent_index] = true;
        if(index == end_node) break;
    }
    
    // decoding the output
    uint8_t j = end_node;
    while(j!=-1){
        printf("%d\n", j);
        j = parent[j];
    }
}

int main(){
    uint32_t graph[V];


     graph[0] = (0b0000 << 28) |  // First 4 bits (MSB)
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


    uint8_t start_node = 0, end_node = 5;
    algo(start_node, end_node, graph);

    return 0;
}