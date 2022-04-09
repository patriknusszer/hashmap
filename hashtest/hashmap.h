#ifndef hashmap_h
#define hashmap_h

// a naive, less flexible unordered_map reimplementation

#include "linkedlist.h"
#include "node.h"

typedef unsigned int uint;

class hashmap;

class proxy {
private:
    string key;
    hashmap* ptr;
    friend class hashmap;
public:
    proxy(string key, hashmap* hm) : key(key), ptr(hm) {}
    void* operator=(any a);
    operator any& ();
};

class hashmap {
private:
	uint sz;
	uint bsz;
	linkedlist<any>* buckets;
    static uint rollhash32(const string& key, int b, int m);
    static uint hashof(const string& key);
    static void calc(const string& key, uint bsz, uint& hash, int& bi);
    void resize();
public:
    bool insert(const string& key, const any& value);
    any* get(const string& key) const;
    hashmap();
    proxy operator[](const string& key);
    bool del(string key);
    ~hashmap();
};

#endif /* hashmap_h */