#include <cassert>  // assert
#include <cstddef>  // size_t
#include <cstdint>  // uint64_t, uint32_t

// Expands the binary representation of input by a factor of scale.
// e.g., expand(0b1111ull, 3) == 0b001001001001
uint64_t expand(uint64_t input, uint32_t scale) {
    assert(scale < 64);
    uint64_t result = 0;
    for(uint32_t i = 0; i < 64; i++){
        uint64_t bit = (input >> i) & 1ull;
        result |= bit << (i * scale);
    }
    return result;  // replace this with your impl!
}

int main() {
    assert(expand(0b1111ull, 3) == 0b001001001001);
    assert(expand(0b0101,2) == 0b00010001);
    return 0;
}
