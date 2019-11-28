#include "NVM_Transaction_Flash_ER.h"


namespace SSD_Components
{
	unsigned int NVM_Transaction_Flash_ER::objCount = 0;
	NVM_Transaction_Flash_ER::NVM_Transaction_Flash_ER(Transaction_Source_Type source, stream_id_type streamID,
		const NVM::FlashMemory::Physical_Page_Address& address) :
		NVM_Transaction_Flash(source, Transaction_Type::ERASE, streamID, 0, NO_LPA, NO_PPA, address, NULL)
	{
		DEBUG_OBJ_ALLOC(typeid(*this).name(), objCount, OBJ_MOD_DEFAULT);
	}

	NVM_Transaction_Flash_ER::~NVM_Transaction_Flash_ER()
	{
		DEBUG_OBJ_DELOC(typeid(*this).name(), objCount, OBJ_MOD_DEFAULT);
	}
}
