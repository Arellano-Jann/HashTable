template <typename KeyType, typename ValueType>
int Dictionary<KeyType, ValueType>::hash(const KeyType& key) const {
    return std::hash<KeyType> keyHash(key);
}

template <typename KeyType, typename ValueType>
bool Dictionary<KeyType, ValueType>::isEmpty() const{
    return itemCount == 0;
}

template <typename KeyType, typename ValueType>
int Dictionary<KeyType, ValueType>::getNumberOfEntries() const{
    return itemCount;
}

template <typename KeyType, typename ValueType>
bool Dictionary<KeyType, ValueType>::add(const KeyType& newKey, const ValueType& newValue){
    if (contains(newKey)) {
        return false;
    }
    int hashIndex = hash(newKey);

}

template <typename KeyType, typename ValueType>
bool Dictionary<KeyType, ValueType>::remove(const KeyType& key){

}

template <typename KeyType, typename ValueType>
bool Dictionary<KeyType, ValueType>::clear(){ // check if this is valid
    while (itemCount > 0){
        if (remove(hashTable[0].getKey())){
            itemCount--;
        }
    }
}

template <typename KeyType, typename ValueType>
bool Dictionary<KeyType, ValueType>::contains(const KeyType& key) const{
    int index = hash(key);
    while (hashTable[index].getKey() != key){
        index++;
        if (hashTable[index].getKey() == key) return true;
    }
    return false;
}

template <typename KeyType, typename ValueType>
ValueType Dictionary<KeyType, ValueType>::getValue(const KeyType& key) const{
    int index = hash(key);
    return hashTable[index].getValue();
}

template <typename KeyType, typename ValueType>
Dictionary<KeyType, ValueType>::~Dictionary(){
    clear();
}