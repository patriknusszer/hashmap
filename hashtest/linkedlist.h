#ifndef linkedlist_h
#define linkedlist_h

#include "node.h"

typedef unsigned int uint;

template <typename T>
class linkedlist {
private:
	node<T>* head;
	node<T>* tail;
	size_t sz;
public:
	class iterator {
	private:
		node<any>* ptr;

		iterator(node<any>* ptr) {
			this->ptr = ptr;
		}

		template <typename T>
		friend class linkedlist;
	public:
		bool operator!=(const iterator& it) const {
			return ptr != it.ptr;
		}

		iterator& operator++() {
			if (ptr != 0)
				ptr = ptr->next();

			return *this;
		}

		node<any>& operator*() const {
			if (ptr == 0)
				throw "Error: end iterator can not be dereferenced";

			return *ptr;
		}

		operator node<any>*() const {
			if (ptr == 0)
				throw "Error: end iterator can not be dereferenced";

			return ptr;
		}

		node<any>* operator->() const {
			if (ptr == 0)
				throw "Error: end iterator can not be dereferenced";

			return ptr;
		}
	};

	iterator begin() {
		return iterator(head);
	}

	iterator end() {
		return iterator(0);
	}

	void traverse() {
		
	}

	linkedlist() {
		sz = 0;
		tail = head = 0;
	}

	size_t size() { return sz; }

	void append(const T& data, string key, uint hash) {
		if (head == 0)
			tail = head = new node<T>(data, this, key, hash);
		else
			tail = tail->nxt = new node<T>(data, this, key, hash, tail);
	}

	void append(const T& data) {
		if (head == 0)
			tail = head = new node<T>(data, this);
		else
			tail = new node<T>(data, this, tail);
	}

	node<T>* find(const string& key) const {
		node<T>* n = head;

		for (; n != 0; n = n->next())
			if (n->key == key)
				return n;

		return 0;
	}

	void del(node<T>* n) {
		if (n->owner != this)
			throw "Error: can not delete a node of another linked list";

		if (n->prv != 0)
			n->prv->nxt = n->nxt;
		else
			head = n->nxt;

		if (n->nxt != 0)
			n->nxt->prv = n->prv;
		else
			tail = n->prv;

		delete n;
	}

	~linkedlist() {
		iterator it = begin();

		while (it != end()) {
			node<any>* cur = it;
			cout << cur->key << endl;
			++it;
			delete cur;
		}
	}
};

#endif