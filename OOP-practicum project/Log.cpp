#include "Log.h"
Log::Log(size_t id, String action) {
	this->id = id;
	this->action = action;
}
Log::Log() {
	id = 0;
	action = "";
}
std::ostream& operator<<(std::ostream& os, const Log& log) {
	os << log.action << "   user id:" << log.id << std::endl;
	return os;
}