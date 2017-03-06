#include "fisherfacerecognizer.h"

#include <opencv/cvaux.h>
#include <opencv/cv.hpp>
#include <limits>


namespace cognition
{

    FisherFaceRecognizer::FisherFaceRecognizer(void)
            :images(0),
             numTrainedImages(0),
             numEigenvalues(0),
             eigenVectors(0),
             averageImage(0),
             eigenvalues(0),
             projectedTrainImage(0)
    {
    }


    /*FisherFaceRecognizer::~FisherFaceRecognizer(void)
    {
        return;
    }*/


    bool FisherFaceRecognizer::addTrainingImage(const std::string &filename, const std::string &name)
    {
        trainingImages[filename] = name;
        return true;
    }

    void FisherFaceRecognizer::freeMemory(int fromIndex)
    {
        for(; fromIndex >= 0; fromIndex--)
            cvFree(&images[fromIndex]);

        numTrainedImages = 0;

        cvFree(images);
    }

    bool FisherFaceRecognizer::train()
    {

        isTrained = true;

        return isTrained;
    }


    bool FisherFaceRecognizer::loadTrainingImages()
    {

        return true;
    }

    void FisherFaceRecognizer::doPCA()
    {

    }

    std::string FisherFaceRecognizer::recognize(cv::Mat &face)
    {

        return recognitionDescriptor[0].second;
    }

    int FisherFaceRecognizer::findNearestNeighbor(float *projectedTestImage)
    {
        //set the least distance to the maximum double value
        double leastDistanceSquare = std::numeric_limits<double>::max();

        //the index of the nearest element
        int nearestImage = 0;

        //calculate distance between each training image and the projected test face
        for(int current = 0; current < numTrainedImages; current++)
        {
            double distanceSquare = 0;

            for(int eigen = 0; eigen < numEigenvalues; eigen++)
            {
                //calculate the distance in for the current eigen
                float distance = projectedTestImage[eigen] -
                                 projectedTrainImage->data.fl[current * numEigenvalues + eigen];

                //square the distance and add it to the total value
                distanceSquare += distance * distance;
            }

            if(distanceSquare < leastDistanceSquare)
            {
                leastDistanceSquare = distanceSquare;
                nearestImage = current;
            }
        }

        return nearestImage;
    }
}