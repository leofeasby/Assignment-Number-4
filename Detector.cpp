// Description: This file defines the Detector class, which models detectors for particle detection in physics experiments.
// Author: Leo Feasby
// Date: 08/03/2024

#include "Detector.h"
#include <iostream>

Detector::Detector() 
  : detector_type("tracker"), status(false) 
{}

Detector::Detector(const std::string& type) 
  : status(false) 
{
  // Validate the detector type before setting it
  if (type == "tracker" || type == "calorimeter" || type == "muon chamber") 
  {
    this->detector_type = type;
  } 
  else 
  {
    std::cerr << "Invalid detector type. Setting to default 'tracker'.\n";
    this->detector_type = "tracker"; // Default to tracker if invalid
  }
}

Detector::~Detector() {}

void Detector::setDetectorType(const std::string& type) 
{
  // Similar validation as in the constructor
  if (type == "tracker" || type == "calorimeter" || type == "muon chamber") 
  {
    this->detector_type = type;
  } 
  else 
  {
    std::cerr << "Invalid detector type. No change made.\n";
  }
}

void Detector::setStatus(bool status) 
{
  this->status = status;
}

std::string Detector::getDetectorType() const 
{
  return this->detector_type;
}

bool Detector::getStatus() const 
{
  return this->status;
}

void Detector::turnOn() 
{
  this->status = true;
}

void Detector::turnOff() 
{
  this->status = false;
}

int Detector::detectParticle(const Lepton& particle) const 
{
  if (!status) 
  {
    std::cout << "Detector is off.\n";
    return 0;
  }

  if ((detector_type == "tracker" && (particle.getParticleType() == "electron" || particle.getParticleType() == "muon")) ||
      (detector_type == "calorimeter" && particle.getParticleType() == "electron") ||
      (detector_type == "muon chamber" && particle.getParticleType() == "muon")) 
  {
    std::cout << particle.getParticleType() << (particle.getCharge() == 1 ? " (antiparticle)" : "") << " was detected\n";
    return 1;
  }

  return 0;
}

void Detector::printInfo() const 
{
  std::cout << "Detector Type: " << this->detector_type
            << "\nStatus: " << (this->status ? "On" : "Off") << '\n';
}

