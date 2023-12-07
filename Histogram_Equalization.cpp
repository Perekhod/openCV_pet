#include <opencv2/opencv.hpp>

int main() 
{
    // ��������� ���������� � ������ �����
    cv::VideoCapture cap("C:/Users/user/Desktop/�������������/test2.mov");

    // ���������, ������ �� ����������
    if (!cap.isOpened()) 
    {
        std::cerr << "������ �������� ���������� ��� ������!\n";
        return -1;
    }

    // ������� ���� ��� ������ �����������
    cv::namedWindow("Histogram Equalization", cv::WINDOW_NORMAL);

    while (true) 
    {
        cv::Mat frame;
        // ��������� ���� �� �����������
        cap >> frame;

        // ���������, ��������� �� ����� �����
        if (frame.empty()) 
        {
            std::cout << "��������� ����� �����.\n";
            break;
        }

        // ����������� ����������� � ������� ������, ���� ��� ��� �� � ����� �������
        if (frame.channels() > 1) 
        {
            cv::cvtColor(frame, frame, cv::COLOR_BGR2GRAY);
        }

        // ��������� ������������� ������������
        cv::Mat equalized_frame;
        cv::equalizeHist(frame, equalized_frame);

        // ���������� ������������ ����
        cv::imshow("Histogram Equalization", equalized_frame);

        // ���� ������� ������� 'q' ��� ������
        if (cv::waitKey(30) == 'q') 
        {
            break;
        }
    }

    // ����������� �������
    cap.release();
    cv::destroyAllWindows();

    return 0;
}