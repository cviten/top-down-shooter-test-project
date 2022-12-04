//
// Created by cviten on 12/2/22.
//

#ifndef TOP_DOWN_SHOOTER_UTIL_H
#define TOP_DOWN_SHOOTER_UTIL_H

template <typename Container>
inline typename Container::mapped_type getValueOrDefault(const Container& map, const typename Container::key_type& key)
{
    auto it = map.find(key);
    if(it != map.end()) return it->second;
    return {};
}

#endif //TOP_DOWN_SHOOTER_UTIL_H
