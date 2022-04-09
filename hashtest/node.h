#ifndef node_h
#define node_h

#include<iostream>
#include <any>

using namespace std;

typedef unsigned int uint;

template<typename T>
class linkedlist;

// readonly class by design
template <typename T>
class node {
private:
	string key;
	T data;
	uint hash;
	node* nxt;
	node* prv;
	linkedlist<T>* owner;

	node(T data, linkedlist<T>* owner, node* prev = 0, node* next = 0) {
		this->nxt = next;
		this->prv = prev;
		this->data = data;
		this->owner = owner;
	}

	node(T data, linkedlist<T>* owner, string key, uint hash, node* prev = 0, node* next = 0) {
		this->nxt = next;
		this->prv = prev;
		this->data = data;
		this->hash = hash;
		this->key = key;
		this->owner = owner;
	}

	template<typename T> friend class linkedlist;
public:
	string getkey() { return key; }
	T& getdata() { return data; }
	uint gethash() { return hash; }
	node* next() { return nxt; }
	node* prev() { return prv; }
};

#endif