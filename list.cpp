//
//  main.cpp
//  list
//
//  Created by sunpeiyang on 2016/11/20.
//  Copyright © 2016年 sun. All rights reserved.
//
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

typedef struct Element
{
    struct Element *next;
    int data;
}Element;


bool insertFront(Element **head, int data)
{
    Element *newElem = (Element*)malloc(sizeof(Element));
    newElem->data = data;
    
    newElem->next = *head;
    
    *head = newElem;
    
    return true;
}

bool insertEnd(Element* head, int data)
{
    Element* tail = head;
    
    while (tail->next)
        tail = tail->next;
    
    Element *newElem = (Element*)malloc(sizeof(Element));
    newElem->data = data;
    
    tail->next = newElem;
    return true;
}

bool printList(Element* head)
{
    while (head->next)
    {
        printf("%d\n", head->data);
        head = head->next;
    }
    printf("%d\n", head->data);
    
    return true;

}

bool deleteElement(Element** head, Element* deleteMe)
{
    Element* elem;
    if (!head || !*head || !deleteMe)
        return false;
    
    elem = *head;
    if (deleteMe == *head)
    {
        *head = elem->next;
        free(deleteMe);
        return true;
    }
    
    while (elem->next == deleteMe)
    {
        elem->next = deleteMe->next;
        free(deleteMe);
        return true;
    }
    elem = elem->next;
    
    return false;
}

void deleteList(Element** head)
{
    Element* deleteMe = *head;
    
    while (deleteMe)
    {
        Element* next = deleteMe->next;
        free(deleteMe);
        deleteMe = next;
    }
    
    return;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    Element* head = (Element*)malloc (sizeof(Element));
    head->data = 1;
    
    //insertFront(&head, 2);
    //insertFront(&head, 3);
    insertEnd(head, 2);
    insertEnd(head, 3);
    
    printList(head);
    
    
    return 0;
}
