#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    // Load the image
    std::string imagePath = "path_to_your_image.jpg"; // Replace with your image path
    cv::Mat image = cv::imread(imagePath, cv::IMREAD_COLOR);

    // Check if the image was loaded successfully
    if (image.empty()) {
        std::cerr << "Could not open or find the image" << std::endl;
        return -1;
    }

    // Get image dimensions
    int rows = image.rows;
    int cols = image.cols;
    int channels = image.channels();

    // Print image dimensions
    std::cout << "Image dimensions: " << rows << "x" << cols << "x" << channels << std::endl;

    // Convert image to array
    std::vector<std::vector<std::vector<uint8_t>>> imageArray(rows, std::vector<std::vector<uint8_t>>(cols, std::vector<uint8_t>(channels)));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            for (int k = 0; k < channels; ++k) {
                imageArray[i][j][k] = image.at<cv::Vec3b>(i, j)[k];
            }
        }
    }

    // Print the array values (for demonstration purposes, only print a small part)
    std::cout << "Array values:" << std::endl;
    for (int i = 0; i < std::min(5, rows); ++i) {
        for (int j = 0; j < std::min(5, cols); ++j) {
            std::cout << "(";
            for (int k = 0; k < channels; ++k) {
                std::cout << static_cast<int>(imageArray[i][j][k]);
                if (k < channels - 1) std::cout << ",";
            }
            std::cout << ") ";
        }
        std::cout << std::endl;
    }

    return 0;
}
