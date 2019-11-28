#include "User_Request.h"

namespace SSD_Components
{
	unsigned int User_Request::lastId = 0;
	unsigned int User_Request::objCount = 0;
	User_Request::User_Request() : Sectors_serviced_from_cache(0)
	{
		ID = "" + std::to_string(lastId++);
		ToBeIgnored = false;
		DEBUG_OBJ_ALLOC(typeid(*this).name(), objCount, OBJ_MOD_DEFAULT);
	}
}