// C++03 zlib-compatible save compression helpers shared by the plugin/tests.
#ifndef TOKELACOOP_SAVECOMPRESS_H
#define TOKELACOOP_SAVECOMPRESS_H
#include <vector>
#include "../../third_party/miniz/miniz.h"
namespace coop {
namespace savecompress {
inline bool compress(const unsigned char* src, unsigned long size,
                    std::vector<unsigned char>* out) {
    unsigned char empty = 0;
    if (!out) return false;
    mz_ulong n = mz_compressBound((mz_ulong)size);
    out->resize((size_t)n);
    if (mz_compress2(out->empty() ? 0 : &(*out)[0], &n, src ? src : &empty, (mz_ulong)size, 6) != MZ_OK) {
        out->clear(); return false;
    }
    out->resize((size_t)n); return true;
}
inline bool decompress(const unsigned char* src, unsigned long size,
                       unsigned long rawSize, std::vector<unsigned char>* out) {
    unsigned char empty = 0;
    if (!out || rawSize > 512UL * 1024UL * 1024UL || size > 512UL * 1024UL * 1024UL) return false;
    out->resize((size_t)rawSize);
    mz_ulong n = (mz_ulong)rawSize;
    int r = mz_uncompress(out->empty() ? 0 : &(*out)[0], &n, src ? src : &empty, (mz_ulong)size);
    if (r != MZ_OK || n != (mz_ulong)rawSize) { out->clear(); return false; }
    return true;
}
}
}
#endif
