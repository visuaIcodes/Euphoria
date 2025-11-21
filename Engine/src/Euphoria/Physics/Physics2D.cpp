#include "Euphoria/Physics/Physics2D.hpp"

using namespace Euphoria;
using namespace Physics;

b2WorldId Physics2D::m_WorldId;
int Physics2D::SubStepCount = 4;
int Physics2D::SimulationIterationsPerFrame = 90;

void Physics2D::CreateWorld() {
	b2WorldDef worldDef = b2DefaultWorldDef();
	worldDef.gravity = {0.0f, -10.0f};
	worldDef.workerCount = 6;
	worldDef.enableSleep = false;

	m_WorldId = b2CreateWorld(&worldDef);
}

void Physics2D::Simulate(float steps) {
	for (int i = 0; i < SimulationIterationsPerFrame; i++) {
		b2World_Step(m_WorldId, steps, SubStepCount);
	}
}

void Physics2D::Shutdown() {
	b2DestroyWorld(m_WorldId);
	m_WorldId = b2_nullWorldId;
}