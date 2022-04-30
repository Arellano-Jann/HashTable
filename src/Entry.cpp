template <typename KeyType, typename ValueType>
bool Entry<KeyType, ValueType>::operator==(const Entry<KeyType, ValueType>& rhs) const {
    return key == rhs.getKey() && value == rhs.getValue();
}

template <typename KeyType, typename ValueType>
bool Entry<KeyType, ValueType>::operator==(const KeyType& rhs) const {
    return key == rhs;
}

template <typename KeyType, typename ValueType>
bool Entry<KeyType, ValueType>::operator>(const Entry<KeyType, ValueType>& rhs) const {
    return key > rhs.getKey();
}

template <typename KeyType, typename ValueType>
bool Entry<KeyType, ValueType>::operator>(const KeyType& rhs) const {
    return key > rhs;
}