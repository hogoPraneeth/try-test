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
    void Print(vector<int>& v) {
        for (auto& i :v) {
            cout << i << " ";
        }
        cout <<  endl;
    }
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
    void Split(SListNode* head, SListNode** f, SListNode** s) {
        if (!head) return;
        SListNode* fast = head->next;
        SListNode* slow = head;
        while(fast != nullptr) {
            fast = fast->next;
            if (fast) {
                slow = slow->next;
                fast = fast->next;
            }
        }
        *s = slow->next;
        slow->next = nullptr;
        *f = head;
    }

    void Sort(SListNode** head) {
        if (!*head || !(*head)->next) return;
        
        SListNode *f, *s;
        Split(*head, &f,  &s);
        Sort(&f);
        Sort(&s);
        *head = Merge(f, s);
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
        for (int i = (len/2)-1; i >= 0; --i) {
            heapify(v, len, i);
        }
        for (int i = len-1; i >= 0; --i) {
            swap(v[0], v[i]);
            heapify(v, i, 0);
        }
    }
    
};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {
//        cout << "new node : " << val << endl;
    }
};

class TreeHeap {
public:
    TreeNode* BuildHeapTree(vector<int>& in, size_t idx, TreeNode* root) {
        if (idx >= in.size()) return nullptr;
        if (!root)
            root = new TreeNode(in[idx]);
        root->left = BuildHeapTree(in, (2*idx) + 1, root->left);
        root->right = BuildHeapTree(in, (2*idx) + 2, root->right);
        return root;
       
    }
    void PrintTree(TreeNode* root) {
        if (!root) return;
        cout << "\n" <<root->val<< "\n";
        if(root->left)
            cout << root->left->val << "  ";
        if (root->right)
            cout << root->right->val << endl;
        PrintTree(root->left);
        PrintTree(root->right);
    }
};

#define QUICK 0
#define MERGE 0
#define ARRHEAP 0
#define TREEHEAP 1

int main() {
#if QUICK
    cout << "Quick sort -----\n";
    // Quick sort
    vector<int> in {1, 5,80,90, 10, 15, 10,  60};
    QuickSort q;
    q.Print(in);
    q.quickSort(in);
    q.Print(in);
#endif

#if MERGE
    // Merge sort
    cout << "Merge sort -----\n";
    vector<int> m_in {1, 5,80,90, 10, 15, 10,  60, 70};
    MergeSort m;
    auto head = m.CreateSList(m_in);
    m.Print(head);
    m.Sort(&head);
    m.Print(head);
#endif
    
#if ARRHEAP
    cout << "Array Based Heap sort -----\n";
    vector<int> h_in {1, 5,80,90, 10, 15, 10,  60, 70};
    ArrayHeap a;
    a.Print(h_in);
    a.HeapSort(h_in, 9);
    a.Print(h_in);
#endif
    
#if TREEHEAP
    cout << "TREE Based Heap sort -----\n";
    vector<int> t_in {1, 5,80,90, 10, 15, 10,  60, 70};
    TreeHeap t;
    TreeNode* root = nullptr;
    auto h_root = t.BuildHeapTree(t_in, 0, root);
    t.PrintTree(h_root);
#endif

    return 0;
}
