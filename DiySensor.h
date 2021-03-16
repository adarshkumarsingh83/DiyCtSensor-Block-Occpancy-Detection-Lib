/*
   Adarsh Model Trains
   Developed by Adarsh kumar
   Support adarshkumarsingh83@gmail.com
*/

#ifndef DiySensor_h
#define DiySensor_h

#include "CtSensor.h"

class DiySensor {

  private:
    int _totalSensor;
    CtSensor * _ctSensorBlocks;

  public:
    DiySensor() {
    }

    void initBlockSensors(int totalSensor);
    void setBlockSensorPins(int blockNo, uint8_t ctSensorPin);
    void setDiyOccupancyThreshhold(int blockNo, int occupancyThreshold);
    void setDiyOccupancySamples(int blockNo, int unOccupancySamples);
    bool isSensorBlockOccupied(int blockNo);

    ~DiySensor() {
      for (int i = 0; i < _totalSensor; i++) {
        delete &_ctSensorBlocks[i];
      }
      delete[] _ctSensorBlocks;
    }
};
#endif