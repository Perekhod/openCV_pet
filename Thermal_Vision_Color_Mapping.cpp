#include <opencv2/opencv.hpp>

int main() 
{
    // Открываем видеопоток с файлом видео
    cv::VideoCapture cap("C:/Users/user/Desktop/Собеседование/test2.mov");

    // Проверяем, открыт ли видеопоток
    if (!cap.isOpened()) 
    {
        std::cerr << "Ошибка открытия видеофайла или потока!\n";
        return -1;
    }

    // Создаем окно для вывода изображения
    cv::namedWindow("Thermal Vision", cv::WINDOW_NORMAL);

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

        // Применяем цветовой маппинг COLORMAP_JET
        cv::Mat thermal_mapped;
        cv::applyColorMap(frame, thermal_mapped, cv::COLORMAP_JET);

        // Отображаем обработанный кадр
        cv::imshow("Thermal Vision", thermal_mapped);

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