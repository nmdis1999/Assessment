#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <array>
#include <limits>

constexpr double ENTROPY_THRESHOLD = 7.5;

double compute_entropy(const std::vector<unsigned char>& data) {
    if (data.empty()) return 0.0;

    std::array<size_t, 256> frequency{};
    for (unsigned char byte : data) {
        ++frequency[byte];
    }

    double entropy = 0.0;
    const double data_size = static_cast<double>(data.size());

    for (size_t count : frequency) {
        if (count == 0) continue;
        double p = count / data_size;
        entropy -= p * std::log2(p);
    }

    return entropy;
}

bool is_likely_encrypted(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Error: Cannot open file '" << filename << "'.\n";
        return false;
    }
    std::vector<unsigned char> buffer(
        (std::istreambuf_iterator<char>(file)),
         std::istreambuf_iterator<char>());

    if (buffer.empty()) {
        std::cerr << "Warning: File is empty.\n";
        return false;
    }

    double entropy = compute_entropy(buffer);
    std::cout << "Computed entropy: " << entropy << " bits/byte\n";

    return entropy >= ENTROPY_THRESHOLD;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <filename>\n";
        return 1;
    }

    bool encrypted = is_likely_encrypted(argv[1]);
    std::cout << "File '" << argv[1] << "' is "
              << (encrypted ? "likely encrypted or compressed.\n"
                            : "not encrypted (likely plaintext).\n");

    return 0;
}
