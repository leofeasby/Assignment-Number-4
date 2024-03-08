// Description: This program demonstrates the use of classes and objects to simulate particle detection.
// Author: Leo Feasby
// Date: 08/03/2024

#include "Lepton.h"
#include "Detector.h"
#include <vector>
#include <iostream>

int main() 
{
  // Create some leptons
  Lepton electron("electron", 0.511, -1, 2.0e7); // mass in MeV, charge, and velocity
  Lepton muon1("muon", 105.7, -1, 3.0e7); // mass in MeV, charge, and velocity
  Lepton antielectron("electron", 0.511, 1, 2.5e7);
  Lepton antimuon("muon", 105.7, 1, 1.0e7);
  Lepton electron2("electron", 0.511, -1, 2.1e7); // Second electron
  Lepton muon2("muon", 105.7, -1, 3.1e7); // Second muon
  Lepton muon3("muon", 105.7, -1, 3.2e7); // Third muon
  Lepton muon4("muon", 105.7, -1, 2.4e7); // Fourth muon

  // Store them in a vector
  std::vector<Lepton> particles = {electron, muon1, antielectron, antimuon, electron2, muon2, muon3, muon4};

  // Print information about each particle
  for (const auto& particle : particles) 
  {
    particle.printInfo();
  }

  // Create detectors
  Detector tracker("tracker");
  Detector calorimeter("calorimeter");
  Detector muonChamber("muon chamber");

  // Demonstrate detector functionality
  std::vector<Detector> detectors = {tracker, calorimeter, muonChamber};
  std::cout << "Initializing detectors...\n";

  for (auto& detector : detectors) 
  {
    int totalDetected = 0; // Initialize total detected particles for each detector
    std::cout << "Turning on " << detector.getDetectorType() << ".\n";
    detector.turnOn();
    std::cout << detector.getDetectorType() << " is now on. Printing detector info:\n";
    detector.printInfo();
    std::cout << "Detecting particles with " << detector.getDetectorType() << ":\n";
    for (const auto& particle : particles) 
    {
      std::cout << "Detecting " << particle.getParticleType() << ".\n";
      int detectionResult = detector.detectParticle(particle);
      if (detectionResult == 1) 
      {
        totalDetected++; // Increment total detected particles if detection is successful
      } 
      else 
      {
        std::cout << particle.getParticleType() << " was not detected by " << detector.getDetectorType() << ".\n";
      }
    }
    std::cout << "Total particles detected by " << detector.getDetectorType() << ": " << totalDetected << "\n"; // Print total detected particles
    std::cout << "Turning off " << detector.getDetectorType() << ".\n";
    detector.turnOff();
    std::cout << detector.getDetectorType() << " is now off.\n";
  }
  std::cout << "All detectors have been turned off. Exiting program.\n";
  return 0;
}

