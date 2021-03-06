/*
  FLUIDS v.1 - SPH Fluid Simulator for CPU and GPU
  Copyright (C) 2008. Rama Hoetzlein, http://www.rchoetzlein.com

  ZLib license
  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.
*/

#ifndef DEF_FLUID
	#define DEF_FLUID
	
	#include "vector.h"

	#include "common_defs.h"

	struct Fluid {
	public:
		Vector3DF		pos;			// Basic particle (must match Particle class)
		DWORD			clr;
		int				next;
		Vector3DF		vel;			
		Vector3DF		vel_eval;		
		unsigned short	age;

		float			pressure;		// Smoothed Particle Hydrodynamics
		float			density;	
		Vector3DF		sph_force;

		int				state; //0 is ice, 1 is water
		float			temperature; //Range from 0 to 250 (32 is melting point)
		int				numNeighbors; //0-6, used for air temp advection
		float			newTemp; //Temp to be added to the particle temperature
		Vector3DI       index; //stores the location of the particle in a voxel grid for easy access

	};

#endif /*PARTICLE_H_*/
