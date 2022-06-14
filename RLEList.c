#include "RLEList.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char symbol;
    int appearance;
    struct node* next;
} *Node;

struct RLEList_t {

    Node head;
};

//This function returns the allocated memory.
// Note that the caller is responsible to free it.
int numOfDigits(int num);
void fixSame(RLEList list);
RLEList RLEListCreate()
{
    RLEList list = malloc(sizeof(RLEList));
    list->head = NULL;
    return list;
}
void RLEListDestroy(RLEList list)
{
    while (list->head)
    {
        Node toDelete = list->head;
        list->head = toDelete->next;
        free(toDelete);
    }
    free(list);
}
RLEListResult RLEListAppend(RLEList list, char value)
{
    if (!list || !value)
    {
        return RLE_LIST_NULL_ARGUMENT;
    }
    if(!list->head)
    {
        list->head = malloc(sizeof (*(list->head)));
        list->head->next=NULL;
        list->head->symbol=value;
        list->head->appearance=1;
        return RLE_LIST_SUCCESS;
    }
    Node tempNode = list->head;
    while (tempNode->next)
    {
        tempNode = tempNode->next;
    }
    if (tempNode->symbol == value)
    {
        tempNode->appearance++;
    }
    else {
        Node  newNode = malloc(sizeof (*newNode));
        if (!newNode){
            return RLE_LIST_OUT_OF_MEMORY;
        }
        newNode->next=NULL;
        newNode->symbol=value;
        newNode->appearance=1;
        tempNode->next = newNode;
    }
    return RLE_LIST_SUCCESS;
}
int RLEListSize(RLEList list)
{
    if (!list)
    {
        return -1;
    }
    Node tempNode = list->head;
    int size = 0;
    while (tempNode) {
        size += tempNode->appearance;
        tempNode = tempNode->next;
    }
    return size;
}
void fixSame(RLEList list){
    if(!list || !list->head)
    {
        return;
    }
    Node tempNode = list->head;
    Node tempNode1 = tempNode->next;
    while (tempNode1){
        if(tempNode1->symbol == tempNode->symbol){
            tempNode->appearance+=tempNode1->appearance;
            tempNode->next = tempNode1->next;
            free(tempNode1);
            tempNode1 = tempNode->next;
        }
        else{
            tempNode=tempNode1;
            tempNode1 = tempNode1->next;
        }
    }
}

RLEListResult RLEListRemove(RLEList list, int index)
{
    if (!list)
    {
        return RLE_LIST_NULL_ARGUMENT;
    }
    if (RLEListSize(list) <= index || index < 0)
    {
        return RLE_LIST_INDEX_OUT_OF_BOUNDS;
    }

    Node currentNode = list->head;
    Node previousNode = NULL;
    while (index >= 0)
    {
        if (index - (currentNode->appearance) < 0)
        {
            currentNode->appearance--;
            break;
        }
        index -= currentNode->appearance;
        previousNode = currentNode;
        currentNode = currentNode->next;
    }
    if(currentNode->appearance==0)
    {
        if(!previousNode){
            list->head=currentNode->next;
            free(currentNode);
        }
        else {
            previousNode->next = currentNode->next;
            free(currentNode);
        }
    }
    return RLE_LIST_SUCCESS;
}
char RLEListGet(RLEList list, int index, RLEListResult* result)
{
    if (!list)
    {
        if (result){
            *result = RLE_LIST_NULL_ARGUMENT;
        }
        return 0;
    }
    if (RLEListSize(list) <= index || index < 0)
    {
        if(result){
            *result = RLE_LIST_INDEX_OUT_OF_BOUNDS;
        }
        return 0;
    }

    Node tempNode = list->head;
    while (index >= 0)
    {
        if (index - (tempNode->appearance) < 0)
        {
            if(result) {
                *result = RLE_LIST_SUCCESS;
            }
            return tempNode->symbol;
        }
        index -= tempNode->appearance;
        tempNode = tempNode->next;
    }

    return 0;
}
char* RLEListExportToString(RLEList list, RLEListResult* result)
{
    fixSame(list);
    if (!list) {
        if (result){
            *result = RLE_LIST_NULL_ARGUMENT;
        }
        return 0;
    }
    Node tempNode = list->head;
    int counter_nodes = 0;
    /*if (tempNode->appearance){
        counter_nodes = 1;
    }*/
    int lenOfAppearance=0;
    while (tempNode) {
        if(tempNode->appearance>0){
            counter_nodes++;
        }
        lenOfAppearance+= (tempNode->appearance) / 10;
        tempNode = tempNode->next;
    }

    char* str = malloc((sizeof(*str) * 3 * counter_nodes) + 1 + lenOfAppearance);
    if (!str) {
        if (result){
            *result = RLE_LIST_OUT_OF_MEMORY;
        }
        return 0;
    }
    tempNode = list->head;
    lenOfAppearance=0;
    //int previousLenOfAppearance=0;
    for (int i = 0; i < counter_nodes; i++) {
        while(tempNode && !(tempNode->appearance)){
            tempNode = tempNode->next;
        }
        //if(tempNode->symbol==str[3 * (i-1)) + previousLenOfAppearance]){
        //}
        str[(3 * i) + lenOfAppearance] = (tempNode->symbol);
        sprintf((str +3 * i + 1 + lenOfAppearance), "%d", tempNode->appearance);
        lenOfAppearance += numOfDigits(tempNode->appearance);
        str[(3 * i) + 2 + lenOfAppearance] = '\n';
        tempNode = tempNode->next;
    }
    str[(3 * counter_nodes)+lenOfAppearance] = '\0';
    if (result){
        *result = RLE_LIST_SUCCESS;
    }
    return str;
}
int numOfDigits(int num){
    int count=-1;
    while (num != 0) {
        num /= 10;
        ++count;
    }
    return count;
}

RLEListResult RLEListMap(RLEList list, MapFunction map_function) {
    if (!list || !map_function) {
        return RLE_LIST_NULL_ARGUMENT;
    }
    Node tempNode = list->head;
    while (tempNode){
        tempNode->symbol= map_function(tempNode->symbol);
        tempNode = tempNode->next;
    }
    return RLE_LIST_SUCCESS;
}