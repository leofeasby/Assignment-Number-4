// Description: Defines the Detector class for modeling detectors in physics experiments.
// Author: Leo Feasby
// Date: 08/03/2024

#ifndef DETECTOR_H
#define DETECTOR_H

#include "Lepton.h"
#include <string>

class Detector 
{
private:
  std::string detector_type; // "tracker", "calorimeter", or "muon chamber"
  bool status; // true for on, false for off

public:
  Detector(); // Default constructor
  Detector(const std::string& type); // Parameterized constructor
  ~Detector(); // Destructor

  // Setters and getters
  void setDetectorType(const std::string& type);
  void setStatus(bool status);
  std::string getDetectorType() const;
  bool getStatus() const;

  // Functionality
  void turnOn();
  void turnOff();
  int detectParticle(const Lepton& particle) const;

  // Utility
  void printInfo() const;
};

#endif 
