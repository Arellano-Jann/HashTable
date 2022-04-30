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
        // if (hashTable[i] == nullptr){
        if (hashTable[i] == Entry<KeyType, ValueType>()){ // if nothing exists in hash table slot
            // hashTable[i].setKey(newKey);
            // hashTable[i].setValue(newValue);
            hashTable[i] = Entry<KeyType, ValueType>(newKey, newValue);
            itemCount++;
            return true;
        }
        if (hashTable[i].getKey() == newKey){ // if already exists then overwrite value
            // hashTable[i].setValue(newValue); // idk which is the better implement
            hashTable[i] = Entry<KeyType, ValueType>(newKey, newValue);
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
        // if (hashTable[i] == nullptr){
        if (hashTable[i] == Entry<KeyType, ValueType>()){ // if nothing exists in hash table slot
            return false;
        }
        if (hashTable[i].getKey() == key){ // if found, remove
            hashTable[i] = Entry<KeyType, ValueType>();
            return true;
        }
    }
    return false;
}

template <typename KeyType, typename ValueType>
bool Dictionary<KeyType, ValueType>::clear(){ // check if this is valid
    int i = 0;
    while (itemCount > 0 && i < hashTableSize){
        if (remove(hashTable[i].getKey())){
            itemCount--;
        }
        i++;
    }
    return true;
    // return itemCount == 0;
}

template <typename KeyType, typename ValueType>
bool Dictionary<KeyType, ValueType>::contains(const KeyType& key) const{
    int index = hash(key);
    do {
        if (hashTable[index].getKey() == key) return true;
        index++;
    } while (hashTable[index].getKey() != key && index < hashTableSize);
    return false;
}

template <typename KeyType, typename ValueType>
ValueType Dictionary<KeyType, ValueType>::getValue(const KeyType& key) const{
    int index = hash(key);
    return hashTable[index].getValue();
}

template <typename KeyType, typename ValueType>
void Dictionary<KeyType, ValueType>::printHashTable() const{
    for (int i = 0; i < hashTableSize; i++){
        if (hashTable[i] != Entry<KeyType, ValueType>()){
            std::cout << "Key: " << hashTable[i].getKey() << " Value: " << hashTable[i].getValue() << std::endl;
        }
        // std::cout << "Index: " << i << " Key: " << hashTable[i].getKey() << " Value: " << hashTable[i].getValue() << std::endl;
    }
}

template <typename KeyType, typename ValueType>
Dictionary<KeyType, ValueType>::~Dictionary(){
    clear();
}