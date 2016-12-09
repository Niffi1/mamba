/****************************************************************/
/*               DO NOT MODIFY THIS HEADER                      */
/* MOOSE - Multiphysics Object Oriented Simulation Environment  */
/*                                                              */
/*           (c) 2010 Battelle Energy Alliance, LLC             */
/*                   ALL RIGHTS RESERVED                        */
/*                                                              */
/*          Prepared by Battelle Energy Alliance, LLC           */
/*            Under Contract No. DE-AC07-05ID14517              */
/*            With the U. S. Department of Energy               */
/*                                                              */
/*            See COPYRIGHT for full restrictions               */
/****************************************************************/

#ifndef FLUIDVELOCITYAUX_H
#define FLUIDVELOCITYAUX_H

#include "AuxKernel.h"


//Forward Declarations
class FluidVelocityAux;

template<>
InputParameters validParams<FluidVelocityAux>();

/**
 * Coupled auxiliary value
 */
class FluidVelocityAux : public AuxKernel
{
public:

  /**
   * Factory constructor, takes parameters so that all derived classes can be built using the same
   * constructor.
   */
  FluidVelocityAux(const InputParameters & parameters);

protected:
  virtual Real computeValue();

  const MaterialProperty<Real> & _permeability;
  const MaterialProperty<Real> & _mu_h2o;
  const VariableValue & _porosity;
  const VariableGradient & _grad_P;

};

#endif //FLUIDVELOCITYAUX_H
