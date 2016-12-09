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

#include "IntegratedBC.h"

#ifndef CRUDCLADNEUMANNBCMULTIAPP_H
#define CRUDCLADNEUMANNBCMULTIAPP_H

//Forward Declarations
class CRUDCladNeumannBCMultiApp;

template<>
InputParameters validParams<CRUDCladNeumannBCMultiApp>();

/**
 * Implements a simple constant Neumann BC where grad(u)=alpha * v on the boundary.
 * Uses the term produced from integrating the diffusion operator by parts.
 */
class CRUDCladNeumannBCMultiApp : public IntegratedBC
{
public:

  /**
   * Factory constructor, takes parameters so that all derived classes can be built using the same
   * constructor.
   */
  CRUDCladNeumannBCMultiApp(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual();

private:

  const PostprocessorValue & _q_dot_multiapp;
};

#endif //CRUDCLADNEUMANNBCMULTIAPP_H
