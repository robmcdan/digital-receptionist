#ifndef COGNITION_RECOGNIZER_EIGENFACERECOGNIZER_H
#define COGNITION_RECOGNIZER_EIGENFACERECOGNIZER_H

//Implementation based on http://www.cognotics.com/opencv/servo_2007_series/part_5/index.html
//by Robin Hewitt, many thanks for his great articles

//suppress warinings generated by the cvaux library that this class uses
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS

#include <map>
#include <opencv2/core/core.hpp>
#include "../recognizer.h"
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/highgui/highgui.hpp>

namespace cognition
{

    class FisherFaceRecognizer : public Recognizer
    {
    public:
        FisherFaceRecognizer(void);
        //virtual ~FisherFaceRecognizer()(void);

        bool addTrainingImage(const std::string &filename, const std::string &name);

        bool train();
        std::string recognize(cv::Mat &face);
        std::size_t numTrainingImages(){ return trainingImages.size(); }

    protected:

        bool loadTrainingImages();
        //principal component analysis
        void doPCA();
        void freeMemory(int fromIndex = -1);
        int findNearestNeighbor(float *projectedTestImage);

        typedef std::map<std::string, std::string> StringMap;

        //filename - > name
        StringMap trainingImages;

        //index - > filename,name (since trainingImages can change)
        typedef std::pair<std::string, std::string> StringPair;
        std::vector<StringPair> recognitionDescriptor;

        IplImage **images;			//array of trained images
        int numTrainedImages;		//number of training images used
        int numEigenvalues;			//number of eigenvalues
        IplImage **eigenVectors;	//array of eigenvectors
        IplImage *averageImage;		//the average image of the training set
        CvMat *eigenvalues;			//eigenvalues matrix
        CvMat *projectedTrainImage;	//projected image matrix
    };

}
#endif //COGNITION_RECOGNIZER_EIGENFACERECOGNIZER_H
