//
//  main.cpp
//  try&test
//
//  Created by Praneeth Patil on 9/30/17.
//  Copyright © 2017 Praneeth Patil. All rights reserved.
//
#include <locale>
#include <ctype.h>
#include <string>
#include <iostream>
#include <memory>
#include <vector>
#include <set>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;
struct ListNode {
    ListNode* next;
    int  val;
    ListNode(int val) : next(nullptr), val(val) {}
};



class QuickSort {
public:
    void quickSort(vector<int>& in) {
        if (in.size() < 2) return;
        quickSort(in, 0, in.size()-1);
    }
    
    void quickSort(vector<int> &in, size_t low, size_t high) {
        if (low < high) {
            int p = patrition(in, low, high);
            if (p < 0) return;
            quickSort(in, low, p-1);
            quickSort(in, p+1, high);
        }
    }

    int patrition(vector<int>& in, size_t low, size_t high) {
        if ((low > in.size()) || (high > in.size())) return -1;
        int pivot = in[high];
        size_t sm = low;
        for (size_t i = low; i < high; ++i) {
            if (in[i] <= pivot) {
                swap(in[i], in[sm++]);
            }
        }
        cout << " hi " << in[high] << " sm " << in[sm] << endl;
        swap(in[high], in[sm]);
        return static_cast<int>(sm);
    }
    
};

struct SListNode {
    int val;
    SListNode* next;
    SListNode(int v) : val(v), next(nullptr) {}
};

class MergeSort {
public:
    SListNode* Sort(SListNode* head) {
        if (!head && !(head)->next) return head;
        SListNode *fast = head, *slow = head;
        while(fast && fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        if (slow == fast) return  head;
        SListNode* s = slow->next;
        (*slow).next = nullptr;
        SListNode* f = head;
        f = Sort(f);
        s = Sort(s);
        auto merged = Merge(f, s);
        return merged;
    }
    
    SListNode* Merge(SListNode* f, SListNode* s) {
        if (!f) return s;
        if (!s) return f;
        Print(f);
        Print(s);
        SListNode* ret_head = nullptr;
        if (f->val < s->val) {
            ret_head = f;
            f = f->next;
        } else {
            ret_head = s;
            s = s->next;
        }
        SListNode* ret_tail = ret_head;
        while(f && s) {
            if (f->val < s->val) {
                (*ret_tail).next = f;
                f = f->next;
            } else {
                (*ret_tail).next = s;
                s = s->next;
            }
            ret_tail = ret_tail->next;
        }
        Print(f);
        Print(s);
        ret_tail->next =  f == nullptr ? s : f;
        return ret_head;
    }
    
    SListNode* CreateSList(vector<int> in) {
        SListNode *head = nullptr, *tail = nullptr;
        
        for (auto& i : in) {
            if (!head) {
                head = new SListNode(i);
                tail = head;
            } else {
                tail->next = new SListNode(i);
                tail = tail->next;
            }
        }
        return head;
    }
    
    void Print(SListNode* head) {
        while (head) {
            cout << head->val << " -> ";
            head = head->next;
        }
        cout << endl;
    }
};

int main() {
#if 0
    // Quick sort
    vector<int> in {1, 5,80,90, 10, 15, 10,  60};
    QuickSort q;
    q.quickSort(in);
    for (auto& i : in) {
        cout << i << " ";
    }
    cout <<  endl;
#endif

    // Merge sort
    
    vector<int> m_in {1, 5,80,90, 10, 15, 10,  60};
    MergeSort m;
    auto head = m.CreateSList(m_in);
    m.Print(head);
    head = m.Sort(head);
    m.Print(head);
    return 0;
}
