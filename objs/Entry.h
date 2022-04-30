#pragma once
#define ENTRY_H

template <typename KeyType, typename ValueType>
class Entry {
    KeyType key;
    ValueType value;
public:
    Entry();
        : key()
        , value() {}
    Entry(const KeyType& key, const ValueType& value)
        : key(key)
        , value(value) {}
    void setKey(const KeyType& key) { this->key = key; }
    void setValue(const ValueType& value) { this->value = value; }
    const KeyType& getKey() const { return key; }
    const ValueType& getValue() const { return value; }
    bool operator==(const Entry<KeyType, ValueType>& rhs) const; // checks if both entries are the same
    bool operator==(const KeyType& rhs) const; // check if both keys are the same
    bool operator >(const Entry<KeyType, ValueType>& rhs) const; // checks if the entry is greater than rhs entry
    bool operator >(const KeyType& rhs) const; // checks if the key is greater than rhs key
};