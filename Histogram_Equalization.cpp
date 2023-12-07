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
    cv::namedWindow("Histogram Equalization", cv::WINDOW_NORMAL);

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

        // Преобразуем изображение в оттенки серого, если оно еще не в таком формате
        if (frame.channels() > 1) 
        {
            cv::cvtColor(frame, frame, cv::COLOR_BGR2GRAY);
        }

        // Применяем гистограммное выравнивание
        cv::Mat equalized_frame;
        cv::equalizeHist(frame, equalized_frame);

        // Отображаем обработанный кадр
        cv::imshow("Histogram Equalization", equalized_frame);

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