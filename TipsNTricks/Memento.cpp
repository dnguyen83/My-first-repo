//#include "Memento.h"
//
//Command *Command::s_commandList[];
//Memento *Command::s_mementoList[];
//int Command::m_numCommands = 0;
//int Command::m_highWater = 0;
//
//void Number::dubble(){
//	m_num = 2 * m_num;
//}
//
//void Number::half() {
//	m_num = m_num / 2;
//}
//
//int Number::getValue(){
//	return m_num;
//}
//
//Memento *Number::createMemento(){
//	return new Memento(m_num);
//}
//
//void Number::reinstateMemento(Memento *memento){
//	m_num = memento->m_state;
//}
//
//void Command::execute() {
//	s_mementoList[m_numCommands] = m_receiver->createMemento();
//	s_commandList[m_numCommands] = this;
//
//	if(m_numCommands > m_highWater) {
//		m_highWater = m_numCommands;
//	}
//	++m_numCommands;
//	(m_receiver->*m_action)();
//}
//
//void Command::undo() {
//	if(m_numCommands == 0) {
//		printf("No more undos\n");
//		return;
//	}
//
//	s_commandList[m_numCommands-1]->m_receiver->reinstateMemento(s_mementoList[m_numCommands-1]);
//	--m_numCommands;
//}
//
//void Command::redo() {
//	if(m_numCommands > m_highWater) {
//		printf("No more redos\n");
//		return;
//	}
//
//	(s_commandList[m_numCommands]->m_receiver->*(s_commandList[m_numCommands]->m_action))();
//	++m_numCommands;
//}