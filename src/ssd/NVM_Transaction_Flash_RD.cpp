#include "NVM_Transaction_Flash_RD.h"
#include "../nvm_chip/NVM_Types.h"

namespace SSD_Components
{
	unsigned int NVM_Transaction_Flash_RD::objCount = 0;
	NVM_Transaction_Flash_RD::NVM_Transaction_Flash_RD(Transaction_Source_Type source, stream_id_type stream_id,
		unsigned int data_size_in_byte, LPA_type lpa, PPA_type ppa, SSD_Components::User_Request* related_user_IO_request,
		NVM::memory_content_type content, NVM_Transaction_Flash_WR* related_write, page_status_type read_sectors_bitmap, data_timestamp_type data_timestamp) :
		NVM_Transaction_Flash(source, Transaction_Type::READ, stream_id, data_size_in_byte, lpa, ppa, related_user_IO_request),
		Content(content), RelatedWrite(related_write), read_sectors_bitmap(read_sectors_bitmap), DataTimeStamp(data_timestamp)
	{
		DEBUG_OBJ_ALLOC(typeid(*this).name(), objCount, OBJ_MOD_DEFAULT);
	}

	NVM_Transaction_Flash_RD::NVM_Transaction_Flash_RD(Transaction_Source_Type source, stream_id_type stream_id,
		unsigned int data_size_in_byte, LPA_type lpa, PPA_type ppa, const NVM::FlashMemory::Physical_Page_Address& address,
		SSD_Components::User_Request* related_user_IO_request,
		NVM::memory_content_type content, NVM_Transaction_Flash_WR* related_write, page_status_type read_sectors_bitmap, data_timestamp_type data_timestamp) :
		NVM_Transaction_Flash(source, Transaction_Type::READ, stream_id, data_size_in_byte, lpa, ppa, address, related_user_IO_request),
		Content(content), RelatedWrite(related_write), read_sectors_bitmap(read_sectors_bitmap), DataTimeStamp(data_timestamp)
	{
		DEBUG_OBJ_ALLOC(typeid(*this).name(), objCount, OBJ_MOD_DEFAULT);

	}

	NVM_Transaction_Flash_RD::NVM_Transaction_Flash_RD(Transaction_Source_Type source, stream_id_type stream_id,
		unsigned int data_size_in_byte, LPA_type lpa, PPA_type ppa, SSD_Components::User_Request* related_user_IO_request,
		NVM::memory_content_type content, page_status_type read_sectors_bitmap, data_timestamp_type data_timestamp) :
		NVM_Transaction_Flash(source, Transaction_Type::READ, stream_id, data_size_in_byte, lpa, ppa, related_user_IO_request),
		Content(content), RelatedWrite(NULL), read_sectors_bitmap(read_sectors_bitmap), DataTimeStamp(data_timestamp)
	{
		DEBUG_OBJ_ALLOC(typeid(*this).name(), objCount, OBJ_MOD_DEFAULT);
	}
		
	NVM_Transaction_Flash_RD::~NVM_Transaction_Flash_RD()
	{
		DEBUG_OBJ_DELOC(typeid(*this).name(), objCount, OBJ_MOD_DEFAULT);
	}
}
