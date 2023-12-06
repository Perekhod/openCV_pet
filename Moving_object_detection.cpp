#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/video/background_segm.hpp>

int main()
{
    // Использование веб-камеры с индексом 0
    cv::VideoCapture cap(0);

    // Проверка на успешное открытие камеры
    if (!cap.isOpened())
    {
        std::cerr << "Error opening camera.\n";
        return -1;
    }

    cv::namedWindow("Motion Detection", cv::WINDOW_GUI_EXPANDED);

    cv::Mat frame;
    cv::Mat fgMask;  // Маска переднего плана для выделения движущихся объектов

    // Инициализация алгоритма выделения фона (можно выбрать другие алгоритмы)
    cv::Ptr<cv::BackgroundSubtractor> pMOG2 = cv::createBackgroundSubtractorMOG2();

    while (true)
    {
        cap >> frame;  // Захват кадра

        if (frame.empty())
        {
            std::cerr << "End of video stream.\n";
            break;
        }

        // Применение алгоритма выделения фона
        pMOG2->apply(frame, fgMask);

        // Применение морфологических операций для удаления шумов и улучшения результатов
        cv::morphologyEx(fgMask, fgMask, cv::MORPH_OPEN, cv::Mat());
        cv::morphologyEx(fgMask, fgMask, cv::MORPH_CLOSE, cv::Mat());

        // Нахождение контуров движущихся объектов
        std::vector<std::vector<cv::Point>> contours;
        cv::findContours(fgMask, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

        // Отрисовка контуров на исходном кадре
        cv::drawContours(frame, contours, -1, cv::Scalar(0, 255, 0), 2);

        // Отображение результатов
        cv::imshow("Motion Detection", frame);

        // Выход из цикла при нажатии клавиши 'q'
        if (cv::waitKey(30) == 'q')
        {
            break;
        }
    }

    // Освобождение ресурсов
    cap.release();
    cv::destroyAllWindows();

    return 0;
}