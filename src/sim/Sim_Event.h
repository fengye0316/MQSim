#ifndef SIMULATOR_EVENT_H
#define SIMULATOR_EVENT_H

#include "Sim_Defs.h"
#include "Sim_Object.h"

namespace MQSimEngine
{
	class Sim_Object;
	class Sim_Event
	{
	public:
		Sim_Event(sim_time_type fireTime, Sim_Object* targetObject, void* parameters = NULL, int type = 0)
			: Fire_time(fireTime), Target_sim_object(targetObject), Parameters(parameters), Type(type), Next_event(NULL), Ignore(false) 
		{
			DEBUG_OBJ_ALLOC(typeid(*this).name(), objCount, OBJ_MOD_DEFAULT);
		}
		~Sim_Event(){
			DEBUG_OBJ_DELOC(typeid(*this).name(), objCount, OBJ_MOD_DEFAULT);
		}
		sim_time_type Fire_time;
		Sim_Object* Target_sim_object;
		void* Parameters = NULL;
		int Type;
		Sim_Event* Next_event;//Used to store event list in the MQSim's engine
		bool Ignore;//If true, this event will not be executed
		static unsigned int objCount;
	};
}

#endif // !SIMULATOR_EVENT_H
