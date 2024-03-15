// Simulating particle detection using classes and objects
// Author: Leo Feasby
// Date: 15/03/2024

#include "Lepton.h"
#include "Detector.h"
#include <vector>
#include <iostream>

int main() 
{
  std::cout << "Program started: Simulating particle detection using classes and objects.\n";
  // Creating leptons
  std::cout << "Creating leptons...\n";
  Lepton electron("electron", 0.511, -1, 10.2, 3, 2, 1); // mass in MeV, charge, and four-momentum components
  Lepton muon1("muon", 105.7, -1, 502.3, 20, 15, 5);
  Lepton antielectron("electron", 0.511, 1, 12.4, 4, 1, 3);
  Lepton antimuon("muon", 105.7, 1, 480.5, 25, 10, 8);
  Lepton electron2("electron", 0.511, -1, 8.9, 2, 3, 2); // Second electron
  Lepton muon2("muon", 105.7, -1, 510.2, 18, 12, 6); // Second muon
  Lepton muon3("muon", 105.7, -1, 495.8, 22, 14, 7); // Third muon
  Lepton muon4("muon", 105.7, -1, 520.1, 19, 11, 9); // Fourth muon
  std::cout << "Leptons created successfully.\n";

  // Storing them in a vector
  std::vector<Lepton> particles = {electron, muon1, antielectron, antimuon, electron2, muon2, muon3, muon4};
  std::cout << "Stored leptons in a vector.\n";

  // Summing the four-momenta of the two electrons and outputting the result
  Lepton summed_electrons = electron + electron2;
  std::cout << "Summed the four-momenta of the two electrons. Resulting four-momentum: ["
            << summed_electrons.get_e() << ", " 
            << summed_electrons.get_px() << ", " 
            << summed_electrons.get_py() << ", " 
            << summed_electrons.get_pz() << "]\n";
  
  // Calculating the dot product of the first two muons
  double dot_product_result = muon1.dotProduct(muon2);
  std::cout << "Calculated the dot product of the first two muons: " << dot_product_result << "\n";

  // Demonstrating assignment operator with an electron
  Lepton new_electron;
  new_electron = electron; // Assignment operator is used
  std::cout << "Assignment operator used successfully for newElectron.\n";

  // Demonstrating copy constructor with a muon
  Lepton new_muon(muon1); // Copy constructor is used
  std::cout << "Copy constructor used successfully for newMuon.\n";

  // Moving the antielectron into another antielectron using the move constructor
  Lepton moved_antielectron(std::move(antielectron));
  std::cout << "Moved antielectron into another antielectron using the move constructor.\n";

  // Assigning the antimuon to another antimuon using the move assignment
  Lepton new_antimuon; // Create a new Lepton object
  new_antimuon = std::move(antimuon); // Use move assignment
  std::cout << "Assigned antimuon to another antimuon using the move assignment operator.\n";

  // Printing information about each particle
  std::cout << "Printing information about each particle...\n";
  for (const auto& particle : particles) 
  {
    particle.print_info();
  }

  // Creating detectors
  std::cout << "Creating detectors...\n";
  Detector tracker("tracker");
  Detector calorimeter("calorimeter");
  Detector muon_chamber("muon chamber");
  std::cout << "Detectors created successfully.\n";

  // Demonstrating detector functionality
  std::vector<Detector> detectors = {tracker, calorimeter, muon_chamber};
  std::cout << "Initializing detectors...\n";

  for (auto& detector : detectors) 
  {
    int total_detected = 0; // Initialize total detected particles for each detector
    std::cout << "Turning on " << detector.get_detector_type() << ".\n";
    detector.turn_on();
    std::cout << detector.get_detector_type() << " is now on. Printing detector info:\n";
    detector.print_info();
    std::cout << "Detecting particles with " << detector.get_detector_type() << ":\n";
    for (const auto& particle : particles) 
    {
      std::cout << "Detecting " << particle.get_particle_type() << ".\n";
      int detection_result = detector.detect_particle(particle);
      if (detection_result == 1) 
      {
        total_detected++; // Increment total detected particles if detection is successful
        std::cout << particle.get_particle_type() << " detected successfully by " << detector.get_detector_type() << ".\n";
      } 
      else 
      {
        std::cout << particle.get_particle_type() << " was not detected by " << detector.get_detector_type() << ".\n";
      }
    }
    std::cout << "Total particles detected by " << detector.get_detector_type() << ": " << total_detected << "\n"; // Print total detected particles
    std::cout << "Turning off " << detector.get_detector_type() << ".\n";
    detector.turn_off();
    std::cout << detector.get_detector_type() << " is now off.\n";
  }
  std::cout << "All detectors have been turned off. Exiting program.\n";
  return 0;
}

