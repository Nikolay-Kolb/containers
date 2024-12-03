#include <functional>
#include <memory>
#include "../Pair.hpp"
#include "../List.hpp"
#include "../Dynamic_Array.hpp"
#include "Hashers/CityHash.hpp"
#include "Hashers/MurmurHash.hpp"

template <typename Key,
         typename Value,
         typename Hash = std::hash<Key>,
         typename KeyEqual = std::equal_to<Key>,
         typename Alloc = std::allocator<Pair<Key, Value>>>
class HashTable {
  private:

    using NodeType = Pair<const Key, Value>;
    using AllocTraits = std::allocator_traits<Alloc>;
    using ListType = List<NodeType, typename AllocTraits::template rebind_alloc<NodeType>>;
    using ListIterator = typename ListType::iterator;
    using ConstListIterator = typename ListType::const_iterator;

    Hash hash_; 
    KeyEqual equal_; // comparator
    Alloc allocator_;
    DynamicArray<ListIterator> hash_table_;
    ListType elements_;

    size_t size_;
    size_t bucket_count_;
    size_t rehash_threshold_;

    static constexpr float MAX_LOAD_FACTOR = 0.8f;
    static constexpr size_t MIN_BUCKET_COUNT = 8;
};



