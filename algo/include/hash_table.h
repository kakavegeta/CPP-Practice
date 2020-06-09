#ifndef _HASH_TABLE_H
#define _HASH_TABLE_H

#include <string>
#include <stdlib.h>
namespace algo {

const std::string NULLKEY = "NULL";
const std::string DUMMY = "DUMMY";

class hashObject {

    public:
    hashObject() {}
    ~hashObject() {}
    hashObject (const hashObject&) = delete;
    hashObject & operator= (const hashObject&) = delete;
    hashObject (hashObject&&) = delete;
    hashObject & operator= (hashObject&&) = delete;

    std::string& val() {
        return _val;
    }

    std::string& key() {
        return _key;
    }

    void setKey (const std::string k) {
        _key = k;
    }

    void setVal (const std::string v) {
        _val = v;
    } 


    void setAsDummy () {
        _key = DUMMY;
        _val = "";
    }

    static const std::string getDummyKey const() {
        return DUMMY;
    } 

    static const std::string getNullKey const () {
        return NULLKEY;
    }

    private:
    std::string _val;
    std::string _key;

};

class HashTable {

    public:
    HashTable(const int n)
        : _size{n}, elems{new hashObject[n]} {
        for(int i=0; i<n; ++i) {
            elems[i].setKey(NULLKEY);
        }
    }

    ~HashTable() {
        delete [] elems;
    }

    HashTable(const HashTable& ht) 
        :_size(ht.size()), elems{new hashObject[ht.size()]}{
        for(int i = 0; i<ht.size(); ++i) {
            elems[i] = ht.elems[i];
        }
    }

    HashTable & operator= (const HashTable& ht) {
        HashTable copy(ht);
        delete [] elems;
        swap(*this, copy);
        return *this;
    }
    /*
    HashTable(HashTable&& ht)
        : _size(ht._size), elems(ht.elems) {
        ht._size = 0;
        ht.elems = nullptr;
    }

    HashTable & operator= (HashTable && rhs) {
        std::move(rhs._size, )
    }
    */


    void swap(const HashTable& lhs, const HashTable& rhs) {
        std::swap(lhs._size, rhs._size);
        std::swap(lhs.elems, rhs.elems);
    }

    size_t size() {
        return _size;
    }


    private:
    int _size;
    hashObject* elems;
    }



}

#endif