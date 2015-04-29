#include "Command.h"

void Command::execute()
{
	(m_object->*m_method)(); // invoke the method on the object
}