//
//  main.cpp
//  list
//
//  Created by 孙培养 on 2016/11/21.
//  Copyright © 2016年 sun. All rights reserved.
//  链表 实现 栈

#include <stdio.h>
#include <stdlib.h>

typedef struct Element
{
    Element* next;
    void* data;
    
}Element;

bool push(Element** stack, void *data)
{
    
    Element* ele = (Element*)malloc(sizeof(Element));
    if (!ele)
        return false;
    
    ele->next = *stack;
    ele->data = data;
    
    *stack = ele;
    return true;
}

bool pop(Element** stack, void** data)
{
    if (!*stack)
        return false;
    
    Element* ele = *stack;
    
    *stack = (*stack)->next;
    
    *data = ele->data;
    
    //printf("%d\n", *(int*)data);
    free(ele);
    return true;
}

bool createStack(Element** stack)
{
    *stack = NULL;
    
    return true;
}

bool deleteStack(Element** stack)
{
    Element *next;
    
    while (*stack)
    {
        next = (*stack)->next;
        free(*stack);
        *stack = next;
    }
    
    return true;
}

int main()
{
    Element* stack;
    int i = 2;
    createStack(&stack);
    push(&stack, &i);
    printf("%d\n", *(int*)stack->data);
    int j1= 3;
    push(&stack, &j1);
    printf("%d\n", *(int*)stack->data);

    int* j = new int;
    int* k = new int;

    pop(&stack, (void**)&j);
    printf("%d\n", *j);
    pop(&stack, (void**)&k);
    printf("%d\n", *k);
    return true;
}

//WARNING
//如果 push 时 int i= 2，push， i=3 push， 栈里面时两个3！




