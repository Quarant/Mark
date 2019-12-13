// #define debug(deb) (deb == 1)
#define DEBUG_INFO 1
#define DEBUG_WARN 0
#define DEBUG_ERROR 0 
#define DEBUG_CRITICAL 0

#define INFO(MESSAGE) std::cout << "\e[39m[INFO] " << MESSAGE << " \e[39m" << std::endl; 

#define WARN(MESSAGE) std::cout << "\e[96m[WARN] " << MESSAGE << " \e[39m" << std::endl;

#define ERROR(MESSAGE) std::cout << "\e[91m[ERROR] " << MESSAGE << " \e[39m" << std::endl; 

#define CRITICAL(MESSAGE) std::cout << "\e[95m[CRITICAL] " << MESSAGE << " \e[39m" << std::endl; 

// #define debug_info if(DEBUG_INFO==1)

// #define debug_warn if(DEBUG_INFO==1)

// #define debug_warn
// #if (DEBUG_WARN == 1) 
// if(DEBUG_WARN == 1)

// #endif

// #define debug_error 
// #if (DEBUG_ERROR == 1) 
// if(DEBUG_ERROR == 1)

// #endif

// #define debug_critical
// #if (DEBUG_CRITICAL == 1) 
// if(DEBUG_CRITICAL == 1)

// #endif

// #define debug_warn(MESSAGE) 
// #if(DEBUG_WARN == 1) 
// std::cout << "\e[92m" << MESSAGE << "\e[39m" << std::endl; 
// #endif

// #define debug_error(MESSAGE) 
// #if(DEBUG_ERROR == 1) 
// std::cout << "\e[91m" << MESSAGE << "\e[39m" << std::endl; 
// #endif

// #define debug_critical(MESSAGE) 
// #if(DEBUG_CRITICAL == 1) 
// std::cout << "\e[95m" << MESSAGE << "\e[39m" << std::endl; 
// #endif


#if ((DEBUG_INFO == 1) || (DEBUG_WARN == 1) || (DEBUG_ERROR == 1) || (DEBUG_CRITICAL == 1))
#include<iostream> 
#endif


// ERROR_CODES
#define FILE_NOT_EXIST -100