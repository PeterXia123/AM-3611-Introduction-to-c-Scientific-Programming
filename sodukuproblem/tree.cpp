//
//  tree.cpp
//  3611miniproject
//
//  Created by yufei xia on 2018/12/1.
//  Copyright © 2018年 yufei xia. All rights reserved.
//

#include<iostream>
using namespace std;

class BST
{
    struct node
    {
        int data;
        int** board;
        node* left;
        node* right;
    };
    
    node* root;
  
    node* makeEmpty(node* t)
    {
        if(t == NULL)
            return NULL;
        {
            makeEmpty(t->left);
            makeEmpty(t->right);
            delete t;
        }
        return NULL;
    }
    
    node* insert(int x, node* t,int** board)
    {
        if(t == NULL)
        {
            t = new node;
            t->data = x;
            t->board = board;
            t->left = t->right = NULL;
        }
        else if(x < t->data)
            t->left = insert(x, t->left, board);
        else if(x > t->data)
            t->right = insert(x, t->right, board);
        return t;
    }
    
    node* findMin(node* t)
    {
        if(t == NULL)
            return NULL;
        else if(t->left == NULL)
            return t;
        else
            return findMin(t->left);
    }
    
    node* findMax(node* t)
    {
        if(t == NULL)
            return NULL;
        else if(t->right == NULL)
            return t;
        else
            return findMax(t->right);
    }
    
    node* remove(int x, node* t)
    {
        node* temp;
        if(t == NULL)
            return NULL;
        else if(x < t->data)
            t->left = remove(x, t->left);
        else if(x > t->data)
            t->right = remove(x, t->right);
        else if(t->left && t->right)
        {
            temp = findMin(t->right);
            t->data = temp->data;
            t->right = remove(t->data, t->right);
        }
        else
        {
            temp = t;
            if(t->left == NULL)
                t = t->right;
            else if(t->right == NULL)
                t = t->left;
            delete temp;
        }
        
        return t;
    }
    
    
    
    node* find(node* t, int x)
    {
        if(t == NULL)
            return NULL;
        else if(x < t->data)
            return find(t->left, x);
        else if(x > t->data)
            return find(t->right, x);
        else
            return t;
    }
    
public:
    BST()
    {
        root = NULL;
    }
    
    
    
    void clean()
    {
        root = makeEmpty(root);
    }
    
    void insert(int x,int** board)
    {
        root = insert(x, root, board);
    }
    
    void remove(int x)
    {
        root = remove(x, root);
    }
    
    
    int** smallestboard(){
      node* node = findMin(root);
        return node->board;
    }
    int smallestherst(){
        node* node = findMin(root);
        return node->data;
    }
    
    void search(int x)
    {
        root = find(root, x);
    }
};


