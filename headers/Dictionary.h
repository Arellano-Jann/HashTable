#pragma once
#define DICTIONARY_H
#include "Entry.h"
#include <functional>

template <typename KeyType, typename ValueType>
class Dictionary {
    static const int hashTableSize = 1024;
    Entry hashTable[hashTableSize];
    int hash(const KeyType& key) const;
public:
    bool isEmpty() override;
    int getNumberOfEntries() override;
    bool add(const KeyType& newKey, const ValueType& newValue) override;
    bool remove(const KeyType& key) override;
    bool clear() override;
    bool contains(const KeyType& key) override; // sees if key is inside dictionary
    ValueType getValue(const KeyType& key) override; // gets the value of a key
    ~Dictionary();
};