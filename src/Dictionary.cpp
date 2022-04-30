template <typename KeyType, typename ValueType>
int Dictionary<KeyType, ValueType>::hash(const KeyType& key) const {
    std::hash<KeyType> keyHash;
    return keyHash(key) % hashTableSize; // spike this
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
    // if (contains(newKey)) { // don't think i need this actually
    //     return false;
    // }
    int hashIndex = hash(newKey);

    // key placing
    for (int i = hashIndex; i < hashTableSize; i++){ // this iterates through the hash table until it finds an empty spot to place the key value pair
        if (hashTable[i].getKey() == newKey){ // if already exists then overwrite value
            hashTable[i].setValue(newValue);
            return true;
        }
        if (hashTable[i].getKey() == nullptr){ // if nothing exists in hash table slot
            hashTable[i].setKey(newKey);
            hashTable[i].setValue(newValue);
            itemCount++;
            return true;
        }
        // otherwise keep iterating until you find an empty slot
    }
    return false; // failed to add for some reason
}

template <typename KeyType, typename ValueType>
bool Dictionary<KeyType, ValueType>::remove(const KeyType& key){
    int hashIndex = hash(key);

    // key placing
    for (int i = hashIndex; i < hashTableSize; i++){ // this iterates through the hash table until it finds the key
        if (hashTable[i].getKey() == key){ // if found, remove
            hashTable[i].setKey(nullptr);
            return true;
        }
        if (hashTable[i].getKey() == nullptr){ // if nothing exists in hash table slot
            return false;
        }
    }
    return false;
}

template <typename KeyType, typename ValueType>
bool Dictionary<KeyType, ValueType>::clear(){ // check if this is valid
    while (itemCount > 0){
        if (remove(hashTable[0].getKey())){
            itemCount--;
        }
    }
    return true;
    // return itemCount == 0;
}

template <typename KeyType, typename ValueType>
bool Dictionary<KeyType, ValueType>::contains(const KeyType& key) const{
    int index = hash(key);
    while (hashTable[index].getKey() != key && index < hashTableSize){
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