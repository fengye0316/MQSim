#include "../sim/Sim_Defs.h"
#include "PCIe_Message.h"
namespace Host_Components
{

	unsigned int PCIe_Message::objCount = 0;

	PCIe_Message::PCIe_Message()
	{
		DEBUG_OBJ_ALLOC(typeid(*this).name(), objCount, OBJ_MOD_DEFAULT);
	}

	PCIe_Message::~PCIe_Message()
	{
		DEBUG_OBJ_DELOC(typeid(*this).name(), objCount, OBJ_MOD_DEFAULT);
	}

}
