// Original Source: https://stackoverflow.com/questions/2654480/writing-bmp-image-in-pure-c-c-without-other-libraries
// Orientation BMP: https://stackoverflow.com/questions/49667464/orientation-of-a-bmp-file-upright-or-upside-down

#include "bitmap_generator.h"
#include <stdio.h>

namespace VIVES {

  void BitmapGenerator::generate(unsigned char* image, size_t height, size_t width, const char* imageFileName) {
    int widthInBytes = width * BYTES_PER_PIXEL;

    unsigned char padding[3] = {0, 0, 0};
    int paddingSize = (4 - (widthInBytes) % 4) % 4;

    int stride = (widthInBytes) + paddingSize;

    FILE* imageFile = fopen(imageFileName, "wb");

    std::vector<unsigned char> fileHeader = create_file_header(height, stride);
    fwrite(fileHeader.data(), 1, FILE_HEADER_SIZE, imageFile);

    std::vector<unsigned char> infoHeader = create_info_header(height, width);
    fwrite(infoHeader.data(), 1, INFO_HEADER_SIZE, imageFile);

    for (size_t i = 0; i < height; i++) {
      fwrite(image + (i*widthInBytes), BYTES_PER_PIXEL, width, imageFile);
      fwrite(padding, 1, paddingSize, imageFile);
    }

    fclose(imageFile);
  }

  std::vector<unsigned char> BitmapGenerator::create_file_header(size_t height, size_t stride) {

    std::vector<unsigned char> fileHeader;
    fileHeader.resize(FILE_HEADER_SIZE, 0);

    size_t fileSize = FILE_HEADER_SIZE + INFO_HEADER_SIZE + (stride * height);

    // 0,0,     /// signature
    // 0,0,0,0, /// image file size in bytes
    // 0,0,0,0, /// reserved
    // 0,0,0,0, /// start of pixel array

    fileHeader[ 0] = (unsigned char)('B');
    fileHeader[ 1] = (unsigned char)('M');
    fileHeader[ 2] = (unsigned char)(fileSize      );
    fileHeader[ 3] = (unsigned char)(fileSize >>  8);
    fileHeader[ 4] = (unsigned char)(fileSize >> 16);
    fileHeader[ 5] = (unsigned char)(fileSize >> 24);
    fileHeader[10] = (unsigned char)(FILE_HEADER_SIZE + INFO_HEADER_SIZE);

    return fileHeader;
  }

  std::vector<unsigned char> BitmapGenerator::create_info_header(size_t height, size_t width) {

    std::vector<unsigned char> infoHeader;
    infoHeader.resize(INFO_HEADER_SIZE, 0);

    // 0,0,0,0, /// header size
    // 0,0,0,0, /// image width
    // 0,0,0,0, /// image height
    // 0,0,     /// number of color planes
    // 0,0,     /// bits per pixel
    // 0,0,0,0, /// compression
    // 0,0,0,0, /// image size
    // 0,0,0,0, /// horizontal resolution
    // 0,0,0,0, /// vertical resolution
    // 0,0,0,0, /// colors in color table
    // 0,0,0,0, /// important color count

    infoHeader[ 0] = (unsigned char)(INFO_HEADER_SIZE);
    infoHeader[ 4] = (unsigned char)(width      );
    infoHeader[ 5] = (unsigned char)(width >>  8);
    infoHeader[ 6] = (unsigned char)(width >> 16);
    infoHeader[ 7] = (unsigned char)(width >> 24);
    infoHeader[ 8] = (unsigned char)(height      );
    infoHeader[ 9] = (unsigned char)(height >>  8);
    infoHeader[10] = (unsigned char)(height >> 16);
    infoHeader[11] = (unsigned char)(height >> 24);
    infoHeader[12] = (unsigned char)(1);
    infoHeader[14] = (unsigned char)(BYTES_PER_PIXEL*8);

    return infoHeader;
  }

};