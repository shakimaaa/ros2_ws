/*******************************************************
 * Copyright (C) 2019, Aerial Robotics Group, Hong Kong University of Science and Technology
 * 
 * This file is part of VINS.
 * 
 * Licensed under the GNU General Public License v3.0;
 * you may not use this file except in compliance with the License.
 *******************************************************/

#pragma once

#include <eigen3/Eigen/Dense>
#include <ceres/ceres.h>
#include "../utility/utility.h"

class PoseLocalParameterization : public ceres::Manifold // 2.3.0
{
    // virtual bool Plus(const double *x, const double *delta, double *x_plus_delta) const;
    // virtual bool ComputeJacobian(const double *x, double *jacobian) const;
    // virtual int GlobalSize() const { return 7; };
    // virtual int LocalSize() const { return 6; };
        virtual bool Plus(const double *x, const double *delta, double *x_plus_delta) const override;
    virtual bool ComputeJacobian(const double *x, double *jacobian) const;
    virtual bool Minus(const double *y, const double *x, double *y_minus_x) const override;
    virtual bool PlusJacobian(const double *x, double *jacobian) const override;
    virtual bool MinusJacobian(const double *x, double *jacobian) const override;
    
    virtual int AmbientSize() const override { return 7; } // Global pose (3D position + quaternion)
    virtual int TangentSize() const override { return 6; } // 6D: translation (3) + rotation (3)
};
