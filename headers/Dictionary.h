#pragma once
#define DICTIONARY_H
#include "Entry.h"
#include <functional>

template <typename KeyType, typename ValueType>
class Dictionary {
    static const int hashTableSize = 1024;
    int itemCount = 0;
    Entry<KeyType, ValueType> hashTable[hashTableSize]; // is this correct?
    int hash(const KeyType& key) const;
public:
    bool isEmpty() const override;
    int getNumberOfEntries() const override;
    bool add(const KeyType& newKey, const ValueType& newValue) override;
    bool remove(const KeyType& key) override;
    bool clear() override;
    bool contains(const KeyType& key) const override; // sees if key is inside dictionary
    ValueType getValue(const KeyType& key) const override; // gets the value of a key
    ~Dictionary();
};

#include "../src/Dictionary.cpp"