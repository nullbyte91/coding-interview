#include <stdio.h>
#include <stdlib.h>

// Hash table size 
#define TABLE_SIZE 13 
  
// Used in second hash function. 
#define PRIME 7 

// Hash Table
int *hashTable, curr_size;

// function to check if hash table is full 
int isFull(){
    return (curr_size == TABLE_SIZE);
}

// function to calculate first hash 
int hash1(int key) 
{ 
    return (key % TABLE_SIZE); 
}

// function to calculate second hash 
int hash2(int key) 
{ 
    return (PRIME - (key % PRIME)); 
} 

void insertHash(int key){
    // if hash table is full 
    if(isFull())
        return;
    // get index from first hash 
    int index = hash1(key); 

    // if collision occurs 
    if (*(hashTable+index) != -1) 
    { 
        // get index2 from second hash 
        int index2 = hash2(key); 
        int i = 1; 
        while (1) 
        { 
            // get newIndex 
            int newIndex = (index + i * index2) % 
                                    TABLE_SIZE; 

            // if no collision occurs, store 
            // the key 
            if (*(hashTable+newIndex) == -1) 
            { 
                *(hashTable+newIndex) = key; 
                break; 
            } 
            i++; 
        } 
    } 

    // if no collision occurs 
    else
        *(hashTable+index) = key; 
    curr_size++;
}

// function to display the hash table 
void displayHash() 
{ 
    for (int i = 0; i < TABLE_SIZE; i++) 
    {
        if (*(hashTable+i) != -1) 
            printf("%d --> %d\n", i, *(hashTable+i));
        else
            printf("%d\n", i);
    } 
}
int main() 
{ 
    int i;
    int a[] = {19, 27, 36, 10, 64}; 
    int n = sizeof(a)/sizeof(a[0]); 
  
    // inserting keys into hash table 
    hashTable = (int*)malloc(TABLE_SIZE*sizeof(int));
    for (i=0; i<TABLE_SIZE; i++){
        *(hashTable+i) = -1;
    }
    for (i = 0; i < n; i++){
        insertHash(a[i]);
    }
    displayHash();
    return 0; 
}