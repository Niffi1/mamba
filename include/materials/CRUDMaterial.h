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

#ifndef CRUDMATERIAL_H
#define CRUDMATERIAL_H

#include "Material.h"

//Forward Declarations
class CRUDMaterial;

template<>
InputParameters validParams<CRUDMaterial>();

class CRUDMaterial : public Material
{
public:
  CRUDMaterial(const InputParameters &  parameters);

protected:
//  virtual void initQpStatefulProperties();
  virtual void computeQpProperties();

private:

  /**
   * Holds a value from the input file.
   */
  Real _dimensionality;
  Real _pore_size_min_baseline;
  Real _pore_size_avg_baseline;
  Real _pore_size_max_baseline;
  Real _r_inner;
  Real _r_outer;
  Real _q_dot_in;
  Real _h_convection;

  Real _mu_298K;
  Real _D_BO3_298K;
  Real _D_Li_298K;
  Real _D_H_298K;
  Real _D_OH_298K;
  Real _scaling_factor;
  Real _thickness;

  // Assumed constant thermal conductivities of solid phases
  Real _k_HBO2_baseline;
  Real _k_Li2B4O7_baseline;
  Real _k_Ni2FeBO5_baseline;

  // Series character of the thermal conductance network
  Real _k_series_character;

  // Volume fractions of solid phases
  Real _vf_Ni_baseline;
  Real _vf_NiO_baseline;
  Real _vf_Fe3O4_baseline;
  Real _vf_NiFe2O4_baseline;
  Real _vf_ZrO2_baseline;
  Real _vf_HBO2_baseline;
  Real _vf_Li2B4O7_baseline;
  Real _vf_Ni2FeBO5_baseline;


  // Debugging flags
  Real _debug_materials;
  Real _case;

  /**
   * This is the member reference that will hold the
   * computed values from this material class.
   */
  MaterialProperty<Real> & _surfacetension;
//  MaterialProperty<Real> & _phase;
  MaterialProperty<Real> & _k_cond;
  MaterialProperty<Real> & _pore_size_min;
  MaterialProperty<Real> & _pore_size_avg;
  MaterialProperty<Real> & _pore_size_max;
  MaterialProperty<Real> & _r_inner_cell;
  MaterialProperty<Real> & _r_outer_cell;
  MaterialProperty<Real> & _h_convection_coeff;
  MaterialProperty<Real> & _permeability;
  MaterialProperty<Real> & _k_liquid;
  MaterialProperty<Real> & _k_solid;
  MaterialProperty<Real> & _mu_h2o;
  MaterialProperty<Real> & _rho_h2o;
  MaterialProperty<Real> & _h_fg_h2o;
  MaterialProperty<Real> & _h_vapor;
  MaterialProperty<Real> & _cp_liquid;
  MaterialProperty<Real> & _cp_vapor;
  MaterialProperty<Real> & _q_dot_clad;
  MaterialProperty<Real> & _D_BO3;
  MaterialProperty<Real> & _D_Li;
  MaterialProperty<Real> & _D_H;
  MaterialProperty<Real> & _D_OH;
  MaterialProperty<Real> & _lgKw_H2O;
  MaterialProperty<Real> & _lgKw_H3BO3;
  MaterialProperty<Real> & _lgKw_H3BO3_2;
  MaterialProperty<Real> & _lgKw_LiBO2;
  MaterialProperty<Real> & _t_crud;
  MaterialProperty<Real> & _conductivity;
  MaterialProperty<Real> & _crud_porosity;

  const VariableValue & _tortuosity;
  const VariableValue & _T;
  const VariableValue & _P;
 // VariableValue & _C;
  const VariableValue & _porosity;
  const VariableValue & _phase;
  const VariableValue & _psat;
  const VariableValue & _Tsat;
 // VariableValue & _HBO2;

};

#endif //CRUDMATERIAL_H
