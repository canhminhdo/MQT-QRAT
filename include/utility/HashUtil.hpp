//
// Created by CanhDo on 2024/12/17.
//

#ifndef HASHUTIL_HPP
#define HASHUTIL_HPP

class HashUtil {
public:
    static std::size_t combinedHash(std::size_t hash1, std::size_t hash2) {
        hash1 ^= hash2 + 0x9e3779b9 + (hash1 << 6) + (hash1 >> 2);
        return hash1;
    }
};

#endif //HASHUTIL_HPP
