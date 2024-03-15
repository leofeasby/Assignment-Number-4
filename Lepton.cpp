// Description: Models particles with attributes like type, mass, charge, and four-momentum.
// Author: Leo Feasby
// Date: 15/03/2024
#include "Lepton.h"
#include <iostream>
#include <vector>

// Speed of light
const double Lepton::light_speed = 2.99792458e8;

// Default constructor initializing default values for a Lepton object
Lepton::Lepton()
  : particle_type("electron"), rest_mass(0.511), charge(-1), four_momentum(new std::vector<double>(4, 0.0))
{
  std::cout << "Default Lepton constructor called. Initialized with type: " << particle_type << ", mass: " << rest_mass << ", charge: " << charge << ", and four_momentum: [0, 0, 0, 0]" << std::endl;
}

// Parameterized constructor for custom initialization of a Lepton object
Lepton::Lepton(const std::string& type, double mass, int charge, double energy, double px, double py, double pz)
  : particle_type(type), rest_mass(mass), charge(charge)
{
  // Initializing four_momentum with provided parameters
  four_momentum = new std::vector<double>{energy, px, py, pz};
  std::cout << "Parameterized Lepton constructor called. Initialized with type: " << particle_type << ", mass: " << rest_mass << ", charge: " << charge << ", and four_momentum: [" << energy << ", " << px << ", " << py << ", " << pz << "]" << std::endl;
}

// Copy constructor for creating a deep copy of another Lepton object
Lepton::Lepton(const Lepton& other)
  : particle_type(other.particle_type), rest_mass(other.rest_mass), charge(other.charge), four_momentum(new std::vector<double>(*other.four_momentum))
{
  std::cout << "Calling Copy Constructor" << std::endl;
}

// Copy assignment operator for assigning one Lepton object to another
Lepton& Lepton::operator=(const Lepton& other)
{
  // Logging the use of the assignment operator
  std::cout << "Calling Assignment Operator" << std::endl;
  if(this != &other) 
  {
    particle_type = other.particle_type;
    rest_mass = other.rest_mass;
    charge = other.charge;
    delete four_momentum; // Deleting existing four_momentum before assignment
    four_momentum = new std::vector<double>(*other.four_momentum);
  }
  return *this;
}

// Move constructor for transferring ownership of resources from one Lepton object to another
Lepton::Lepton(Lepton&& other) noexcept
  : particle_type(std::move(other.particle_type)), rest_mass(other.rest_mass), charge(other.charge), four_momentum(other.four_momentum)
{
  // Logging the use of the move constructor
  std::cout << "Calling Move Constructor" << std::endl;
  other.four_momentum = nullptr; // Ensuring the moved-from object is left in a valid state
}

// Move assignment operator for transferring ownership of resources between Lepton objects
Lepton& Lepton::operator=(Lepton&& other) noexcept
{
  std::cout << "Calling Move Assignment Operator" << std::endl;
  if(this != &other) 
  {
    delete four_momentum; // Deleting existing four_momentum before assignment
    particle_type = std::move(other.particle_type);
    rest_mass = other.rest_mass;
    charge = other.charge;
    four_momentum = other.four_momentum;
    other.four_momentum = nullptr; // Ensuring the moved-from object is left in a valid state
  }
  return *this;
}

// Destructor for cleaning up dynamically allocated memory
Lepton::~Lepton() 
{
  std::cout << "Calling Destructor" << std::endl;
  delete four_momentum;
}

// Setter methods for updating Lepton object attributes
void Lepton::set_particle_type(const std::string& type) 
{
  particle_type = type;
  std::cout << "Particle type set to: " << type << std::endl;
}

void Lepton::set_rest_mass(double mass) 
{
  if(mass > 0) 
  {
    rest_mass = mass;
    std::cout << "Rest mass set to: " << mass << std::endl;
  } 
  else 
  {
    std::cout << "Invalid mass. It must be positive.\n";
  }
}

void Lepton::set_charge(int charge) 
{
  this->charge = charge;
  std::cout << "Charge set to: " << charge << std::endl;
}

void Lepton::set_four_momentum(double energy, double px, double py, double pz) 
{
  if(energy >= 0) 
  {
    (*four_momentum)[0] = energy;
    (*four_momentum)[1] = px;
    (*four_momentum)[2] = py;
    (*four_momentum)[3] = pz;
    std::cout << "Four_momentum set to: [" << energy << ", " << px << ", " << py << ", " << pz << "]" << std::endl;
  } 
  else 
  {
    std::cout << "Invalid energy. It must be non-negative.\n";
  }
}

// Getter methods for accessing Lepton object attributes
double Lepton::get_e() const 
{
  if(four_momentum != nullptr) 
  {
    std::cout << "Getting energy: " << (*four_momentum)[0] << std::endl;
    return (*four_momentum)[0];
  } 
  else 
  {
    std::cerr << "four_momentum is not initialized.\n";
    return 0.0;
  }
}

double Lepton::get_px() const 
{ 
  std::cout << "Getting Px: " << (*four_momentum)[1] << std::endl;
  return (*four_momentum)[1]; 
}

double Lepton::get_py() const 
{ 
  std::cout << "Getting Py: " << (*four_momentum)[2] << std::endl;
  return (*four_momentum)[2]; 
}

double Lepton::get_pz() const 
{ 
  std::cout << "Getting Pz: " << (*four_momentum)[3] << std::endl;
  return (*four_momentum)[3]; 
}

std::string Lepton::get_particle_type() const 
{
  std::cout << "Getting particle type: " << particle_type << std::endl;
  return particle_type;
}

double Lepton::get_rest_mass() const 
{
  std::cout << "Getting rest mass: " << rest_mass << std::endl;
  return rest_mass;
}

int Lepton::get_charge() const 
{
  std::cout << "Getting charge: " << charge << std::endl;
  return charge;
}

// Method for printing detailed information about the Lepton object
void Lepton::print_info() const 
{
  std::cout << "Particle Type: " << particle_type
            << "\nRest Mass (MeV): " << rest_mass
            << "\nCharge: " << charge
            << "\nEnergy (MeV): " << get_e()
            << "\nMomentum px (MeV/c): " << get_px()
            << "\nMomentum py (MeV/c): " << get_py()
            << "\nMomentum pz (MeV/c): " << get_pz() << '\n';
}

// Overloaded "+" operator for summing the four-momenta of two Lepton objects
Lepton Lepton::operator+(const Lepton& other) const 
{
  std::vector<double> summed_four_momentum(4);
  for(size_t i = 0; i < 4; ++i) 
  {
    summed_four_momentum[i] = (*this->four_momentum)[i] + (*other.four_momentum)[i];
  }
  return Lepton(this->particle_type, this->rest_mass, this->charge, summed_four_momentum[0], summed_four_momentum[1], summed_four_momentum[2], summed_four_momentum[3]);
}

// Method for calculating the dot product of the four-momenta of two Lepton objects
double Lepton::dotProduct(const Lepton& other) const 
{
    return + (*this->four_momentum)[0] * (*other.four_momentum)[0] // Energy component
           + (*this->four_momentum)[1] * (*other.four_momentum)[1] // X component
           + (*this->four_momentum)[2] * (*other.four_momentum)[2] // Y component
           + (*this->four_momentum)[3] * (*other.four_momentum)[3]; // Z component
}

