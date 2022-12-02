//
// Created by cviten on 12/2/22.
//

#ifndef TOP_DOWN_SHOOTER_UTIL_H
#define TOP_DOWN_SHOOTER_UTIL_H

template <typename KeyType, typename ValueType>
inline ValueType getValueOrDefault(const std::map<KeyType,ValueType>& map, const KeyType& key)
{
    auto it = map.find(key);
    if(it != map.end()) return it->second;
    return {};
}

#endif //TOP_DOWN_SHOOTER_UTIL_H
