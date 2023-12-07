#include <opencv2/opencv.hpp>

int main()
{
    // Открываем видеопоток с файлом видео
    cv::VideoCapture cap("C:/Users/user/Desktop/Собеседование/test3_720p.mp4");

    // Проверяем, открыт ли видеопоток
    if (!cap.isOpened())
    {
        std::cerr << "Ошибка открытия видеофайла или потока!\n";
        return -1;
    }

    // Создаем окно для вывода изображения
    cv::namedWindow("Noise Reduction", cv::WINDOW_NORMAL);

    while (true)
    {
        cv::Mat frame;
        // Считываем кадр из видеопотока
        cap >> frame;

        // Проверяем, достигнут ли конец видео
        if (frame.empty())
        {
            std::cout << "Достигнут конец видео.\n";
            break;
        }

        // Применяем blur фильтр для снижения шума
        cv::Mat denoised_frame;
        cv::blur(frame, denoised_frame, cv::Size(9, 9));

        // Отображаем обработанный кадр
        cv::imshow("Noise Reduction", denoised_frame);

        // Ждем нажатия клавиши 'q' для выхода
        if (cv::waitKey(30) == 'q')
        {
            break;
        }
    }

    // Освобождаем ресурсы
    cap.release();
    cv::destroyAllWindows();

    return 0;
}
