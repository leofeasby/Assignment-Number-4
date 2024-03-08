// Description: This file defines the Lepton class, which models particles with attributes like type, mass, charge, and velocity.
// Author: Leo Feasby
// Date: 08/03/2024

#include "Lepton.h"
#include <iostream>

const double Lepton::light_speed = 2.99792458e8; // Speed of light in m/s

Lepton::Lepton()
  : particle_type("electron"), rest_mass(0.511), charge(-1), velocity(0), beta(0) 
{}

Lepton::Lepton(const std::string& type, double mass, int charge, double velocity)
  : particle_type(type), rest_mass(mass), charge(charge), velocity(velocity) 
{
  this->beta = velocity / Lepton::light_speed;
}

Lepton::~Lepton() {}

void Lepton::setParticleType(const std::string& type) 
{
  this->particle_type = type;
}

void Lepton::setRestMass(double mass) 
{
  if (mass > 0) 
  {
    this->rest_mass = mass;
  } 
  else 
  {
    std::cout << "Invalid mass. It must be positive.\n";
  }
}

void Lepton::setCharge(int charge) 
{
  this->charge = charge;
}

void Lepton::setVelocity(double velocity) 
{
  double potentialBeta = velocity / Lepton::light_speed;
  if (velocity >= 0 && potentialBeta <= 1) 
  {
    this->velocity = velocity;
    this->beta = potentialBeta;
  } 
  else 
  {
    std::cout << "Invalid velocity. It must be between 0 and the speed of light, ensuring beta does not exceed 1.\n";
  }
}

std::string Lepton::getParticleType() const 
{
  return this->particle_type;
}

double Lepton::getRestMass() const 
{
  return this->rest_mass;
}

int Lepton::getCharge() const 
{
  return this->charge;
}

double Lepton::getVelocity() const 
{
  return this->velocity;
}

double Lepton::getBeta() const 
{
  return this->beta;
}

void Lepton::printInfo() const 
{
  std::cout << "Particle Type: " << this->particle_type
            << "\nRest Mass (MeV): " << this->rest_mass
            << "\nCharge: " << this->charge
            << "\nVelocity (m/s): " << this->velocity
            << "\nBeta: " << this->beta << '\n';
}

