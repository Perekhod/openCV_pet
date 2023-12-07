#include <opencv2/opencv.hpp>

int main()
{
    // Открываем изображение
    cv::Mat image = cv::imread("C:/Users/user/Desktop/Собеседование/luggage.jpg");

    // Проверяем, удалось ли загрузить изображение
    if (image.empty())
    {
        std::cerr << "Ошибка загрузки изображения!\n";
        return -1;
    }

    // Применяем пороговую сегментацию
    int threshold_value = 125; // Значение порога (можете изменить)
    cv::Mat binary_image;
    cv::threshold(image, binary_image, threshold_value, 255, cv::THRESH_BINARY);

    // Отображаем исходное изображение и результат пороговой сегментации
    cv::imshow("Original Image", image);
    cv::imshow("Thresholded Image", binary_image);

    cv::waitKey(0);

    return 0;
}
