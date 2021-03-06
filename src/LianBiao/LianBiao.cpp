﻿using namespace std;
#include <iostream>
#include "stdlib.h"

struct LianBiao {
    int data;
    LianBiao* pre;
    LianBiao* next;
};

LianBiao* set(int* array) {
    
    // 第一个元素
    LianBiao* last = (LianBiao*) malloc (sizeof(LianBiao));
    LianBiao* cur = last;
    last->data = array[0];
    LianBiao* head = last;
    int size = 9;
    // 从一开始，减去第一个元素
    for (int i = 1; i < size; i++) {
        cur = (LianBiao*) malloc (sizeof(LianBiao));
		cur->data = array[i];
		last->next = cur;
		last = cur;
    }
    
    last = NULL;
    cur = NULL;
	return head;
}

void get(LianBiao* head) {
    LianBiao* iterator = head;
    while (iterator != NULL) {
        cout<<iterator->data<<"\t";
		iterator = iterator->next;
    }
    cout<<"\n";
}

bool hasCycle(LianBiao* head) {
        if (head == NULL) {
            return false;
        }
        LianBiao* ahead;
        LianBiao* behind;
        ahead = head->next;
        int aheadPos = 1;
        int behindPos = 0;
        while (ahead != NULL) {
            behind = head;
            behindPos = 0;
            while (behind != ahead) {
                behind = behind->next;
                behindPos++;
            }
            if (aheadPos != behindPos) {
                return true;
            }
            ahead = ahead->next;
            aheadPos++;
        }
        return false;
    }
	
int main() {
    struct LianBiao* head;
    int a[9] = {1,3,5,6,7,3,5,7,1};
    head = set(&a[0]);
    get(head);
	if(hasCycle(head)) {
		cout<<"true";
	} else {
		cout<<"false";
	}
    return 0;
}
