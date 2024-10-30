#include "patcher.h"

#include <cassert>
#include <fstream>
#include <iterator>
#include <stdexcept>
#include <vector>

using namespace std;

int main() {
    ifstream ifs{"../../assets/main.fatbin", ifstream::binary};
    vector<unsigned char> buf{istreambuf_iterator<char>{ifs}, {}};
    if (buf.size() < 16) {
        throw runtime_error{"invalid fatbin"};
    }
    auto patched = patch_fatbin(buf.data());
    if (patched == nullptr) {
        throw runtime_error{"patcher failed"};
    }
    ofstream ofs{"/tmp/patched.fatbin", ofstream::binary | ofstream::out};
    ofs.write(reinterpret_cast<char *>(patched->data()), patched->size());
}
