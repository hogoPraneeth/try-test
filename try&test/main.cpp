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
        if (!head) return head;
        if (!(head)->next) return nullptr;
        SListNode *fast = head->next, *slow = head;
        while(fast) {
            fast = fast->next;
            if (fast != nullptr) {
                slow = slow->next;
                fast = fast->next;
            }
        }
        SListNode* s = slow->next;
        (*slow).next = nullptr;
        SListNode* f = head;
        cout << "f : ";
        Print(f);
        cout << "s : ";
        Print(s);
        f = Sort(f);
        s = Sort(s);
        
        cout << "MERGED\n";
        auto merged = Merge(f, s);
        Print(merged);
        cout << "----------------\n";
        return merged;
    }
    
    SListNode* Merge(SListNode* f, SListNode* s) {
        if (!f) return s;
        if (!s) return f;
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


class ArrayHeap {
public:
    void heapify(vector<int>& v, int len, int i) {
        int lar = i;
        int l = (2*i) + 1, r = (2*i) + 2;
        
        if ((l < len) && v[lar] < v[l]) {
            lar = l;
        }
        if ((r < len) && v[lar] < v[r]) {
            lar = r;
        }
        if (lar != i) {
            swap(v[lar], v[i]);
            heapify(v, len, lar);
        }
    }
    
    void swap(int& a, int&b) {
        int t = a;
        a = b;
        b = t;
    }
    void Print(vector<int>& v) {
        for (auto& i :v) {
            cout << i << " ";
        }
        cout <<  endl;
    }
    void HeapSort(vector<int>& v, int len) {
        if (v.size() <= 0) return;
        static int j = 0;
        for (int i = (len/2)-1; i >= 0; --i) {
            heapify(v, len, i);
            cout << j++ << endl;
        }
        for (int i = len-1; i >= 0; --i) {
            swap(v[0], v[i]);
            heapify(v, i, 0);
        }
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

#if 0
    // Merge sort
    
    vector<int> m_in {1, 5,80,90, 10, 15, 10,  60, 70};
    MergeSort m;
    auto head = m.CreateSList(m_in);
    m.Print(head);
    head = m.Sort(head);
    m.Print(head);
    return 0;
#endif
    vector<int> h_in {1, 5,80,90, 10, 15, 10,  60, 70};
    ArrayHeap a;
    a.HeapSort(h_in, 9);
    a.Print(h_in);
    
}
