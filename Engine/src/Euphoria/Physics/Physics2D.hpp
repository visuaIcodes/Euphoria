#pragma once
#include "box2d/box2d.h"

namespace Euphoria::Physics {
	class Physics2D {
	public:
		static void CreateWorld();
		static void Simulate(float steps);
		static void Shutdown();

		static int SubStepCount;
		static int SimulationIterationsPerFrame;

	private:
		static b2WorldId m_WorldId;
	};
}