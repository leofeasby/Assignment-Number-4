// Description: Defines the Lepton class for modeling particles with attributes like type, mass, charge, and four-momentum.
// Author: Leo Feasby
// Date: 15/03/2024

#ifndef LEPTON_H
#define LEPTON_H

#include <string>
#include <iostream>
#include <vector>

class Lepton 
{
private:
  std::string particle_type; // "electron" or "muon"
  double rest_mass;
  int charge; // +1 for particles, -1 for antiparticles
  std::vector<double>* four_momentum; // Dynamically allocated four-momentum vector

public:
  Lepton(); // Default constructor
  Lepton(const std::string& type, double mass, int charge, double energy, double px, double py, double pz); // Parameterized constructor
  Lepton(const Lepton& other); // Copy constructor
  Lepton& operator=(const Lepton& other); // Copy assignment operator
  Lepton(Lepton&& other) noexcept; // Move constructor
  Lepton& operator=(Lepton&& other) noexcept; // Move assignment operator
  ~Lepton(); // Destructor

  // Setters
  void set_particle_type(const std::string& type);
  void set_rest_mass(double mass);
  void set_charge(int charge);
  void set_four_momentum(double energy, double px, double py, double pz);

  // Getters
  std::string get_particle_type() const;
  double get_rest_mass() const;
  int get_charge() const;
  double get_e() const;
  double get_px() const;
  double get_py() const;
  double get_pz() const;

  // Other member functions
  void print_info() const;
  Lepton operator+(const Lepton& other) const; // Overloaded "+" operator for summing four-vectors
  double dotProduct(const Lepton& other) const; // Function for the dot product of two particle four-vectors

  // Constants
  static const double light_speed;
};

#endif 