#pragma once

#include <cstddef>
#include <vector>

namespace VIVES {

  class BitmapGenerator {

    public:
      static void generate(unsigned char* image, size_t height, size_t width, const char* imageFileName);

    private:
      static std::vector<unsigned char> create_file_header(size_t height, size_t stride);
      static std::vector<unsigned char> create_info_header(size_t height, size_t width);

    private:
      const static size_t BYTES_PER_PIXEL = 3;
      const static size_t FILE_HEADER_SIZE = 14;
      const static size_t INFO_HEADER_SIZE = 40;

  };

};