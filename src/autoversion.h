#ifndef AUTOVERSION_H
#define AUTOVERSION_H

namespace AutoVersion{
	
	//Date Version Types
	static const char DATE[] = "06";
	static const char MONTH[] = "12";
	static const char YEAR[] = "2008";
	static const double UBUNTU_VERSION_STYLE = 8.12;
	
	//Software Status
	static const char STATUS[] = "Alpha";
	static const char STATUS_SHORT[] = "a";
	
	//Standard Version Type
	static const long MAJOR = 0;
	static const long MINOR = 8;
	static const long BUILD = 812;
	static const long REVISION = 4615;
	
	//Miscellaneous Version Types
	static const long BUILDS_COUNT = 1341;
	#define RC_FILEVERSION 0,8,812,4615
	#define RC_FILEVERSION_STRING "0, 8, 812, 4615\0"
	static const char FULLVERSION_STRING[] = "0.8.812.4615";
	
	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY = 12;
	

}
#endif //AUTOVERSION_H
