#include "hashmap.h"

uint hashmap::rollhash32(const string& key, int b, int m) {
    uint hash = 0;
    uint coeff = 1;

    for (int i = 0; i < key.size(); i++) {
        hash = (hash + key[i] * coeff) % m;
        coeff *= b;
        coeff %= m;
    }

    return hash;
}

uint hashmap::hashof(const string& key) {
    return rollhash32(key, 257, 1761471161);
}

void hashmap::calc(const string& key, uint bsz, uint& hash, int& bi) {
    hash = hashof(key);
    bi = hash % bsz;
}

bool hashmap::insert(const string& key, const any& value) {
    uint hash;
    int bi;
    calc(key, bsz, hash, bi);

    if (buckets[bi].find(key) != 0)
        return false;

    if (sz == bsz) resize();

    buckets[bi].append(value, key, hash);
    sz++;
    return true;
}

void hashmap::resize() {
    uint nsz = bsz * 2;
    linkedlist<any>* nbuckets = new linkedlist<any>[nsz];

    for (int i = 0; i < bsz; i++) {
        linkedlist<any>::iterator it = buckets[i].begin();

        while (it != buckets[i].end()) {
            nbuckets[it->gethash() % nsz].append(it->getdata(), it->getkey(), it->gethash());
            ++it;
        }
    }

    bsz = nsz;
    delete[] buckets;
    buckets = nbuckets;
}

any* hashmap::get(const string& key) const {
    uint hash;
    int bi;
    calc(key, bsz, hash, bi);
    node<any>* ptr;

    if ((ptr = buckets[bi].find(key)) == 0)
        return 0;

    return &ptr->getdata();
}

hashmap::hashmap() {
    buckets = new linkedlist<any>[bsz = 5];
    sz = 0;
}

proxy hashmap::operator[](const string& key) {
    return proxy(key, this);
}

bool hashmap::del(string key) {
    uint hash;
    int bi;
    calc(key, bsz, hash, bi);
    node<any>* p = buckets[bi].find(key);

    if (p == 0)
        return false;

    buckets[bi].del(p);
    sz--;
    return true;
}

void* proxy::operator=(any a) {
    ptr->insert(key, a);
    return 0;
}

proxy::operator any& () {
    any* p = ptr->get(key);

    if (p == 0)
        throw "Error: queried entity not found";

    return *p;
}


hashmap::~hashmap() {
    delete[] buckets;
}