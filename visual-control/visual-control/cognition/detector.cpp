#include "detector.h"
#include "Controller.h"
#include <boost/thread/locks.hpp>
#include <algorithm>
#include "framecapture.h"
#include "Controller.h"

namespace cognition
{
	Detector::Detector(const std::string& name, FrameCapturePtr captureDevice)
		:name(name), autoNotify(true)
	{
		//this can be dangerous, if capture device is the only one that holds a shared_ptr
		//to this recognizer
		if(captureDevice != 0)
			captureDevice->addFrameReceiver(this);
	}

	Detector::~Detector(void)
	{
	}


	bool Detector::addController(ControllerPtr controller)
	{
		boost::lock_guard<boost::mutex>(this->controllersLock);
		return controllers.insert(controller).second;
	}

	void Detector::removeController(ControllerPtr controller)
	{
		boost::lock_guard<boost::mutex>(this->controllersLock);

		controllers.erase(controller);

		//for(ControllerSetItr i = controllers.begin(); i != controllers.end(); ++i)
		//{
		//	if((*i).get() == (*i).get())
		//	{
		//		controllers.erase(i);
		//		return;
		//	}
		//}
	}

	void Detector::notifyControllers()
	{
		boost::lock_guard<boost::mutex>(this->controllersLock);

		for(ControllerSetItr i = controllers.begin(); i != controllers.end(); ++i)
			(*i)->stateChanged(this);
	}

	void Detector::threadStart()
	{
		keepProcessing = true;

		while(keepProcessing)
		{
			processFrame();
			//maybe there should be a wait if there is no new frame loaded! 
			//check up condition variables to be less resource intensive!
			//boost should stop threads when interrupt is called and
			//the thread is waiting on a condition, so interrupting will still work
		}
	}

	void Detector::requestTreadStop()
	{
		keepProcessing = false;
	}

	Detector::RectVector Detector::getAreas() 
	{ 
		boost::lock_guard<boost::mutex>(this->areaLock);
		//the scope is not left until return statement is completed
		return areas;
	}

	//should usually be called only from the inside, by one 1 thread!
	bool Detector::setAreas(const Detector::RectVector &newAreas)
	{
		if( areas.size() == newAreas.size() &&
			std::equal(newAreas.begin(), newAreas.end(), areas.begin()))
		{
			//there is nothing new, don't update and notify!
			return false;
		}

		areaLock.lock();
		areas = newAreas;
		areaLock.unlock();

		//areas have changed and autoNotify is on, send update!
		if(autoNotify)
			notifyControllers();

		return true;
	}

	void Detector::receiveFrame(const cv::Mat &frame)
	{
		//locks on entry, destructor unlocks!
		boost::lock_guard<boost::mutex>(this->frameLoadLock);

		//no cloning required, getNextFrame handles that
		nextFrame = frame;
	}

	cv::Mat Detector::getMostRecentFrame()
	{
		boost::lock_guard<boost::mutex>(this->frameLoadLock);

		return nextFrame.clone();
	}
}
