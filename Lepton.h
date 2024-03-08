// Description: Defines the Lepton class for modeling particles with attributes like type, mass, charge, and velocity.
// Author: Leo Feasby
// Date: 08/03/2024

#ifndef LEPTON_H
#define LEPTON_H

#include <string>
#include <iostream>

class Lepton 
{
private:
  std::string particle_type; // "electron" or "muon"
  double rest_mass; // in MeV
  int charge; // +1 for particles, -1 for antiparticles
  double velocity; // in m/s, 0 to the speed of light
  double beta; // velocity/speed of light, in [0, 1]

public:
  Lepton(); // Default constructor
  Lepton(const std::string& type, double mass, int charge, double velocity); // Parameterized constructor
  ~Lepton(); // Destructor

  // Setters
  void setParticleType(const std::string& type);
  void setRestMass(double mass);
  void setCharge(int charge);
  void setVelocity(double velocity);

  // Getters
  std::string getParticleType() const;
  double getRestMass() const;
  int getCharge() const;
  double getVelocity() const;
  double getBeta() const;

  // Other member functions
  void printInfo() const;

  // Constants
  static const double light_speed;
};

#endif 
