/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/

#include <stdio.h>
#include <stdlib.h>


#define MAX_SIZE 1000
struct node {
    int num;
    int position;
};

struct elements{
    struct node data;
    struct elements *next;
};

int hashFunction(int key){
    int r = key % MAX_SIZE;
    return r < 0 ? r + MAX_SIZE : r;
}

void insert(struct node info, struct elements *hashTable[]){
    int hashKey = hashFunction(info.num);
    struct elements *temp = malloc(sizeof(struct elements));
    temp->data = info;
    temp->next = hashTable[hashKey];
    hashTable[hashKey] = temp;
}

void show(struct elements *hash_table[])
{
      int count;
      struct elements *ptr;
      for(count = 0; count < MAX_SIZE; count++)
      {
            if(hash_table[count] != NULL)
            {
                  ptr = hash_table[count];
                  while(ptr != NULL)
                  {
                        printf("%d %d\t", ptr->data.num, ptr->data.position);
                        ptr=ptr->next;
                  }
            }
      }
      printf("\n");
}

int search(int key, struct elements *hash_table[])
{
    int h;
    struct elements *ptr;
    h = hashFunction(key);
    ptr = hash_table[h];
    while(ptr != NULL)
    {
        if(ptr->data.num == key)
        {
                return ptr->data.position;
        }
        ptr = ptr->next;
    }
    return -1;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    *returnSize = 2;
    struct elements *hashTable[MAX_SIZE];
    int i, diff, position=-1;
    for (i=0; i<MAX_SIZE; i++){
        hashTable[i] = NULL;
    }
    struct node info;
    for(i=0; i<numsSize; i++){
        diff = target - nums[i];
        position = search(diff, hashTable);
        if (position>=0){
            int *returnElements = (int*)malloc(2*sizeof(int));
            returnElements[0] = position;
            returnElements[1] = i;
            return returnElements;
        }
        info.num = nums[i];
        info.position = i;
        insert(info, hashTable);
        //show(hashTable);
    }
    
    return 0;
}
