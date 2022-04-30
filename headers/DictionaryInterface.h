#pragma once
#define DICTIONARYINTERFACE_H

template <typename KeyType, typename ValueType>
class DictionaryInterface {

public:
    virtual bool isEmpty() const = 0;
    virtual int getNumberOfEntries() const = 0;
    virtual bool add(const KeyType& newKey, const ValueType& newValue) = 0;
    virtual bool remove(const KeyType& key) = 0;
    virtual bool clear() = 0;
    virtual bool contains(const KeyType& key) const = 0; // sees if key is inside dictionary
    virtual ValueType getValue(const KeyType& key) const = 0; // gets the value of a key
    virtual ~DictionaryInterface() {}
};