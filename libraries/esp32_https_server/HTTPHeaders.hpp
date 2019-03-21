#ifndef SRC_HTTPHEADERS_HPP_
#define SRC_HTTPHEADERS_HPP_

#include <string>
// Arduino declares it's own min max, incompatible with the stl...
#undef min
#undef max
#include <vector>

#include "HTTPSServerConstants.hpp"
#include "HTTPHeader.hpp"

namespace httpsserver {

class HTTPHeaders {
public:
	HTTPHeaders();
	virtual ~HTTPHeaders();

	HTTPHeader * get(std::string name);
	std::string getValue(std::string name);
	void set(HTTPHeader * header);

	std::vector<HTTPHeader *> * getAll();

	void clearAll();

private:
	std::vector<HTTPHeader*> * _headers;
};

} /* namespace httpsserver */

#endif /* SRC_HTTPHEADERS_HPP_ */
